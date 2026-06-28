#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/page_management.h"
#include "../header/cache.h"

/* E01 - Validasi URL manual */
int isValidURL(const char *url) {
    if (url == NULL || url[0] == '\0') return 0;
    int len = strlen(url), i = 0, dotFound = 0;
    while (i < len) {
        int labelLen = 0;
        while (i < len && url[i] != '.') {
            char c = url[i];
            if (!((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='-')) return 0;
            labelLen++; i++;
        }
        if (labelLen == 0 || labelLen > 63) return 0;
        if (url[i-1] == '-') return 0;
        if (i < len && url[i] == '.') { dotFound = 1; i++; if (i >= len) return 0; }
    }
    if (!dotFound) return 0;
    int lastDot = -1;
    for (int j = 0; j < len; j++) if (url[j] == '.') lastDot = j;
    int tldLen = len - lastDot - 1;
    if (tldLen < 2) return 0;
    for (int j = lastDot+1; j < len; j++) {
        char c = url[j];
        if (!((c>='A'&&c<='Z')||(c>='a'&&c<='z'))) return 0;
    }
    return 1;
}

int getMaxID(WebDb *web) {
    int maxId = 0;
    for (int i = 0; i < web->count; i++)
        if (web->elements[i].id > maxId) maxId = web->elements[i].id;
    return maxId;
}

int findGraphNode(WebGraph *graph, int sourceId) {
    for (int i = 0; i < graph->node_count; i++)
        if (graph->nodes[i].source_id == sourceId) return i;
    return -1;
}

void removeFromCache(CacheMap *cache, const char *url) {
    int idx = findCache(cache, (char *)url);
    if (idx == -1) return;
    for (int i = idx; i < cache->count - 1; i++) {
        strncpy(cache->keyUrl[i],       cache->keyUrl[i+1],       MAX_URL     - 1);
        strncpy(cache->valueContent[i], cache->valueContent[i+1], MAX_CONTENT - 1);
    }
    cache->count--;
    cache->keyUrl[cache->count][0]      = '\0';
    cache->valueContent[cache->count][0] = '\0';
}

int readMultilineContent(char *buffer, int maxLen) {
    char line[1024];
    int totalLen = 0;
    buffer[0] = '\0';
    while (1) {
        printf(">>> ");
        if (!fgets(line, sizeof(line), stdin)) break;
        int lineLen = strlen(line);
        if (lineLen > 0 && line[lineLen-1] == '\n') line[--lineLen] = '\0';
        if (strcmp(line, ".") == 0) break; // ⁶🤷⁷
        if (totalLen > 0 && totalLen+1 < maxLen) { strcat(buffer, "\n"); totalLen++; }
        if (totalLen + lineLen < maxLen) { strcat(buffer, line); totalLen += lineLen; }
    }
    return totalLen;
}

int readLinkedPages(WebDb *web, char urlList[][MAX_URL], int maxLinks) {
    char input[MAX_URL];
    int count = 0;
    while (count < maxLinks) {
        printf(">>> ");
        if (!fgets(input, sizeof(input), stdin)) break;
        int len = strlen(input);
        if (len > 0 && input[len-1] == '\n') input[--len] = '\0';
        if (strcmp(input, "DONE") == 0) break;
        if (!isValidURL(input)) { printf("Format URL tidak valid!\n"); continue; }
        if (findWebPage(web, input) == -1) { printf("URL tidak ditemukan!\n"); continue; }
        strncpy(urlList[count], input, MAX_URL - 1);
        count++;
    }
    return count;
}

/* F05 - add_page */
void addPage(WebDb *web, CacheMap *cache, WebGraph *graph, const char *url) {
    if (!isValidURL(url)) { printf("Format URL tidak valid!\n"); return; }

    if (findWebPage(web, (char *)url) != -1) {
        printf("Sudah terdapat halaman dengan url %s. Gunakan url lain yang belum terdaftar!\n", url);
        return;
    }
    if (web->count >= MAX_WEB_PAGES) { printf("Database penuh!\n"); return; }

    char content[MAX_CONTENT];
    printf("Masukkan konten (Akhiri dengan titik '.' di baris baru):\n");
    readMultilineContent(content, MAX_CONTENT);

    char linkedPages[MAX_LINKS][MAX_URL];
    printf("Masukkan linked pages (Ketik 'DONE' jika sudah selesai):\n");
    int linkCount = readLinkedPages(web, linkedPages, MAX_LINKS);

    int newId = getMaxID(web) + 1;
    WebPage newPage;
    newPage.id = newId;
    strncpy(newPage.url,     url,     MAX_URL     - 1);
    strncpy(newPage.content, content, MAX_CONTENT - 1);
    newPage.url    [MAX_URL     - 1] = '\0';
    newPage.content[MAX_CONTENT - 1] = '\0';
    web->elements[web->count++] = newPage;

    if (graph->node_count < MAX_WEB_PAGES) {
        int nodeIdx = graph->node_count;
        graph->nodes[nodeIdx].source_id  = newId;
        graph->nodes[nodeIdx].link_count = 0;
        for (int i = 0; i < linkCount; i++) {
            int targetIdx = findWebPage(web, linkedPages[i]);
            if (targetIdx != -1 && graph->nodes[nodeIdx].link_count < MAX_LINKS) {
                graph->nodes[nodeIdx].target_ids[graph->nodes[nodeIdx].link_count++]
                    = web->elements[targetIdx].id;
            }
        }
        graph->node_count++;
    }

    printf("Halaman %s berhasil ditambahkan!\n", url);
}

/* F05 - edit_page */
void editPage(WebDb *web, CacheMap *cache, WebGraph *graph, const char *url) {
    if (!isValidURL(url)) { printf("Format URL tidak valid!\n"); return; }

    int idx = findWebPage(web, (char *)url);
    if (idx == -1) { printf("Tidak ada halaman dengan url %s!\n", url); return; }

    int cacheIdx = findCache(cache, (char *)url);
    printf(cacheIdx != -1
        ? "[Status: Cache-Hit] Mengambil data dari cache...\n"
        : "[Status: Cache-Miss] Mengambil data dari database...\n");

    printf("Konten saat ini:\n%s\n", web->elements[idx].content);


    int nodeIdx = findGraphNode(graph, web->elements[idx].id);
    if (nodeIdx != -1 && graph->nodes[nodeIdx].link_count > 0) {
        printf("Linked pages:\n");
        for (int i = 0; i < graph->nodes[nodeIdx].link_count; i++) {
            int targetId = graph->nodes[nodeIdx].target_ids[i];
            for (int j = 0; j < web->count; j++) {
                if (web->elements[j].id == targetId) {
                    printf("[%d] %s\n", i+1, web->elements[j].url);
                    break;
                }
            }
        }
    }

    char newContent[MAX_CONTENT];
    printf("Masukkan konten baru (akhiri dengan '.' atau ketik '.' saja jika tidak ingin mengubah):\n");
    printf(">>> ");
    char firstLine[1024];
    fgets(firstLine, sizeof(firstLine), stdin);
    int firstLen = strlen(firstLine);
    if (firstLen > 0 && firstLine[firstLen-1] == '\n') firstLine[--firstLen] = '\0';

    int skipContent = (strcmp(firstLine, ".") == 0);
    if (!skipContent) {
        strncpy(newContent, firstLine, MAX_CONTENT - 1);
        newContent[MAX_CONTENT-1] = '\0';
        char rest[MAX_CONTENT]; rest[0] = '\0';
        readMultilineContent(rest, MAX_CONTENT - strlen(newContent) - 2);
        if (strlen(rest) > 0) {
            strncat(newContent, "\n",  MAX_CONTENT - strlen(newContent) - 1);
            strncat(newContent, rest,  MAX_CONTENT - strlen(newContent) - 1);
        }
    }


    char newLinkedPages[MAX_LINKS][MAX_URL];
    int  newLinkCount = 0;
    printf("Masukkan linked pages baru (DONE jika selesai, SKIP jika tidak ingin mengubah):\n");
    printf(">>> ");
    char skipCheck[16];
    fgets(skipCheck, sizeof(skipCheck), stdin);
    int skipLinks = (strncmp(skipCheck, "SKIP", 4) == 0);
    if (!skipLinks) newLinkCount = readLinkedPages(web, newLinkedPages, MAX_LINKS);


    if (!skipContent) {
        strncpy(web->elements[idx].content, newContent, MAX_CONTENT - 1);
        web->elements[idx].content[MAX_CONTENT-1] = '\0';
    }


    if (!skipLinks && nodeIdx != -1) {
        graph->nodes[nodeIdx].link_count = 0;
        for (int i = 0; i < newLinkCount; i++) {
            int targetIdx = findWebPage(web, newLinkedPages[i]);
            if (targetIdx != -1 && graph->nodes[nodeIdx].link_count < MAX_LINKS) {
                graph->nodes[nodeIdx].target_ids[graph->nodes[nodeIdx].link_count++]
                    = web->elements[targetIdx].id;
            }
        }
    }


    removeFromCache(cache, url);

    printf("Halaman %s berhasil diperbarui!\n", url);
}

/* F05 - delete_page */
void deletePage(WebDb *web, CacheMap *cache, WebGraph *graph, const char *url) {
    if (!isValidURL(url)) { printf("Format URL tidak valid!\n"); return; }

    int idx = findWebPage(web, (char *)url);
    if (idx == -1) { printf("Tidak ada halaman dengan url %s!\n", url); return; }

    int cacheIdx = findCache(cache, (char *)url);
    if (cacheIdx != -1) {
        removeFromCache(cache, url);
        printf("[Status: Cache-Hit] URL ditemukan di cache dan telah dibersihkan.\n");
    }

    int deletedId = web->elements[idx].id;
    printf("Membersihkan relasi linked pages...\n");

    int nodeIdx = findGraphNode(graph, deletedId);
    if (nodeIdx != -1) {
        for (int i = nodeIdx; i < graph->node_count - 1; i++)
            graph->nodes[i] = graph->nodes[i+1];
        graph->node_count--;
    }

    for (int i = 0; i < graph->node_count; i++) {
        for (int j = 0; j < graph->nodes[i].link_count; j++) {
            if (graph->nodes[i].target_ids[j] == deletedId) {
                for (int k = j; k < graph->nodes[i].link_count - 1; k++)
                    graph->nodes[i].target_ids[k] = graph->nodes[i].target_ids[k+1];
                graph->nodes[i].link_count--;
                j--;
            }
        }
    }

    /* Hapus dari WebBase */
    for (int i = idx; i < web->count - 1; i++)
        web->elements[i] = web->elements[i+1];
    web->count--;

    printf("Halaman %s berhasil dihapus!\n", url);
}
