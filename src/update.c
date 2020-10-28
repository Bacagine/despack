/* GitHub: 
 * 
 * COpyright (C) 2020
 * 
 * update.c: 
 * 
 * Developed by Gustavo Bacagine       <gustavo.bacagine@protonmail.com>
 *              Lucas Pereira de Matos <lucas.pereira.matos.000@gmail.com>
 * 
 * Begin's date: 21/07/2020
 */

#include <stdio.h>
#include "../include/package.h"

void update(void){
    /* New list to be downloaded */
    FILE *new_list;
    
    /* Backup of the actual list */
    rename(PKG_LIST, PKG_LIST_OLD);
    
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    /* Install the new list */
    if(curl){
        new_list = fopen(PKG_LIST, "w");
        curl_easy_setopt(curl, CURLOPT_URL, pkg_list_url);
        curl_easy_setopt(curl, CURLOPT_WRITEINFO, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, new_list);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(new_list);
    }
    
    /* Remove the old
     * list */
    remove(PKG_LIST_OLD);
}
