#ifndef BROWSER_H
#define BROWSER_H

#include "adt.h"

void init_tab_system(TabSystem *sys);
void checktab(TabSystem *sys);
void newtab(TabSystem *sys);
void closetab(TabSystem *sys);
void nexttab(TabSystem *sys, int steps);
void prevtab(TabSystem *sys, int steps);

void print_linked_pages(WebGraph *graph, WebDb *base, char *current_url);
void openlinked(
    TabSystem *sys,
    WebGraph *graph,
    WebDb *base,
    CacheMap *cache,
    int index
);

#endif
