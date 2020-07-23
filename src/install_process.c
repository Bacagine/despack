/* Date of begin: 22/07/2020 */

#include "../include/fatec/fatec.h"
#include "../include/package.h"

void install_process(const char *pkg_name){
    package pkg;
    /* For example: pack = hello.tar.xz
     * and pkg_folder = /usr/share/despack/hello.tar.xz */
    char pack, pkg_downloaded;
    
    /* Salvando o nome do pacote
     * para poder usá-lo no cadastro */
    strcpy(pkg.name, pkg_name);

/*  Aqui precisamos encontrar uma maneira
    de descobrir a data atual no sistema do
    usuario e salvar dentro da estrutura
    pkg.dt_instalacao.dia = ;
    pkg.dt_instalacao.mes = ;
    pkg.dt_instalacao.ano = ; */
    
/*  Aqui precisamos descobrir a
    memoria do pacote e salvar
    na estrutura
    pkg.memory = ; */
    
    download(pkg_name, &pack, &pkg_downloaded);
    descompactar(pkg_name, PKG_SRC);
    compile();
//    install(pkg_name, );
    cadastrar_pacote(pkg);
}
