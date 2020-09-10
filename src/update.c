/* Date of begin: 07/21/2020 */

#include <stdio.h>
#include "../include/package.h"

void update(void){
    FILE *list;
    
    /* Remove a lista
     * antiga */
    remove(PKG_LIST);
    
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    /* Instala a lista nova */
    if(curl){
        list = fopen(PKG_LIST, "w");
        curl_easy_setopt(curl, CURLOPT_URL, pkg_list_url);
        curl_easy_setopt(curl, CURLOPT_WRITEINFO, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, list);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(list);
    }
}
