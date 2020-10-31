/* GitHub: https://github.com/Bacagine/despack/src/unpack.c
 * 
 * Copyright (C) 2020
 * 
 * unpack.c: Unpacking a package
 * 
 * Developed by Gustavo Bacagine <gustavo.bacagine@gmail.com>
 * 
 * Begin's date: 22/07/2020
 * Date of last modification: 30/10/2020
 */

#include <string.h>
#include "../include/package.h"

int unpack(const char *pkg_downloaded, const char *pkg_despack){
    char tar[5] = "tar ";
    const char tar_options[3][7] = { "-xzvf ", "-xvf ", "-xjvf " };
    char *command = (char *) malloc(sizeof(char) * 69);
    
    /* Verify if memory
     * allocation is
     * possible */
    if(command == NULL){
        fprintf(stderr, NO_MEMORY);
        return MEM_ERR;
    }
    
/*    char extension[9];
    int len;
    
    len = strlen(pkg_downloaded);
    
    ola.tar.xz
    for(int count = len-3; count < len; count++){
        strcpy(extension, &pkg_downloaded[count]);
    }*/
    
    /* command = "tar " */
    strcpy(command, tar);
    
    /* Verifing the extension of the package to
     * unzip properly */
    if(verify_package(pkg_downloaded) == 0){
        /* command = "tar -xzvf " */
        strcat(command, tar_options[0]);
        
        /* command = "tar -xzvf ola.tar.xz" */
        strcat(command, pkg_downloaded);
        
        /* command = "tar -xzvf ola.tar.xz -C " */
        strcat(command, " -C ");
        
        /* command = "tar -xzvf ola.tar.xz -C /usr/src/ola" */
        strcat(command, pkg_despack);
        
        /* execute tar -xzvf ola.tar.xz -C /usr/src/ola */
        system(command);
    }
    else if(verify_package(pkg_downloaded) == 1){
        /* command = "tar -xvf " */
        strcat(command, tar_options[1]);
        
        /* command = "tar -xvf ola.tar.xz" */
        strcat(command, pkg_downloaded);
        
        /* command = "tar -xvf ola.tar.xz -C " */
        strcat(command, " -C ");
        
        /* command = "tar -xvf ola.tar.gz -C /usr/src/ola" */
        strcat(command, pkg_despack);
        
        /* execute tar -xvf ola.tar.gz -C /usr/src */
        system(command);
    }
    else if(verify_package(pkg_downloaded) == -1){
        /* command = "tar -xjvf " */
        strcat(command, tar_options[2]);
        
        /* command = "tar -xjvf ola.tar.xz" */
        strcat(command, pkg_downloaded);
        
        /* command = "tar -xjvf ola.tar.xz -C " */
        strcat(command, " -C ");
        
        /* command = "tar -xjvf ola.tar.bz2 -C /usr/src/ola" */
        strcat(command, pkg_despack);
        
        /* execute tar -xjvf ola.tar.bz2 -C /usr/src */
        system(command);
    }
    free(command);
    return EXIT_SUCCESS;
}
