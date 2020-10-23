/* Date of begin: 22/07/2020
 * Date of last modification: 23/10/2020 */

#include <string.h>
#include <fatec/fatec.h>
#include "../include/package.h"

void install_process(const char *pkg_name){
    package *pkg = (package *) malloc(sizeof(package));
    
    /* For example: pack = hello.tar.xz
     * pkg_downloaded = /usr/share/despack/hello.tar.xz
     * pkg_despack = hello
     * pkg_src = /usr/src/hello */
    char *pack = (char *) malloc(sizeof(char) * 26);
    char *pkg_downloaded = (char *) malloc(sizeof(char) * 45);
    char *pkg_despack = (char *) malloc(sizeof(char) * 19);
    char *pkg_src = (char *) malloc(sizeof(char) * 28);
    
    int day, month, year, hour, minute, second;
    
    /* Salvando o nome do pacote
     * para poder usá-lo no cadastro */
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
    
    /* Descompacta o pacote para o
     * diretorio de compilação */
    descompactar(pkg_name, pkg_src);
    
    /* Compile and install
     * the package */
    compile(pkg_src);
    
    get_date_time(&day, &month, &year, &hour, &minute, &second);
    
    pkg->dt_instalacao.day = day;
    pkg->dt_instalacao.month = month;
    pkg->dt_instalacao.year = year;
    pkg->tm_instalacao.hour = hour;
    pkg->tm_instalacao.minute = minute;
    pkg->tm_instalacao.second = second;
    
    /* If the package was installed realiza
     * the cadastro of package na lista de
     * pacotes instalados */
    if(verifica_instalacao(pkg->name)){
        cadastrar_pacote(pkg);
    }
    else{
        fprintf(stderr, "Error: Nao foi possivel instalar o programa: %s!\n", pkg->name);
        return;
    }
    
    free(pkg_src);
    free(pkg_despack);
    free(pkg_downloaded);
    free(pack);
    free(pkg);
}
