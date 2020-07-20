/* GitHub: https://github.com/Bacagine/despack
 * 
 * download.c: Archive with function for download
 * package.
 * 
 * Developers: Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * 
 * 
 * 
 * Date of begin: 20/07/2020
 * Data of last modification: 20/07/2020
 */

#include <stdio.h>
#include <string.h>
#include "../include/package.h"

size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream){
    size_t written = fwrite(ptr, size, nmeb, stream);
    return written;
}

int download(const char *pkg){
    FILE *list;
    
    printf("Reading package list...\n");
    
    if((list = fopen(PKG_LIST, "r")) == NULL){
        fprintf(stderr, "Error: %s archive or directory not found!\n", PKG_LIST);
        return 1;
    }
    
    char line[100000], *url;
    int count = 0;
    
    /* Reading the package list */
    while(fgets(line, 100000, list) != NULL){
        /* search package on list */
        if(strstr(pkg, line)){
            count++;
            fscanf(list, "%s", url);
        }
    }
    
    /* If package not 
     * found */
    if(count == 0){
        fprintf(stderr, "Error: Package %s not found!\n", pkg);
        return 1;
    }
    
    /* Close package 
     * list */
    fclose(list);
    
    CURL *curl;
    CURLcode res;
    FILE *pack;
    
    curl = curl_easy_init();
    if(curl){
        pack = fopen(pkg, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEINFO, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, pack);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(pack);
        return 0;
    }
}
