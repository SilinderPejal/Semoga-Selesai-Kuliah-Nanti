#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/backforward.h"

HistAddress createHistoryNode(char *url) {
    HistAddress p = (HistAddress)malloc(sizeof(HistoryNode));
    if (p != NULL) {
        strcpy(p->url, url);
        PREV(p) = NULL;
        NEXT(p) = NULL;
    }
    return p;
}

void freeForwardHistory(HistAddress startNode) {
    HistAddress p = startNode;
    while (p != NULL) {
        HistAddress nextNode = NEXT(p);
        free(p);
        p = nextNode;
    }
}

void openNewPage(Tab *t, char *url) {
    HistAddress p = createHistoryNode(url);
    if (p == NULL) return;

    if (t->head == NULL) {
        t->head = p;
        t->currentAddress = p;
    } else {
        if (t->currentAddress->next != NULL) {
            freeForwardHistory(t->currentAddress->next);
        }
        
        t->currentAddress->next = p;
        PREV(p) = t->currentAddress;
        
        t->currentAddress = p;
    }
    printf("OPEN: Berhasil membuka %s\n", url);
    printf("[Konten] Menampilkan halaman: %s\n", t->currentAddress->url);
}

void back(Tab *t) {
    if (t->currentAddress == NULL || t->currentAddress->prev == NULL) {
        printf("ERROR: BACK TIDAK BISA DIJALANKAN KARENA TIDAK ADA HALAMAN SEBELUMNYA!\n");
        if (t->currentAddress != NULL) {
            printf("[Konten] Menampilkan halaman: %s\n", t->currentAddress->url);
        }
    } else {
        t->currentAddress = t->currentAddress->prev;
        printf("BACK: Kembali ke halaman sebelumnya.\n");
        printf("[Konten] Menampilkan halaman: %s\n", t->currentAddress->url);
    }
}

void forward(Tab *t) {
    if (t->currentAddress == NULL || t->currentAddress->next == NULL) {
        printf("ERROR: FORWARD TIDAK BISA DIJALANKAN KARENA TIDAK ADA HALAMAN SELANJUTNYA!\n");
        if (t->currentAddress != NULL) {
            printf("[Konten] Menampilkan halaman: %s\n", t->currentAddress->url);
        }
    } else {
        t->currentAddress = t->currentAddress->next;
        printf("FORWARD: Maju ke halaman selanjutnya.\n"); // ⁶🤷⁷
        printf("[Konten] Menampilkan halaman: %s\n", t->currentAddress->url);
    }
}
