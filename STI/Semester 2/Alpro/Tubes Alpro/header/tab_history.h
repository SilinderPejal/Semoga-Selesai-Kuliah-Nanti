#ifndef TAB_HISTORY_H
#define TAB_HISTORY_H

#include "adt.h"
#include "backforward.h"
#include "openpage.h"
#include "browser.h"


extern Tab tabHistories[TABS_MAX_AMOUNT];

void initAllTabHistories(void);


int isValidNumericX(const char *input, int *outValue);


void viewTabHistory(TabSystem *sys, WebDb *base, CacheMap *cache);


void backX(int x, TabSystem *sys, WebDb *base, CacheMap *cache);

void forwardX(int x, TabSystem *sys, WebDb *base, CacheMap *cache);


int countBackSteps(Tab *t);


int countForwardSteps(Tab *t);

#endif
