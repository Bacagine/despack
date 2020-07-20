#include <stdio.h>
#include "../include/package.h"

void update(void){
    FILE *list;
    
    remove(PKG_LIST);
    
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl){
        list = fopen(PKG_LIST, "w");
        curl_easy_setopt(curl, CURLOPT_URL, "https://github.com/Bacagine/despack/despack.list");
        curl_easy_setopt(curl, CURLOPT_WRITEINFO, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, list);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(list);
    }
}
