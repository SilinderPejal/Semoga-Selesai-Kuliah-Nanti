#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../header/command.h"
#include "../header/adt.h"
#include "../header/openpage.h"
#include "../header/cache.h"
#include "../header/discover.h"
#include "../header/search.h"
#include "../header/browser.h"
#include "../header/backforward.h"
#include "../header/tab_history.h"
#include "../header/page_management.h"
#include "../header/globalhistory.h"
#include "../header/bookmark.h"
#include "../header/67.h"
#include "../header/download.h"

// EXTERNAL GLOBAL VARIABLES
extern WebDb web;
extern CacheMap cache;
extern TabSystem tabSystem;
extern WebGraph graph;
extern BookmarkList bookmarks;
extern DownloadQueue downloadQueue;

// =========================
// COMMAND ARRAY
// =========================

static const Command COMMANDS[] = {
    {"discover", cmdDiscover},
    {"search", cmdSearch},
    {"open", cmdOpen},
    {"add_page", cmdAddPage},
    {"edit_page", cmdEditPage},
    {"delete_page", cmdDeletePage},
    {"checktab", cmdChecktab},
    {"newtab", cmdNewtab},
    {"closetab", cmdClosetab},
    {"nexttab", cmdNexttab},
    {"prevtab", cmdPrevtab},
    {"back", cmdBack},
    {"forward", cmdForward},
    {"backX", cmdBackX},
    {"forwardX", cmdForwardX},
    {"history", cmdHistory},
    {"openlinked", cmdOpenlinked},
    {"download", cmdDownload},
    {"tick", cmdTick},
    {"add_bookmark", cmdAddBookmark},
    {"view_bookmark", cmdViewBookmark},
    {"delete_bookmark", cmdDeleteBookmark},
    {"open_bookmark", cmdOpenBookmark},
    {"67", cmd67},
    {"exit", cmdExit}
};

static const int NUM_COMMANDS =
    sizeof(COMMANDS) / sizeof(COMMANDS[0]);

// =========================
// UTILITIES
// =========================

void stripNewline(char *str) {
 // ⁶🤷⁷
    int len = strlen(str);

    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

const char *stripWhitespace(const char *str) {

    while (*str == ' ' || *str == '\t') { //67
        str++;
    }

    return str;
}

const char *splitArgs(char *line, char **cmd_out) {

    char *ptr = (char *) stripWhitespace(line);

    *cmd_out = ptr;

    while (*ptr && *ptr != ' ' && *ptr != '\t') {
        ptr++;
    }

    if (*ptr) {

        *ptr = '\0';
        ptr++;

        return stripWhitespace(ptr);
    }

    return ptr;
}

// =========================
// EVAL
// =========================

void eval(char *input) {

    char *cmd = NULL;

    const char *args =
        splitArgs(input, &cmd);

    if (cmd == NULL || *cmd == '\0') {
        return;
    }

    for (int i = 0; i < NUM_COMMANDS; i++) {

        if (strcmp(cmd, COMMANDS[i].name) == 0) {

            COMMANDS[i].handler(args);

            return;
        }
    }

    printf("Command tidak valid!\n");
}

// =========================
// COMMAND HANDLERS
// =========================

void cmdDiscover(const char *args) {

    discover(web);
}

void cmdSearch(const char *args) {

    searchPage(&web, (char *) args);
}

void cmdOpen(const char *args) {

    if (!isValidURL((char *) args)) {

        printf("Format URL tidak valid!\n");

        return;
    }

    openPage(
        &web,
        &cache,
        (char *) args
    );

    addGlobalHistory(
        &globalHistory,
        (char *) args
    );

    openNewPage(
        &tabHistories[
            tabSystem.active_idx
        ],
        (char *) args
    );
}

void cmdAddPage(const char *args) {

    addPage(
        &web,
        &cache,
        &graph,
        (char *) args
    );
}

void cmdEditPage(const char *args) {

    editPage(
        &web,
        &cache,
        &graph,
        (char *) args
    );
}

void cmdDeletePage(const char *args) {

    deletePage(
        &web,
        &cache,
        &graph,
        (char *) args
    );
}

void cmdChecktab(const char *args) {

    checktab(&tabSystem);
}

void cmdNewtab(const char *args) {

    newtab(&tabSystem);
}

void cmdClosetab(const char *args) {

    closetab(&tabSystem);
}

void cmdNexttab(const char *args) {

    int steps;

    if (!isValidNumericX(
            (char *) args,
            &steps
        )) {

        printf(
            "Input numerik tidak valid!\n"
        );

        return;
    }

    nexttab(
        &tabSystem,
        steps
    );
}

void cmdPrevtab(const char *args) {

    int steps;

    if (!isValidNumericX(
            (char *) args,
            &steps
        )) {

        printf(
            "Input numerik tidak valid!\n"
        );

        return;
    }

    prevtab(
        &tabSystem,
        steps
    );
}

void cmdBack(const char *args) {

    back(
        &tabHistories[
            tabSystem.active_idx
        ]
    );
}

void cmdForward(const char *args) {

    forward(
        &tabHistories[
            tabSystem.active_idx
        ]
    );
}

void cmdBackX(const char *args) {

    int x;

    if (!isValidNumericX(
            (char *) args,
            &x
        )) {

        printf(
            "Input numerik tidak valid!\n"
        );

        return;
    }

    backX(
        x,
        &tabSystem,
        &web,
        &cache
    );
}

void cmdForwardX(const char *args) {

    int x;

    if (!isValidNumericX(
            (char *) args,
            &x
        )) {

        printf(
            "Input numerik tidak valid!\n"
        );

        return;
    }

    forwardX(
        x,
        &tabSystem,
        &web,
        &cache
    );
}

void cmdHistory(const char *args) {

    printGlobalHistory(
        &globalHistory
    );
}

void cmdOpenlinked(const char *args) {

    int index;

    if (!isValidNumericX(
            (char *) args,
            &index
        )) {

        printf(
            "Input numerik tidak valid!\n"
        );

        return;
    }

    openlinked(
        &tabSystem,
        &graph,
        &web,
        &cache,
        index
    );
}

void cmdDownload(const char *args) {

    download(
        &downloadQueue,
        args
    );
}

void cmdAddBookmark(const char *args) {

    char alias[50];
    char url[MAX_URL];

    sscanf(
        args,
        "%s %s",
        alias,
        url
    );

    addBookmark(
        &bookmarks,
        &web,
        alias,
        url
    );
}

void cmdViewBookmark(const char *args) {
    viewBookmark(bookmarks);
}

void cmdDeleteBookmark(const char *args) {
    deleteBookmark(
        &bookmarks,
        args
    );
}

void cmdOpenBookmark(const char *args) {

    openBookmark(
        &bookmarks,
        &web,
        &cache,
        args
    );
}

void cmdTick(const char *args) {

    tick(&downloadQueue);
}

void cmd67(const char *args) {
    rokunana();
}

void cmdExit(const char *args) {

    printf(
        "Terima kasih telah menggunakan Nangor Browser!\n"
    );

    exit(0);
}