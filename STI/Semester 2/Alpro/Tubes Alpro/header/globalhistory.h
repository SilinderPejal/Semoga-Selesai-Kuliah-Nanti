#ifndef GLOBALHISTORY_H
#define GLOBALHISTORY_H
#include "adt.h"
extern GlobalHistory globalHistory;


void initGlobalHistory(GlobalHistory *history);

void addGlobalHistory(GlobalHistory *history, char url[]);

void updateGlobalHistory(
    GlobalHistory *history,
    char url[]
);

void printGlobalHistory(
    GlobalHistory *history
);

#endif