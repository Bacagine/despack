/* GitHub: https://github.com/Bacagine/despack/src/install_process.c
 * 
 * Copyright (C) 2020
 * 
 * install_process.c: Instaling process for a package
 * 
 * Developed by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * Date of begin: 22/07/2020
 * Date of last modification: 26/10/2020
 */

#include <string.h>
#include <fatec/fatec.h>
#include "../include/package.h"

int install_process(const char *pkg_name){
    package *pkg = (package *) malloc(sizeof(package));
    
    /* For example: pack = hello.tar.xz
     * pkg_downloaded = /usr/share/despack/hello.tar.xz
     * pkg_despack = hello
     * pkg_src = /usr/src/hello */
    char *pack = (char *) malloc(sizeof(char) * 26);
    char *pkg_downloaded = (char *) malloc(sizeof(char) * 45);
    char *pkg_despack = (char *) malloc(sizeof(char) * 19);
    char *pkg_src = (char *) malloc(sizeof(char) * 28);
    
    /* Verify if memory allocation is possible */
    if(pkg == NULL || pack == NULL || pkg_downloaded == NULL ||
       pkg_despack == NULL || pkg_src == NULL){
        fprint(stderr, NO_MEMORY);
        return MEM_ERR;
    }
    
    int day, month, year, hour, minute, second;
    
    /* Saving the package name
     * to be able to register */
    strcpy(pkg->name, pkg_name);

/*  Aqui precisamos descobrir a
    memoria do pacote e salvar
    na estrutura
    pkg->memory = ; */
    
    download(pkg_name, pack, pkg_downloaded, pkg_despack);
    
    /* pkg_src = /usr/src/ */
    strcpy(pkg_src, PKG_SRC);
    
    /* pkg_src = /usr/src/hello */
    strcat(pkg_src, pkg_despack);
    
    /* Unzip the package to the
     * compiling directory */
    unpack(pkg_name, pkg_src);
    
    /* Compile and install
     * the package */
    compile(pkg_src);
    
    /* Gets the date and time of the package instalation */
    get_date_time(&day, &month, &year, &hour, &minute, &second);
    
    /* It stores the variables on
     * structure package */
    pkg->dt_instalacao.day = day;
    pkg->dt_instalacao.month = month;
    pkg->dt_instalacao.year = year;
    pkg->tm_instalacao.hour = hour;
    pkg->tm_instalacao.minute = minute;
    pkg->tm_instalacao.second = second;
    
    /* If the package was installed make
     * the register of the package on
     * installed package list */
    if(verify_instalation(pkg->name)){
        register_package(pkg);
    }
    else{
        fprintf(stderr, "Error: Nao foi possivel instalar o programa: %s!\n", pkg->name);
        return DEFAULT_ERR;
    }
    
    /* Free the memory
     * space that was
     * allocated */
    free(pkg_src);
    free(pkg_despack);
    free(pkg_downloaded);
    free(pack);
    free(pkg);
    
    return OK;
}
