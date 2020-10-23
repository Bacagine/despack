/* Date of creation: 22/07/2020
 * Date of last modification: 23/10/2020 */

#include <string.h>
#include "../include/package.h"

void compile(char *pkg_src){
    char *src = (char *) malloc(sizeof(char) * 28);
    char *config = (char *) malloc(sizeof(char) * 38);
    char make[46] = "make -f ", make_install[54] = "make install -f ";
    
    /* Armazenando onde o pacote
     * foi descompactado para
     * compilação */
    strcpy(src, pkg_src);
    
    /* config = /usr/src/hello */
    strcpy(config, src);
    
    /* make = make -f /usr/src/hello */
    strcat(make, src);
    
    /* make_install = make install -f /usr/src/hello */
    strcat(make_install, src);
    
    /* config = /usr/src/hello/configure */
    strcat(config, "/configure");
    
    /* make = make -f /usr/src/hello/Makefile */
    strcat(make, "/Makefile");
    
    /* make_install = make install -f /usr/src/hello/Makefile */
    strcat(make_install, "/Makefile");
    
    /* Realizando configuração
     * compilação e insalação
     * do programa */
    system(config);
    system(make);
    system(make_install);
    
    free(config);
    free(src);
}
