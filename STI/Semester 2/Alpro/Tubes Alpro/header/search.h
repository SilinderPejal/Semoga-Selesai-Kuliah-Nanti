#ifndef SEARCH_H
#define SEARCH_H
#include "adt.h"

/*Sort halaman-halaman yang ada pake bubble sort*/
void sortWebDb(WebDb *web);

// search utility
void toLowerCase(char str[]);
int IgnoreCase(char text[], char query[]);

/*Print hasil search dari tiga fungsi diatas bos*/
void printSearchResult(WebDb result, char query[]);

/*Real fungsi search yang gabungin keempat diatas*/
void searchPage(WebDb *web, char query[]);

#endif