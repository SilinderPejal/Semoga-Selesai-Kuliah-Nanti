#ifndef COMMAND_H
#define COMMAND_H

typedef struct {
    const char *name;
    void (*handler)(const char *args);
} Command;

// Utility
void stripNewline(char *str);
const char *stripWhitespace(const char *str);
const char *splitArgs(char *line, char **cmd_out);

// Core
void eval(char *input);

// Command Handlers
void cmdDiscover(const char *args);
void cmdSearch(const char *args);
void cmdOpen(const char *args);
void cmdAddPage(const char *args);
void cmdEditPage(const char *args);
void cmdDeletePage(const char *args);
// tab management
void cmdChecktab(const char *args);
void cmdNewtab(const char *args);
void cmdClosetab(const char *args);
void cmdNexttab(const char *args);
void cmdPrevtab(const char *args);
// back forward
void cmdBack(const char *args);
void cmdForward(const char *args);
void cmdBackX(const char *args);
void cmdForwardX(const char *args);
// tab history
void cmdHistory(const char *args);
void cmdOpenlinked(const char *args);
// bookmark
void cmdAddBookmark(const char *args);
void cmdViewBookmark(const char *args);
void cmdDeleteBookmark(const char *args);
void cmdOpenBookmark(const char *args);
// download
void cmdDownload(const char *args);
void cmdTick(const char *args);
void cmd67(const char *args);
// exit
void cmdExit(const char *args);
// 67
void cmd67(const char *args);

#endif