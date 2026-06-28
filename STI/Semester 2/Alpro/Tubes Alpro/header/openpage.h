#ifndef OPENPAGE_H
#define OPENPAGE_H
#include "adt.h"

void loadWebDb(WebDb *web); 

int findWebPage(WebDb *web, char url[]);

void openPage(WebDb *web, CacheMap *cache, char url[]);

#endif