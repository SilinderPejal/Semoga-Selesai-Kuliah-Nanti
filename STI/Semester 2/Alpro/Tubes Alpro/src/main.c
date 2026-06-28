#include <stdio.h>

#include "../header/adt.h"
#include "../header/cache.h"
#include "../header/browser.h"
#include "../header/tab_history.h"
#include "../header/globalhistory.h"
#include "../header/command.h"
#include "../header/download.h"

// GLOBAL VARIABLES

WebDb web;
CacheMap cache;
TabSystem tabSystem;
WebGraph graph;
DownloadQueue downloadQueue;

// DEFAULT GRAPH

void loadDefaultGraph(WebGraph *graph) {

    graph->node_count = 2;

    graph->nodes[0].source_id = 1;
    graph->nodes[0].target_ids[0] = 2;
    graph->nodes[0].link_count = 1;

    graph->nodes[1].source_id = 2;
    graph->nodes[1].target_ids[0] = 1;
    graph->nodes[1].link_count = 1;
}

// MAIN

int main() {

    char line[256];

    // INIT CACHE
    cache.count = 0;
    cache.firstInIndex = 0;

    // INIT WEB
    loadWebDb(&web);

    // INIT GRAPH
    loadDefaultGraph(&graph);

    // INIT TAB
    init_tab_system(&tabSystem);

    // INIT HISTORY
    initAllTabHistories();
    initGlobalHistory(&globalHistory);

    // INIT DOWNLOAD QUEUE
    createQueue(&downloadQueue);

    // BANNER
    printf("=====================================\n");
    printf("       WELCOME TO SLOPSLOPGO\n");
    printf("=====================================\n");

    // REPL
    while (1) { // ⁶🤷⁷

        printf("\n>>> ");

        fgets(
            line,
            sizeof(line),
            stdin
        );

        stripNewline(line);

        eval(line);
    }

    return 0;
}