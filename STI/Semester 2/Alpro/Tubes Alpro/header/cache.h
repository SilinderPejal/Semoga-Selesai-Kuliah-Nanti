#ifndef CACHE_H
#define CACHE_H
#include "adt.h"

int findCache(CacheMap *cache, char url[]);

void putCache(CacheMap *cache, char url[], char content[]);

void deleteCache(CacheMap *cache, char url[]);

#endif