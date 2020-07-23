/* GitHub: https://github.com/Bacagine/pkg_manager/
 * 
 * package.h: Biblioteca com as funções usadas
 * no gerenciamento de pacotes
 * 
 * Developers: Gustavo Bacagine       <gustavo.bacagine@protnomail.com>
 *             Lucas Pereira de Matos <lucas.pereira.matos.000@gmail.com>
 * 
 * Date of begin: 20/07/2020
 * Date of last modification: 22/07/2020
 */

#ifndef _PACKAGE_H
#define _PACKAGE_H

#include <curl/curl.h>
#include <time.h>

/* Library created by fatec students */
#include "../include/fatec/data.h"

/* Name of package manager */
#define NAME       "despack"

/* Version of package manager */
#define VERSION    "despack 20.07.22"

/* Message for help the user */
#define HELP       "Usage: despack [options] command\n\
\n\
despack is a commandline package maneger created by\n\
students of FATEC Caraicuíba.\n\
\n\
Commands:\n\
  update  - update package list\n\
  upgrade - upgrade pakcage\n\
  install - install package\n\
  remove  - uninstall package\n\
\n\
See despack man pages for more information about the commands.\n"

/* Archive containing a list of packages on the
 * repository */
#define PKG_LIST "/usr/share/despack/despack.list"

/* Archive where it will be listed the 
 * packages installed in sistem */
#define PKG_INSTALLED_LIST   "/usr/share/despack/pkgs.dat"

/* Directory where it will be salved 
 * the packages */
#define PKG_FOLDER "/usr/share/despack/packages/"

/* Man page of package manager */
#define PKG_MAN    "/usr/share/man/man8/despack.8.gz"

/* Diretorio onde será descompactado
 * o pacote para compilação */
#define PKG_SRC    "/usr/src/"

/* Repositorios dos pacotes */
const char *repository = { "https://www.despack.github.io/packages/" };

/* Link onde se encontra a
 * lista de pacotes existentes
 * no repositorio */
const char *pkg_list_url = { "https://www.despack.github.io/packages/despack.list" };

/* Structure that represent
 * a package */
typedef struct{
    char name[51];
    double memory;
    date dt_instalacao;
} package;

/* Faz download do pacote
 * 
 * Recebe o nome do pacote como 1º argumento,
 * o pacote como 2º argumento e o pacote salvo como 3º argumento */
int download(const char *pkg_name, char *pkg, char *pkg_downloaded);

/* Descompacta um pacote
 * 
 * Recebe o pacote como 1º argumento e o 
 * local para a descompactação como 2º argumento */
void descompactar(const char *pkg_downloaded, const char *dest);

/* Faz a compilação
 * do pacote */
void compile(void);

/* Instala o pacote no sistema
 * 
 * Recebe como 1º argumento o nome do pacote e
 * o destino como 2º argumento */
void install(const char *pkg_name, const char *dest);

/* Processo de instalação do pacote
 * 
 * Recebe o nome do pacote como parametro */
void install_process(const char *pkg_name);

/* Cadastra o pacote instalado no
 * arquivo em /usr/share/pkgs.dat */
void cadastrar_pacote(package pkg);

/* Lista os pacotes instalados
 * no sistema */
void listar_pacotes(void);

/* Desinstala o pacote do sistema
 * 
 * Recebe o nome do pacote como
 * argumento */
void uninstall(const char *pkg_name);

/* Atualiza a lista 
 * de pacotes */
void update(void);

/* Cria um pacote atraves de um diretorio
 * 
 * Recebe como 1º argumento o nome do diretorio e 
 * o nome do pacote como 2º argumento */
void compactar(const char *folder, const char *pkg);

/* Pegamos essa função neste link: https://code-examples.net/en/q/18f7ed */
size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream);

#endif
