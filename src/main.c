/* Main file of package manager 
 * 
 * Begin's date: 07/20/2020
 * Date of last modification: 08/12/2020
 */

#include <stdio.h>
#include <fatec/fatec.h>
#include "../include/package.h"

int main(int argc, char **argv){
    if(argc == 1){
        fprintf(stderr, "Error: You don't pass arguments!\nUse: %s [OPTIONS] [NAME_PACKAGE]\n", argv[0]);
        return 1;
    }
    else{
        if(argc == 2){
            if(!strcmp(argv[1], "update")){
                update();
            }
            else if(!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")){
                print(VERSION);
            }
            else if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")){
                print(VERSION);
                print(HELP);
            }
            else if(!strcmp(argv[1], "-dev") || !strcmp(argv[1], "--developers")){
                developers(2, devs, emails, dev_year, dev_university, dev_city, DESCRIPTION);
            }
        }
        else if(argc == 3){
            /* Instala o pacote no sistema */
            if(!strcmp(argv[1], "-i") || !strcmp(argv[1], "install")){
                install_process(argv[2]);
            }
            /* Remove o pacote do sistema */
            else if(!strcmp(argv[1], "-r") || !strcmp(argv[1], "remove")){
                uninstall(argv[2]);
            }
            /* Atualiza um pacote */
            else if(!strcmp(argv[1], "upgrade")){
                uninstall(argv[2]);
                install(repository, argv[2]);
            }
            /* Descompacta o pacote no diretorio atual */
            else if(!strcmp(argv[1], "-x") || !strcmp(argv[1], "--extract")){
                char dest;
                descompactar(argv[2], &dest);
            }
            /* Faz download do pacote no diretorio /usr/share/despack/packages */
            else if(!strcmp(argv[1], "download")){
                char pack[26], pkg_downloaded[45], pkg_despack[19];
                download(argv[2], pack, pkg_downloaded, pkg_despack);
            }
        }
        else if(argc == 4){
            /* Cria um pacote */
            if(!strcmp(argv[1], "-c") || !strcmp(argv[1], "--compact")){
                compactar(argv[2], argv[3]);
            }
            else if(!strcmp(argv[1], "download")){
                char pack[26], pkg_downloaded[45];
                download(argv[2], pack, pkg_downloaded, argv[3]);
            }
        }
        else{
            fprint(stderr, "Error: Ivalid arguments!");
            return 1;
        }
    }
    return 0;
}
