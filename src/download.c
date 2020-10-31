/* GitHub: https://github.com/Bacagine/despack/src/download.c
 * 
 * download.c: Archive with function for download package.
 * 
 * Copyright (C) 2020
 * 
 * Developed by: Gustavo Bacagine       <gustavo.bacagine@protonmail.com>
 *               Lucas Pereira de Matos <lucas.pereira.matos.000@gmail.com>
 * 
 * Begin's date: 20/07/2020
 * Data of last modification: 30/10/2020
 */

#include <stdio.h>
#include <string.h>
#include "../include/package.h"

size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream){
    size_t written = fwrite(ptr, size, nmeb, stream);
    return written;
}

int download(const char *pkg_name, char *pack, char *pkg_downloaded, char *pkg_despack){
    /* List of existing
     * packages in
     * repository */
    FILE *list;
    
    printf("Reading package list...\n");
    
    /* Verifing if the package list exist in user's system */
    if((list = fopen(PKG_LIST, "r")) == NULL){
        fprintf(stderr, "Error: %s no such file or directory!\n", PKG_LIST);
        return FILE_ERR;
    }
    
    /* The variable aux will be stored
     * the content found on list
     * to complet the url.
     * 
     * For example:
     * aux = h/hello.tar.xz
     * repository = https://despack.github.com/packages/
     * url = https://despack.github.com/packages/h/hello.tar.xz */
    char *line = (char *) malloc(sizeof(char) * 100);
    char *aux = (char *) malloc(sizeof(char) * 51);
    
    /* Verify if memory allocation is possible */
    if(line == NULL || aux == NULL){
        fprintf(stderr, NO_MEMORY);
        return MEM_ERR;
    }
    
    int count = 0;
    
    /* Reading the package list */
    while(fgets(line, 100, list) != NULL){
//    while(fscanf(list, "%100[^\n]", line)){
        /* search package on list */
        if(strstr(line, pkg_name)){
            count++;
            /* aux = h/hello.tar.xz */
            strcpy(aux, line);
            //sscanf(aux, "%100[^\n]", line);
            /* pkg = hello.tar.xz */
            strcpy(pack, &line[2]);
            break;
        }
    }
    
    /* If the package
     * not found */
    if(count == 0){
        fprintf(stderr, "Error: Package %s not found!\n", pkg_name);
        return NO_PACK;
    }
    
    /* Close the 
     * package list */
    fclose(list);
    
    /* Veryfing the length of the string pack */
    int pkg_len;
    pkg_len = strlen(pack);
    
    /* pkg_len = hello */
    pkg_len -= 7;
    
//    for(int count = 0; count <= pkg_len; count++){
        /* pkg_despack = hello */
        strncpy(pkg_despack, pack, pkg_len);
//    }
    
    /* url = link to download the package */
    char url[51];
    
    /* url = https://despack.github.io/packages/ */
    strcpy(url, repository);

    /* url = https://despack.github.com/packages/h/hello.tar.xz */
    strcat(url, aux);

    /* pkg_dowloaded = /usr/share/despack/packages/ */
    strcpy(pkg_downloaded, PKG_FOLDER);

    /* pkg_dowloaded = /usr/share/despack/packages/hello.tar.xz */
    strcat(pkg_downloaded, pack);
    
    CURL *curl;
    CURLcode res;
    FILE *pack_d;
    
//    printf("%s\n", pkg_despack);
    
    curl = curl_easy_init();
    if(curl){
        pack_d = fopen(pkg_downloaded, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEINFO, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, pack_d);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(pack_d);
    }
    
    free(aux);
    free(line);
    
    return EXIT_SUCCESS;
}
