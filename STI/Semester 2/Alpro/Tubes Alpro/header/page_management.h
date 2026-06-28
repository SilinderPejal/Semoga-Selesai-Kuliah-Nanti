#ifndef PAGE_MANAGEMENT_H
#define PAGE_MANAGEMENT_H

#include "adt.h"
#include "openpage.h"

int  isValidURL          (const char *url);
int  readMultilineContent(char *buffer, int maxLen);
int  readLinkedPages     (WebDb *web, char urlList[][MAX_URL], int maxLinks);
int  getMaxID            (WebDb *web);
int  findGraphNode       (WebGraph *graph, int sourceId);
void removeFromCache     (CacheMap *cache, const char *url);

void addPage   (WebDb *web, CacheMap *cache, WebGraph *graph, const char *url);
void editPage  (WebDb *web, CacheMap *cache, WebGraph *graph, const char *url);
void deletePage(WebDb *web, CacheMap *cache, WebGraph *graph, const char *url);

#endif
