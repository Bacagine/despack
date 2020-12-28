/* GitHub: https://github.com/Bacagine/despack/src/main.c
 * 
 * Copyright (C) 2020
 * 
 * main.c: Main file of despack package manager
 * 
 * Developed by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * Begin's date: 20/07/2020
 * Date of last modification: 30/10/2020
 */

#include <stdio.h>
#include <string.h>
//#include <fatec/fatec.h>
#include "../include/package.h"

int main(int argc, char **argv){
    if(argc == 1){
        fprintf(stderr, "Error: You don't pass arguments!\nUse: %s [options] <package_name>\n", NAME);
        return ARG_ERR;
    }
    else if(argc == 2){
        if(!strcmp(argv[1], "update")){
            update();
        }
        else if(!strcmp(argv[1], "upgrade")){
            full_upgrade();
        }
        else if(!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")){
            puts(VERSION);
        }
        else if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
            puts(VERSION);
            puts(HELP);
        }/*
        else if(!strcmp(argv[1], "-dev") || !strcmp(argv[1], "--developers")){
            // Nome dos desenvolvedores
            const char devs[2][51] = { "Gustavo Samuel Bacagine Azevedo", "Lucas Pereira de Matos" };

            // Email dos desenvolvedores
            const char emails[2][51] = { "gustavo.bacagine@protonmail.com", "lucas.pereira.matos.000@gmail.com" };
            developers(2, devs, emails, dev_year, dev_university, dev_city, DESCRIPTION);
        }*/
    }
    else if(argc == 3){
        /* Install the package on system */
        if(!strcmp(argv[1], "-i") || !strcmp(argv[1], "install")){
            //install(argv[3]);
        }
        else if(!strcmp(argv[1], "install-src")){
            install_process(argv[2]);
        }
        /* Remove the package of system */
        else if(!strcmp(argv[1], "-r") || !strcmp(argv[1], "remove")){
            //uninstall(argv[2]);
        }
        /* Upgrade a package */
        else if(!strcmp(argv[1], "upgrade")){
            upgrade(argv[2]);
        }
        /* Unpack the package on diretorio atual */
        else if(!strcmp(argv[1], "-x") || !strcmp(argv[1], "--extract")){
            char *dest = (char *) malloc(sizeof(char));
            
            /* Verify if memory allocation is possible */
            if(dest == NULL){
                fprintf(stderr, NO_MEMORY);
                return MEM_ERR;
            }
            
            unpack(argv[2], dest);
            
            free(dest);
			dest = NULL;
        }
        /* Download of package on directory /usr/share/despack/packages */
        else if(!strcmp(argv[1], "download")){
            /* Alloc space in memory */
            char *pack = (char *) malloc(sizeof(char) * 26);
            char *pkg_downloaded = (char *) malloc(sizeof(char) * 45);
            char *pkg_despack = (char *) malloc(sizeof(char) * 19);
            
            /* Verify if memory allocation is possible */
            if(pack == NULL || pkg_downloaded == NULL || pkg_despack == NULL){
                fprintf(stderr, NO_MEMORY);
                return MEM_ERR;
            }
            
            download(argv[2], pack, pkg_downloaded, pkg_despack);
                
            /* Free memory
             * allocated */
            free(pack);
            free(pkg_downloaded);
            free(pkg_despack);

			pack = NULL;
			pgk_downloaded = NULL;
			pkg_despack = NULL;
        }
    }
    else if(argc == 4){
        /* Create a package */
        if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "--compress")){
            //compress(argv[2], argv[3]);
        }
        else if(!strcmp(argv[1], "download")){
            char *pack = (char *) malloc(sizeof(char) * 26);
            char *pkg_downloaded = (char *) malloc(sizeof(char) * 45);
            
            /* Verify if memory allocation is possible */
            if(pack == NULL || pkg_downloaded == NULL){
                fprintf(stderr, NO_MEMORY);
                return MEM_ERR;
            }
            
            download(argv[2], pack, pkg_downloaded, argv[3]);
            
            /* Free the memory
             * space that was
             * allocated */
            free(pack);
            free(pkg_downloaded);
        }
    }
    else{
        fprintf(stderr, "Error: Ivalid arguments!");
        return ARG_ERR;
    }
    return EXIT_SUCCESS;
}
