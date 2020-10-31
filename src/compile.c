/* GitHub: https://github.com/Bacagine/despack/src/compile.c
 * 
 * Copyright (C) 2020
 * 
 * compile.c: 
 * 
 * Developed by Gustavo Bacagine <gustavo.bacagine@gmail.com>
 * 
 * Begin's date: 22/07/2020
 * Date of last modification: 30/10/2020
 */

#include <string.h>
#include "../include/package.h"

int compile(char *pkg_src){
    char *src = (char *) malloc(sizeof(char) * 28);
    char *config = (char *) malloc(sizeof(char) * 38);
    
    /* Verify if memory allocation is possible */
    if(src == NULL || config == NULL){
        fprintf(stderr, NO_MEMORY);
        return MEM_ERR;
    }
    
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
    
    /* Make the configuration,
     * compilation and instalation
     * of the program. */
    system(config);
    system(make);
    system(make_install);
    
    free(config);
    free(src);
    
    return EXIT_SUCCESS;
}
