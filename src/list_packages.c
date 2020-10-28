/* GitHub: https://github.com/Bacagine/despack/src/list_packages.c
 * 
 * Copyright (C) 2020
 * 
 * list_packages.c: Show the package list installed on user's system
 * 
 * Developed Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * Begin's date: 22/07/2020
 * Date of last modification: 26/10/2020
 */

#include <stdio.h>
#include "../include/package.h"

int list_packages(void){
    /* List with the package
     * installed on system */
    FILE *list;
    
    /* Verifing if the list exist on user's system */
    if((list = fopen(PKG_INSTALLED_LIST, "rb")) == NULL){
        fprintf(stderr, "Error: %s no such file or directory!\n", PKG_INSTALLED_LIST);
        return FILE_ERR;
    }
    
    package *pkg = (package *) malloc(sizeof(package));
    
    /* Showing the packages installed on system */
    fprintf(stdout, "**********************************************************\n");
    fprintf(stdout, "#Package  Memory  Date Hour\n");
    fprintf(stdout, "**********************************************************\n");
    while(fread(pkg, sizeof(package), 1, list) > 0){
        fprintf(stdout, "%-50.50s %s %02d/%02d/%02d - %02dh:%02dmin:%02dsec\n", pkg->name, pkg->memory,
                                                                                pkg->dt_instalacao.day,
                                                                                pkg->dt_instalacao.month,
                                                                                pkg->dt_instalacao.year,
                                                                                pkg->tm_instalacao.hour,
                                                                                pkg->tm_instalacao.minute,
                                                                                pkg->tm_instalacao.second);
    }
    fprintf(stdout, "**********************************************************\n");
    free(pkg);
    return OK;
}
