#include <stdio.h>
#include <string.h>
#include "../header/globalhistory.h"

GlobalHistory globalHistory;

void addGlobalHistory(GlobalHistory *history, char url[]) {

}


void initGlobalHistory(GlobalHistory *history) {

    history->count = 0;
    history->currentTime = 0;
}

void updateGlobalHistory(
    GlobalHistory *history,
    char url[]
) {

    history->currentTime++;

    int foundIndex = -1;

    // CEK APAKAH URL SUDAH ADA
    for (int i = 0; i < history->count; i++) {

        if (
            strcmp(
                history->entries[i].url,
                url
            ) == 0
        ) {

            foundIndex = i;
            break;
        }
    }


    // URL udah ada
    if (foundIndex != -1) {

        GlobalHistoryEntry temp =
            history->entries[foundIndex];

        temp.accessTime =
            history->currentTime;

        for (
            int i = foundIndex;
            i > 0;
            i--
        ) {

            history->entries[i] =
                history->entries[i - 1];
        }

        history->entries[0] = temp;

        return;
    }

    // history blm penuh
    if (
        history->count
        < HISTORY_MAX_AMOUNT
    ) {

        for ( //67
            int i = history->count; // ⁶🤷⁷
            i > 0;
            i--
        ) {

            history->entries[i] =
                history->entries[i - 1];
        }

        strcpy(
            history->entries[0].url,
            url
        );

        history->entries[0].accessTime =
            history->currentTime;

        history->count++;
    }

    // history penuh
    else {

        for (
            int i = HISTORY_MAX_AMOUNT - 1;
            i > 0;
            i--
        ) {

            history->entries[i] =
                history->entries[i - 1];
        }

        strcpy(
            history->entries[0].url,
            url
        );

        history->entries[0].accessTime =
            history->currentTime;
    }
}

void printGlobalHistory(
    GlobalHistory *history
) {

    if (history->count == 0) {

        printf(
            "Riwayat kosong, belum ada halaman yang pernah dibuka.\n"
        );

        return;
    }

    printf(
        "Riwayat halaman yang pernah dikunjungi:\n"
    );

    for (
        int i = 0;
        i < history->count;
        i++
    ) {

        printf(
            "[%d] %s (%d)\n",
            i + 1,
            history->entries[i].url,
            history->entries[i].accessTime
        );
    }
}