/* GitHub: https://github.com/Bacagine/despack/src/verify_package.c
 * 
 * Copyright (C) 2020
 * 
 * verify_package.c: Verify if a package is installed on
 * user's system.
 * 
 * Developed by Gustavo Bacagine <gustavo.bacagine@gmail.com>
 * 
 * Begin's data: 09/08/2020
 * Date of last modification: 26/10/2020
 */

#include <stdio.h>
#include <string.h>
#include "../include/package.h"

int verify_package(const char *pack){
    char *extension = (char *) malloc(sizeof(char) * 9);
    
    if(extension == NULL){
        fprintf(stderr, NO_MEMORY);
        return MEM_ERR;
    }
    
    int len;
    
    len = strlen(pack);
    
    /* Taking the package extension */
    for(int count = len-3; count < len; count++){
        strcpy(extension, &pack[count]);
    }
    
    if(!strcmp(extension, "bz2")){
        free(extension);
		extension = NULL;
        return IS_TAR_BZ;
    }
    else if(!strcmp(extension, ".xz")){
        free(extension);
		extension = NULL;
        return IS_TAR_XZ;
    }
    else if(!strcmp(extension, ".gz")){
        free(extension);
		extension = NULL;
        return IS_TAR_GZ;
    }
}
