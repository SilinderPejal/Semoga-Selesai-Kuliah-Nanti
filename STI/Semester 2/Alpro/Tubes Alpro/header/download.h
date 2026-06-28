#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include "adt.h"
#include "boolean.h"

typedef struct {
    char url[MAX_URL];
    int remainingTicks;
} DownloadItem;

typedef struct {
    DownloadItem buffer[DOWNLOAD_MAX_AMOUNT];
    int head;
    int tail;
    int size;
} DownloadQueue;

void createQueue(DownloadQueue *q);

boolean isEmpty(DownloadQueue q);

boolean isFull(DownloadQueue q);

void download(DownloadQueue *q, char *url);

void tick(DownloadQueue *q);

#endif
