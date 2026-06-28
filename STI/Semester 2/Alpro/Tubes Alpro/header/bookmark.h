#ifndef BOOKMARK_H
#define BOOKMARK_H

#include "adt.h"
#include "cache.h"
#include "openpage.h"

void initBookmarkList(
    BookmarkList *list
);

void addBookmark(
    BookmarkList *list,
    WebDb *web,
    char alias[],
    char url[]
);

void viewBookmark(
    BookmarkList list
);

void deleteBookmark(
    BookmarkList *list,
    char alias[]
);

void openBookmark(
    BookmarkList *list,
    WebDb *web,
    CacheMap *cache,
    char alias[]
);

#endif
