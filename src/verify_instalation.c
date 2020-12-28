/* GitHub: https://github.com/Bacagine/despack/src/verify_instalation.c
 * 
 * Copyright (C) 2020
 * 
 * verify_instalation.c: 
 * 
 * Developed by Gustavo Bacagine <gustavo.bacagine@gmail.com>
 * 
 * Begin's date: 10/08/2020
 * Date of last modification: 30/10/2020
 */

#include <stdio.h>
#include <string.h>
#include "../include/package.h"

int verify_instalation(const char *pkg_name){
    FILE *prog;
    char *pack = (char *) malloc(sizeof(char) * 25);
    
    /* Verify if the memory
     * allocation is possible */
    if(pack == NULL){
        fprintf(stderr, NO_MEMORY);
        return MEM_ERR;
    }
    
    strcpy(pack, BIN_DIR);
    strcat(pack, pkg_name);
    
    /* Verify if the package is installed on system */
    if((prog = fopen(pack, "rb")) == NULL){
        return EXIT_FAILURE;
    }
    
    fclose(prog);
    
    free(pack);

	pack = NULL;
    
    return EXIT_SUCCESS;
}
