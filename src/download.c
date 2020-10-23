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
 * Data of last modification: 23/10/2020
 */

#include <stdio.h>
#include <string.h>
#include "../include/package.h"

size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream){
    size_t written = fwrite(ptr, size, nmeb, stream);
    return written;
}

int download(const char *pkg_name, char *pkg, char *pkg_downloaded, char *pkg_despack){
    /* Lista de pacotes
     * existentes no
     * repositorio */
    FILE *list;
    
    printf("Reading package list...\n");
    
    if((list = fopen(PKG_LIST, "r")) == NULL){
        fprintf(stderr, "Error: %s no such file or directory!\n", PKG_LIST);
        return 1;
    }
    
    /* A variavel aux irá armazenar
     * o contéudo encontrado na lista
     * para completar a url.
     * 
     * Por exemplo:
     * aux = h/hello.tar.xz
     * repository = https://despack.github.com/packages/
     * url = https://despack.github.com/packages/h/hello.tar.xz */
    char *line = (char *) malloc(sizeof(char) * 100);
    char *aux = (char *) malloc(sizeof(char) * 51);
    int count = 0;
    
    /* Reading the package list */
    while(fgets(line, 100, list) != NULL){
//    while(fscanf(list, "%100[^\n]", line)){
        /* search package on list */
        if(strstr(line, pkg_name)){
            count++;
            /* aux = h/hello.tar.xz */
            //strcpy(aux, line);
            sscanf(aux, "%100[^\n]", line);
            /* pkg = hello.tar.xz */
            strcpy(pkg, &line[2]);
            break;
        }
    }
    
    /* If package not 
     * found */
    if(count == 0){
        fprintf(stderr, "Error: Package %s not found!\n", pkg_name);
        return 1;
    }
    
    /* Close package
     * list */
    fclose(list);
    
    /* Verificando o tamanho da string pkg */
    int pkg_len;
    pkg_len = strlen(pkg);
    
    /* pkg_len = hello */
    pkg_len -= 7;
    
//    for(int count = 0; count <= pkg_len; count++){
        /* pkg_despack = hello */
        strncpy(pkg_despack, pkg, pkg_len);
//    }
    
    /* url = link para baixar o pacote */
    char url[51];
    
    /* url = https://despack.github.io/packages/ */
    strcpy(url, repository);

    /* url = https://despack.github.com/packages/h/hello.tar.xz */
    strcat(url, aux);

    /* pkg_dowloaded = /usr/share/despack/packages/ */
    strcpy(pkg_downloaded, PKG_FOLDER);

    /* pkg_dowloaded = /usr/share/despack/packages/hello.tar.xz */
    strcat(pkg_downloaded, pkg);
    
    CURL *curl;
    CURLcode res;
    FILE *pack;
    
//    printf("%s\n", pkg_despack);
    
    curl = curl_easy_init();
    if(curl){
        pack = fopen(pkg_downloaded, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEINFO, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, pack);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(pack);
    }
    
    free(aux);
    free(line);
    return 0;
}

