#include <stdio.h>
#include <string.h>
#include "../header/browser.h"
#include "../header/openpage.h"

int global_tab_counter = 1;

void init_tab_system(TabSystem *sys) {
    sys->count = 1;
    sys->active_idx = 0;
    sprintf(sys->tabs[0].tab_name, "TAB1");
    sys->tabs[0].is_page_open = 0;
    global_tab_counter = 2;
}

void checktab(TabSystem *sys) {
    printf("List of tab(s):\n");
    for (int i = 0; i < sys->count; i++) {
        printf("[%d] %s\n", i + 1, sys->tabs[i].tab_name);
    }
    printf("Current tab: %s\n", sys->tabs[sys->active_idx].tab_name);
}

void newtab(TabSystem *sys) {
    if (sys->count >= TABS_MAX_AMOUNT) {
        printf("ERROR: Jumlah tab tidak bisa melebihi batas maksimum!\n");
        return;
    }
    sprintf(sys->tabs[sys->count].tab_name, "TAB%d", global_tab_counter);
    sys->tabs[sys->count].is_page_open = 0;
    
    printf("Tab baru (%s) berhasil dibuat!\n", sys->tabs[sys->count].tab_name);
    sys->count++;
    global_tab_counter++;
}

void closetab(TabSystem *sys) {
    if (sys->count <= 1) {
        printf("ERROR: Tidak bisa menutup tab, tab minimal berjumlah 1!\n");
        return;
    }
    printf("%s berhasil ditutup.\n", sys->tabs[sys->active_idx].tab_name);
    
    for (int i = sys->active_idx; i < sys->count - 1; i++) {
        sys->tabs[i] = sys->tabs[i + 1];
    }
    sys->count--;
    
    if (sys->active_idx >= sys->count) {
        sys->active_idx = sys->count - 1;
    }
}

void nexttab(TabSystem *sys, int steps) {
    if (steps <= 0 || sys->active_idx + steps >= sys->count) {
        printf("ERROR: Posisi tab tidak valid!\n");
        return;
    }
    sys->active_idx += steps;
    printf("Tab saat ini berhasil diganti ke %s.\n", sys->tabs[sys->active_idx].tab_name);
}

void prevtab(TabSystem *sys, int steps) {
    if (steps <= 0 || sys->active_idx - steps < 0) {
        printf("ERROR: Posisi tab tidak valid!\n");
        return;
    }
    sys->active_idx -= steps; // ⁶🤷⁷
    printf("Tab saat ini berhasil diganti ke %s.\n", sys->tabs[sys->active_idx].tab_name);
}

void print_linked_pages(WebGraph *graph, WebDb *base, char *current_url) {
    int source_id = -1;
    for (int i = 0; i < base->count; i++) {
        if (strcmp(base->elements[i].url, current_url) == 0) {
            source_id = base->elements[i].id;
            break;
        }
    }
    
    if (source_id == -1) {
        printf("ERROR: HALAMAN TIDAK MEMILIKI TAUTAN YANG BISA DIBUKA!\n");
        return;
    }
    
    int graph_idx = -1;
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].source_id == source_id) {
            graph_idx = i;
            break;
        }
    }
    
    if (graph_idx == -1 || graph->nodes[graph_idx].link_count == 0) {
        printf("ERROR: HALAMAN TIDAK MEMILIKI TAUTAN YANG BISA DIBUKA!\n");
        return;
    }
    
    printf("Linked pages:\n");
    for (int i = 0; i < graph->nodes[graph_idx].link_count; i++) {
        int target_id = graph->nodes[graph_idx].target_ids[i];
        for (int j = 0; j < base->count; j++) {
            if (base->elements[j].id == target_id) {
                printf("[%d] %s\n", i + 1, base->elements[j].url);
                break;
            }
        }
    }
}

void openlinked(TabSystem *sys, WebGraph *graph, WebDb *base, CacheMap *cache, int index){
    BrowserTab *active = &sys->tabs[sys->active_idx];
    if (!active->is_page_open) {
        printf("ERROR: COMMAND HANYA DAPAT DIGUNAKAN SAAT HALAMAN WEB TERBUKA!\n");
        return;
    }
    
    int source_id = active->current_page.id;
    int graph_idx = -1;
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].source_id == source_id) {
            graph_idx = i;
            break;
        }
    }
    
    if (graph_idx == -1 || index <= 0 || index > graph->nodes[graph_idx].link_count) {
        printf("ERROR: Posisi tab tidak valid!\n");
        return;
    }
    
    int target_id = graph->nodes[graph_idx].target_ids[index - 1];
    char target_url[MAX_URL] = "";
    for (int i = 0; i < base->count; i++) {
        if (base->elements[i].id == target_id) {
            strcpy(target_url, base->elements[i].url);
            break;
        }
    }
    
    if (strlen(target_url) > 0) {
        openPage(base, cache, target_url);;
    }
}
