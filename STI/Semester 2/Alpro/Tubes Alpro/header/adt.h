#ifndef ADT_H
#define ADT_H

#define MAX_WEB_PAGES 100
#define MAX_URL 100
#define MAX_CONTENT 5000
#define MAX_CACHE 50
#define TABS_MAX_AMOUNT 10
#define MAX_LINKS 20
#define HISTORY_MAX_AMOUNT 20
#define DOWNLOAD_MAX_AMOUNT 5
#define BOOKMARK_MAX 100

//buat f03 open page
typedef struct {
    int id;
    char url[MAX_URL];
    char content[MAX_CONTENT];
} WebPage;

//ADT Set untuk menyimpan daftar halaman web
typedef struct {
    WebPage elements[MAX_WEB_PAGES];
    int count;
} WebDb;

//buat f04 cache
typedef struct {
    char keyUrl[MAX_CACHE][MAX_URL];
    char valueContent[MAX_CACHE][MAX_CONTENT];
    int count;
    int firstInIndex;
} CacheMap;

typedef struct {
    char tab_name[10];
    WebPage current_page;
    int is_page_open;
} BrowserTab;

typedef struct {
    BrowserTab tabs[TABS_MAX_AMOUNT];
    int count;
    int active_idx;
} TabSystem;

typedef struct {
    int source_id;
    int target_ids[MAX_LINKS];
    int link_count;
} GraphNode;

typedef struct {
    GraphNode nodes[MAX_WEB_PAGES];
    int node_count;
} WebGraph;


// buat spek bonus global history
typedef struct {
    char url[MAX_URL];
    int accessTime;
} GlobalHistoryEntry;

typedef struct {
    GlobalHistoryEntry entries[HISTORY_MAX_AMOUNT];
    int count; // ⁶🤷⁷
    int currentTime;
} GlobalHistory;

// bookmark
typedef struct {
    char alias[50];
    char url[MAX_URL];
} Bookmark;

typedef struct {
    Bookmark data[BOOKMARK_MAX];
    int count;
} BookmarkList;


#endif
