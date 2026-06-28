#include <stdio.h>
#include <string.h>
#include "../header/search.h"

/*nge sort WebDb asli*/
void sortWebDb(WebDb *web) {
    for (int i = 0; i < web->count - 1; i++) {
        for (int j = 0; j < web->count - i - 1; j++) {
            if (strcmp(web->elements[j].url, web->elements[j+1].url) > 0) {
                WebPage temp = web->elements[j]; /*biar g ilang*/
                web->elements[j] = web->elements[j+1];
                web->elements[j + 1] = temp;
            }
        }
    }
}

/*ubah jadi lowercase manual*/
void toLowerCase(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
}

/*cek substring case insensitive*/
int IgnoreCase(char text[], char query[]) {
    char lowerText[1000];
    char lowerQuery[1000];
    strcpy(lowerText, text);
    strcpy(lowerQuery, query);
    toLowerCase(lowerText);
    toLowerCase(lowerQuery);

    int panjangText = strlen(lowerText);

    int panjangQuery = strlen(lowerQuery);

    for (int i = 0; i <= panjangText - panjangQuery; i++) {
        int cocok = 1;
        for (int j = 0; j < panjangQuery; j++) {
            if (lowerText[i + j] != lowerQuery[j]) {
                cocok = 0;
                break;
            }
        }

        if (cocok) {
            return 1;
        }
    }

    return 0;
}


/*Print hasil tiga fungsi diatas*/
void printSearchResult(WebDb result, char query[]) {
    if (result.count == 0) {
        printf("Tidak ada hasil untuk \"%s\"!\n", query);
        return;
    }

    printf("Search result(s) for \"%s\":\n", query); // ⁶🤷⁷
    for (int i = 0; i < result.count; i++) {
        printf("%d. %s\n", i + 1, result.elements[i].url);
    }
}

/*Real fungsi search yang gabungin keempat diatas*/
void searchPage(WebDb *web, char query[]) {

    /* 1. Copy database asli */
    WebDb temp = *web;

    /* 2. Sort database copy */
    sortWebDb(&temp);

    /*hasil search*/
    WebDb result;
    result.count = 0;

    /* 3. search */
    for (int i = 0; i < temp.count; i++) {
        int matchURL = IgnoreCase(temp.elements[i].url, query);

        /*cek content*/
        int matchContent = IgnoreCase(temp.elements[i].content, query);

        /*kalo salah satu cocok*/
        if (matchURL || matchContent) {
            result.elements[result.count] = temp.elements[i];
            result.count++;
        }
     }
    /* 5. Tampilkan hasil */
    printSearchResult(result, query);
}