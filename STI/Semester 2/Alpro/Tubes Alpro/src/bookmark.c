#include <stdio.h>
#include <string.h>

#include "../header/bookmark.h"

BookmarkList bookmarks;

// INIT
void initBookmarkList(BookmarkList *list) {
    list->count = 0;
}

// ADD BOOKMARK
void addBookmark(BookmarkList *list, WebDb *web, char alias[], char url[]) {

    // CEK ALIAS DUPLIKAT
    for (int i = 0; i < list->count; i++){
        if (strcmp(list->data[i].alias,alias) == 0) {
            printf("Alias sudah digunakan!\n");
            return;
        }
    }

    // CEK URL ADA
    int found = 0;

    for ( int i = 0; i < web->count; i++) {
        if (strcmp(web->elements[i].url, url) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("URL tidak ditemukan!\n");
        return;
    }

    // TAMBAH BOOKMARK
    strcpy(list->data[list->count].alias, alias);
    strcpy(list->data[list->count].url, url);
    list->count++;
    printf("Bookmark berhasil ditambahkan!\n");
}

// VIEW BOOKMARK
void viewBookmark(BookmarkList list) {
    if (list.count == 0) {
        printf("Belum ada bookmark.\n");
        return;
    }

    printf("Daftar Bookmark:\n");

    for (int i = 0; i < list.count; i++) {
        printf("%d. %s -> %s\n", i + 1, list.data[i].alias, list.data[i].url);
    }
}

// DELETE BOOKMARK
void deleteBookmark(BookmarkList *list, char alias[]) {
    int idx = -1;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->data[i].alias, alias) == 0) {
            idx = i;
            break;
        }
    }
 // ⁶🤷⁷
    if (idx == -1) {
        printf("Bookmark tidak ditemukan!\n");
        return;
    }

    for (int i = idx; i < list->count - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->count--;

    printf("Bookmark berhasil dihapus!\n");
}

// OPEN BOOKMARK
void openBookmark(BookmarkList *list, WebDb *web, CacheMap *cache, char alias[]) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->data[i].alias, alias) == 0) {
            openPage(web, cache, list->data[i].url);
            return;
        }
    }

    printf("Bookmark tidak ditemukan!\n");
}
