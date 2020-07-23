/* GitHub: https://github.com/Bacagine/despack
 * 
 * Copyright (C) 2020
 * 
 * list.c: 
 * 
 * 
 * 
 * 
 * Date of begin: 22/07/2020
 * Date of last modification: 22/07/2020
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
    fprintf(stdout, "#Package  Memory  Date\n");
    fprintf(stdout, "**********************************************************\n");
    while(fread(&pkg, sizeof(package), 1, list) > 0){
        fprintf(stdout, "%-50.50s %.2lf %02d/%02d/%02d\n", pkg.name, pkg.memory, pkg.dt_instalacao.dia,
                                                           pkg.dt_instalacao.mes, pkg.dt_instalacao.ano);
    }
    fprintf(stdout, "**********************************************************\n");
}
