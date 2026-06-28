#include <stdio.h>
#include <string.h>
#include "../header/discover.h"

/*algoritma lcg untuk minimal lima elemen*/
/*output ADT yang berisi 5 WebPage yang sudah ter randomize dari yg sebelumnya*/
WebDb lcgFive(WebDb web) {
    /*Deklarasi ADT List baru*/
    WebDb afterLcg;

    /*LCG ALGORITHM, WebPage.id based!*/
    int seed = 1; /*Dari satu biasanya emang*/
    int a = 2 + (web.count % 2); /*Biar random aja*/
    int c = web.count % 2; /*Biar random aja*/
    int m = web.count; /*Max dari nilai yang mungkin*/
    int x = seed;

    for (int i = 0; i<5; i++) {
        x = (a * x + c) % m;
        afterLcg.elements[i] = web.elements[x]; 
    }

    afterLcg.count = 5;
    return afterLcg;
}

/*discover f01*/
void discover(WebDb web) {
    printf("Berikut adalah beberapa halaman acak yang telah anda kunjungi:\n");

    /*Cond. 1: Halaman >= 5*/
    if (web.count > 4) {
        WebDb randomized = lcgFive(web);
        for (int i = 0; i < 5; i++) {
            printf("%d. %s\n", i + 1, randomized.elements[i].url);
        }
    } else { /*Halaman < 5, jadi lgsg display all.*/
        for (int i = 0; i < web.count; i++) {
            printf("%d. %s\n", i + 1, web.elements[i].url);
        }
    }
    
}
