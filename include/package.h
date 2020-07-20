/* GitHub: https://github.com/Bacagine/pkg_manager/
 * 
 * package.h: Biblioteca com as funções usadas
 * no gerenciamento de pacotes
 * 
 * Developers: Gustavo Bacagine       <gustavo.bacagine@protnomail.com>
 *             Lucas Pereira de Matos <lucas.pereira.matos.000@gmail.com>
 * 
 * Date of begin: 20/07/2020
 * Date of last modification: 20/07/2020
 */

#ifndef _PACKAGE_H
#define _PACKAGE_H

#include <curl/curl.h>
/* Library created by fatec students */
#include "../include/fatec/data.h"

/* Name of package manager */
#define NAME       "despack"

/* Version of package manager */
#define VERSION    "despack 20.07.20"

/* Message for help user */
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
#define PKG_LIST "/usr/share/despack/despack.list/"

/* Archive where it will be listed the 
 * packages installed in sistem */
#define PKG_INSTALLED_LIST   "/usr/share/despack/pkgs.dat"

/* Directory where it will be salved 
 * the packages */
#define PKG_FOLDER "/var/cache/despack/"

/* Man page of package manager */
#define PKG_MAN    "/usr/share/man/man8/despack.8.gz"

/* Repositorios dos pacotes */
//const char *repository = { "https://www.github.com/Bacagine/pkg_manager/" };

/* Structure that represent
 * a package */
typedef struct{
    char name[51];
    date dt_instalacao;
    double memoria;
} package;

/* Faz download do pacote
 * 
 * Recebe o link do pacote como 1º argumento
 * e recebe o nome do pacote como 2º argumento */
int download(const char *pkg);

/* Descompacta um pacote
 * 
 * Recebe o nome do pacote como argumento */
void descompactar(const char *pkg);

/* Faz a compilação
 * do pacote */
void compile(void);

/* Instala o pacote no sistema
 * 
 * Recebe como 1º argumento o nome do pacote e
 * o destino como 2º argumento */
void install(const char *pkg, const char *dest);

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
void uninstall(const char *pkg);

/* Atualiza a lista 
 * de pacotes */
void update(void);

/* Cria um pacote atraves de um diretorio
 * 
 * Recebe como 1º argumento o nome do diretorio e 
 * o nome do pacote como 2º argumento */
void compactar(const char *folder, const char *pkg);

/*  */
size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream);

#endif