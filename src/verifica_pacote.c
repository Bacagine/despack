/* 
 * Data: 09/08/2020
 * Data da última modificação: 23/10/2020
 */

#include <stdio.h>
#include <string.h>
#include "../include/package.h"

int verifica_pacote(const char *pkg){
    char *extension = (char *) malloc(sizeof(char) * 9);
    int len;
    
    len = strlen(pkg);
    
    /* Pegando a extensão do pacote */
    for(int count = len-3; count < len; count++){
        strcpy(extension, &pkg[count]);
    }
    
    if(!strcmp(extension, "bz2")){
        free(extension);
        return -1;
    }
    else if(!strcmp(extension, ".xz")){
        free(extension);
        return 0;
    }
    else if(!strcmp(extension, ".gz")){
        free(extension);
        return 1;
    }
}
