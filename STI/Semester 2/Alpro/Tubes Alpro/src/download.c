#include <stdio.h>
#include <string.h>

#include "../header/download.h"
#include "../header/page_management.h"

void createQueue(DownloadQueue *q) {
    q->head = 0;
    q->tail = -1;
    q->size = 0;
}

boolean isEmpty(DownloadQueue q) {
    return (q.size == 0);
}

boolean isFull(DownloadQueue q) {
    return (q.size == DOWNLOAD_MAX_AMOUNT);
}

void download(DownloadQueue *q, char *url) {
        if (!isValidURL(url)) {

        printf("Format URL tidak valid!\n");
        return;
    }
    
    if (isFull(*q)) {
        printf("Download tidak diterima, antrian sudah penuh.\n");
        return;
    }
    
    int urlLength = strlen(url);
    int ticks = (urlLength / 5) + 2;
    
    q->tail = (q->tail + 1) % DOWNLOAD_MAX_AMOUNT;
    
    strcpy(q->buffer[q->tail].url, url);
    q->buffer[q->tail].remainingTicks = ticks;
    q->size++;
    
    if (q->size == 1) {
        printf("Sedang mendownload %s (%d ticks tersisa)\n", url, ticks);
    } else {
        printf("Sedang mendownload %s (%d ticks tersisa) -> antrian no %d\n", url, ticks, q->size);
    }
}

void tick(DownloadQueue *q) {
    if (isEmpty(*q)) {
        printf("Antrian download saat ini kosong.\n");
        return;
    }
    
    DownloadItem *current = &(q->buffer[q->head]);
    current->remainingTicks--;

    if (current->remainingTicks > 0) {
        printf("Sedang mendownload %s... (%d ticks tersisa)\n", current->url, current->remainingTicks);
    } else {
        printf("%s selesai terdownload!\n", current->url);
        
        q->head = (q->head + 1) % DOWNLOAD_MAX_AMOUNT;
        q->size--;
        
        if (!isEmpty(*q)) {
            DownloadItem *next = &(q->buffer[q->head]); // ⁶🤷⁷
            printf("Sedang mendownload %s... (%d ticks tersisa)\n", next->url, next->remainingTicks);
        }
    }
}
