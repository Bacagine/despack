/* GitHub: https://github.com/Bacagine/despack
 * 
 * Copyright (C) 2020
 * 
 * list.c: 
 * 
 * 
 * 
 * 
 * Begin's date: 07/22/2020
 * Date of last modification: 08/17/2020
 */

#include <stdio.h>
#include "../include/package.h"

void listar_pacotes(void){
    FILE *list;
    
    if((list = fopen(PKG_INSTALLED_LIST, "rb")) == NULL){
        fprintf(stderr, "Error: %s no such file or directory!\n", PKG_INSTALLED_LIST);
        return;
    }
    
    package pkg;
    
    fprintf(stdout, "**********************************************************\n");
    fprintf(stdout, "#Package  Memory  Date Hour\n");
    fprintf(stdout, "**********************************************************\n");
    while(fread(&pkg, sizeof(package), 1, list) > 0){
        fprintf(stdout, "%-50.50s %.2lf %02d/%02d/%02d - %02dh:%02dmin:%02dsec\n", pkg.name, pkg.memory,
                                                                                   pkg.dt_instalacao.day,
                                                                                   pkg.dt_instalacao.month,
                                                                                   pkg.dt_instalacao.year,
                                                                                   pkg.tm_instalacao.hour,
                                                                                   pkg.tm_instalacao.minute,
                                                                                   pkg.tm_instalacao.second);
    }
    fprintf(stdout, "**********************************************************\n");
}
