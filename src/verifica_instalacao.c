/* Data: 10/08/2020
 * Data da ultima modificação: 23/10/2020 */

#include <stdio.h>
#include <string.h>
#include "../include/package.h"

int verifica_instalacao(const char *pkg_name){
    FILE *prog;
    char *pkg = (char *) malloc(sizeof(char) * 25);
    
    strcpy(pkg, "/usr/bin/");
    strcat(pkg, pkg_name);
    
    /* Verifica se o pacote está instalado no sistema */
    if((prog = fopen(pkg, "rb")) == NULL){
        return 1;
    }
    
    fclose(prog);
    
    free(pkg);
    
    return 0;
}
