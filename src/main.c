/* Arquivo principal do gerenciador de pacotes */

#include <stdio.h>
#include "../include/fatec/fatec.h"
#include "../include/package.h"

int main(int argc, char **argv){
    if(argc == 1){
        fprintf(stderr, "Error: You don't pass arguments!\nUse: %s [OPTIONS] [NAME_PACKAGE]", argv[0]);
        return 1;
    }
    else{
        if(argc == 2){
            if(!strcmp(argv[1], "update")){
                update();
            }
            else if(!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")){
                puts(VERSION);
            }
            else if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
                puts(VERSION);
                puts(HELP);
            }
        }
        else if(argc == 3){
            /* Instala o pacote no sistema */
            if(!strcmp(argv[1], "-i") || !strcmp(argv[1], "--install")){
                install_process(argv[2]);
             /* Colocar tudo isso dentro 
                da função chamada acima
                ------------------------
                package pkg;
                strcpy(pkg.name, argv[2]);
                pkg.dt_instalacao.dia = ;
                pkg.dt_instalacao.mes = ;
                pkg.dt_instalacao.ano = ;
                download(repository, argv[2]);
                descompactar(argv[2]);
                compile();
                install(argv[2], );
                cadastrar_pacote(); */
            }
            /* Remove o pacote do sistema */
            else if(!strcmp(argv[1], "-r") || !strcmp(argv[1], "--remove")){
                uninstall(argv[2]);
            }
            /* Atualiza um pacote */
            else if(!strcmp(argv[1], "upgrade")){
                uninstall(argv[2]);
                install(repository, argv[2]);
            }
            /* Descompacta o pacote no diretorio atual */
            else if(!strcmp(argv[1], "-x") || !strcmp(argv[1], "--extract")){
                descompactar(argv[2]);
            }
        }
        else if(argc == 4){
            /* Cria um pacote */
            if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "--compact")){
                compactar(argv[2], argv[3]);
            }
        }
        else{
            fprintf(stderr, "Error: Ivalid arguments!\n");
            return 1;
        }
    }
}
