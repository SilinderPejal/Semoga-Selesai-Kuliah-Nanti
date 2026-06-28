#ifndef BACKFORWARD_H
#define BACKFORWARD_H

#include "adt.h"

typedef struct HistoryNode* HistAddress;
typedef struct HistoryNode {
    char url[MAX_URL];
    HistAddress prev;
    HistAddress next;
} HistoryNode;

typedef struct {
    char name;
    HistAddress head;
    HistAddress currentAddress; 
} Tab;

#define PREV(p) (p)->prev
#define INFO(p) (p)->url
#define NEXT(p) (p)->next

HistAddress createHistoryNode(char *url);

void freeForwardHistory(HistAddress startNode);

void openNewPage(Tab *t, char *url);

void back(Tab *t);

void forward(Tab *t);

#endif