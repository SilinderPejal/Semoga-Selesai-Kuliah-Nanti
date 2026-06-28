#include <stdio.h>
#include <string.h>
#include "../header/openpage.h"
#include "../header/cache.h"

void loadWebDb(WebDb *web) {
    web->count = 5;

    web->elements[0].id = 1;
    strcpy(web->elements[0].url, "mysteryshack.com");
    strcpy(
        web->elements[0].content,
        "SELAMAT DATANG DI MYSTERY SHACK!\n"
        "Tempat paling ajaib di Nangor Falls\n"
        "(dan satu-satunya yang punya diskon 0%!)."
    );

    web->elements[1].id = 2;
    strcpy(web->elements[1].url, "gideon-tent.org");
    strcpy(
        web->elements[1].content,
        "BACA MASA DEPANMU DI SINI!\n"
        "\"Gideon kecil\" tahu segalanya tentangmu."
        "…dan masa depan itu mungkin tidak menyukaimu.\n"
        "WARNING: ramalan bisa menyebabkan paranoia ringan sampai eksistensial."
    );

    web->elements[2].id = 3;
    strcpy(web->elements[1].url, "mebelrajut.net");
    strcpy(
        web->elements[1].content,
        "MEBEL PINUS HANDMADE SHOP!\n"
        "Haiiii! Selamat datang di dunia rajutan Mabel!\n"
        "Aku bikin sweater lucu, boneka rajut, dan gelang persahabatan!\n"
        "Semua dibuat dengan cinta, glitter, dan sedikit terlalu banyak energi!\n"
        "Produk dijamin bisa bikin kamu tiba-tiba merasa lebih ceria dari biasanya :)"
    );

    web->elements[3].id = 4;
    strcpy(web->elements[3].url, "nangor-paranormal-log.id");
    strcpy(
    web->elements[3].content,
        "LOG KEJADIAN ANEH NANGOR FALLS #447\n"
        "- Jam 02:33, semua bayangan menghadap arah yang sama\n"
        "- Lampu jalan berkedip membentuk kode Morse: 'JANGAN BUKA'\n"
        "- Seorang warga mengaku melihat dirinya sendiri masuk ke toko\n"
        "Status: belum diselidiki karena semua investigator menghilang."
    );   

    web->elements[3].id = 4;
    strcpy(web->elements[3].url, "soosremodels.com");
    strcpy(
    web->elements[3].content,
        "SOOS REPAIR & FIX-IT SERVICE!\n"
        "Spesialis: perbaikan Mystery Shack, TV rusak, pintu aneh, dan hal-hal yang tidak seharusnya hidup.\n"
        "GARANSI: kalau makin rusak, kita anggap itu upgrade."
    );
}


int findWebPage(WebDb *web, char url[]) {
    for (int i = 0; i < web->count; i++) {
        if (strcmp(web->elements[i].url, url) == 0) {
            return i;
        }
    }
    return -1;
}

void openPage(WebDb *web, CacheMap *cache, char url[]) {
int cacheIndex = findCache(cache, url);

    // cache found
    if (cacheIndex != -1) {

        printf("[Status: Cache-Found] Mengambil data dari cache...\n");

        printf("%s\n", cache->valueContent[cacheIndex]);

        return;
    }

    // cache miss
    int webIndex = findWebPage(web, url);

    if (webIndex != -1) {

        printf("[Status: Cache-Miss] Mengambil data dari Web Database...\n");

        printf("%s\n", web->elements[webIndex].content);

        putCache(
            cache,
            web->elements[webIndex].url,
            web->elements[webIndex].content
        );

        return;
    }
    printf("404 Not Found! Halaman tidak ditemukan.\n"); // ⁶🤷⁷
}