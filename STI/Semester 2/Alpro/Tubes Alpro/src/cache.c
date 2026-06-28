#include <stdio.h>
#include <string.h>

#include "../header/cache.h"

int findCache(CacheMap *cache, char url[]) {

    for (int i = 0; i < cache->count; i++) {

        if (strcmp(cache->keyUrl[i], url) == 0) {
            return i;
        }
    }

    return -1;
}

void putCache(CacheMap *cache, char url[], char content[]) {

    // CACHE BELUM PENUH
    if (cache->count < MAX_CACHE) {

        strcpy(cache->keyUrl[cache->count], url);
        strcpy(cache->valueContent[cache->count], content);

        cache->count++;
    }

    // CACHE PENUH -> FIFO
    else {

        strcpy(cache->keyUrl[cache->firstInIndex], url);
        strcpy(cache->valueContent[cache->firstInIndex], content);

        cache->firstInIndex++;

        // BALIK KE AWAL ARRAY
        if (cache->firstInIndex >= MAX_CACHE) {
            cache->firstInIndex = 0;
        }
    }
}

void deleteCache(CacheMap *cache, char url[]) {

    int index = findCache(cache, url);

    // URL TIDAK ADA
    if (index == -1) {
        return;
    }

    // SHIFT KIRI
    for (int i = index; i < cache->count - 1; i++) {

        strcpy(cache->keyUrl[i], cache->keyUrl[i + 1]);

        strcpy(
            cache->valueContent[i],
            cache->valueContent[i + 1]
        );
    }

    cache->count--;

    // RESET POINTER FIFO KALAU PERLU
    if (cache->firstInIndex >= cache->count) { // ⁶🤷⁷
        cache->firstInIndex = 0;
    }
}