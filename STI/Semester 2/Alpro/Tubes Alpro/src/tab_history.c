#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/tab_history.h"


Tab tabHistories[TABS_MAX_AMOUNT];

void initAllTabHistories(void) {
    for (int i = 0; i < TABS_MAX_AMOUNT; i++) {
        tabHistories[i].head           = NULL;
        tabHistories[i].currentAddress = NULL;
    }
}

int isValidNumericX(const char *input, int *outValue) {
    if (!input || input[0] == '\0') return 0;
    int len = strlen(input);
    if (len > 6) return 0;
    for (int i = 0; i < len; i++)
        if (input[i] < '0' || input[i] > '9') return 0;
    int value = atoi(input);
    if (value <= 0 || value > 999999) return 0;
    if (outValue) *outValue = value;
    return 1;
}

int countBackSteps(Tab *t) {
    if (t->currentAddress == NULL) return 0;
    int count = 0;
    HistAddress p = t->currentAddress;
    while (PREV(p) != NULL) { count++; p = PREV(p); }
    return count;
}


int countForwardSteps(Tab *t) {
    if (t->currentAddress == NULL) return 0;
    int count = 0;
    HistAddress p = t->currentAddress;
    while (NEXT(p) != NULL) { count++; p = NEXT(p); }
    return count;
}


void viewTabHistory(TabSystem *sys, WebDb *base, CacheMap *cache) {
    int idx = sys->active_idx;
    Tab *t  = &tabHistories[idx];

    if (t->head == NULL) {
        printf("Riwayat kosong, belum ada halaman yang pernah dibuka.\n");
        return;
    }

    HistAddress p = t->head;
    int i = 0;
    while (p != NULL) {
        if (p == t->currentAddress)
            printf("[%d] %s  <- YOU ARE HERE\n", i, p->url);
        else
            printf("[%d] %s\n", i, p->url);
        i++;
        p = NEXT(p);
    }

    printf("\n");
    if (t->currentAddress != NULL) // ⁶🤷⁷
        openPage(base, cache, t->currentAddress->url);
}

void backX(int x, TabSystem *sys, WebDb *base, CacheMap *cache) {
    int idx = sys->active_idx;
    Tab *t  = &tabHistories[idx];

    if (t->currentAddress == NULL) {
        printf("ERROR: BACK TIDAK BISA DIJALANKAN KARENA TIDAK ADA HALAMAN SEBELUMNYA!\n");
        return;
    }

    int available = countBackSteps(t);
    if (available < x) {
        printf("ERROR: Tidak bisa back %d langkah, hanya ada %d halaman sebelumnya!\n",
               x, available);
        openPage(base, cache, t->currentAddress->url);
        return;
    }

    for (int i = 0; i < x; i++)
        back(t);

    printf("BACK: KEMBALI KE HALAMAN %s\n", t->currentAddress->url);
    openPage(base, cache, t->currentAddress->url);
}

void forwardX(int x, TabSystem *sys, WebDb *base, CacheMap *cache) {
    int idx = sys->active_idx;
    Tab *t  = &tabHistories[idx];

    if (t->currentAddress == NULL) {
        printf("ERROR: FORWARD TIDAK BISA DIJALANKAN KARENA TIDAK ADA HALAMAN SELANJUTNYA!\n");
        return;
    }

    int available = countForwardSteps(t);
    if (available < x) {
        printf("ERROR: Tidak bisa forward %d langkah, hanya ada %d halaman ke depan!\n",
               x, available);
        openPage(base, cache, t->currentAddress->url);
        return;
    }

    for (int i = 0; i < x; i++)
        forward(t);

    printf("FORWARD: KEMBALI KE HALAMAN %s\n", t->currentAddress->url);
    openPage(base, cache, t->currentAddress->url);
}
