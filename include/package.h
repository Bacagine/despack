/* GitHub: https://github.com/Bacagine/pkg_manager/
 * 
 * package.h: Library with functions useds
 * in package managment
 * 
 * Developers: Gustavo Bacagine       <gustavo.bacagine@protnomail.com>
 *             Lucas Pereira de Matos <lucas.pereira.matos.000@gmail.com>
 * 
 * Begin's date: 20/07/2020
 * Date of last modification: 23/10/2020
 */

#ifndef _PACKAGE_H
#define _PACKAGE_H

#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>
//#include <libtar.h>
#include <fatec/date.h>

/* Name of package manager */
#define NAME       "despack"

/* Version of package manager */
#define VERSION    "despack 20.10.23"

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
  search  - search package\n\
\n\
See despack man pages for more information about the commands.\n"

#define DESCRIPTION "despack is a commandline package maneger created by\n\
students of FATEC Caraicuíba.\n"

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
#define repository "https://www.despack.github.io/packages/"

/* Link onde se encontra a
 * lista de pacotes existentes
 * no repositorio */
#define pkg_list_url "https://www.despack.github.io/packages/despack.list"

/* Ano da última modificação */
#define dev_year 2020

/* Cidade da faculdade */
#define dev_city "Carapicuíba"

/* Nome da faculdade */
#define dev_university "FATEC"

/* Structure that represent
 * a instalation time of package */
typedef struct{
    int hour;
    int minute;
    int second;
} time_i;

/* Structure that represent
 * a package */
typedef struct{
    char name[51];
    double memory;
    date dt_instalacao;
    time_i tm_instalacao;
} package;

/* Processo de instalação do pacote
 * 
 * Recebe o nome do pacote como parametro */
void install_process(const char *pkg_name);

/* Faz download do pacote
 * 
 * Recebe o nome do pacote como 1º argumento,
 * o pacote como 2º argumento e o pacote salvo,
 * como 3º argumento o pacote no local de download
 * e como 4º argumento o pacote descompactado no
 * local para compilação */
int download(const char *pkg_name, char *pkg, char *pkg_downloaded, char *pkg_despack);

/* Descompacta um pacote
 * 
 * Recebe o pacote como 1º argumento e o 
 * local para a descompactação como 2º argumento */
void descompactar(const char *pkg_downloaded, const char *pkg_despack);

/* Faz a compilação
 * do pacote */
void compile(char *pkg_src);

/* Verifica se o pacote foi
 * instalado com sucesso.
 * Em caso positivo retorna 0,
 * em caso negativo retorna 1 */
int verifica_instalacao(const char *pkg_name);

/* Cadastra o pacote instalado no
 * arquivo em /usr/share/pkgs.dat */
void cadastrar_pacote(package *pkg);

/* Lista os pacotes instalados
 * no sistema */
void listar_pacotes(void);

/* Instala o pacote no sistema
 * 
 * Recebe como 1º argumento o nome do pacote e
 * o destino como 2º argumento */
void install(const char *pkg_name, const char *pkg_despack);

/* Desinstala o pacote do sistema
 * 
 * Recebe o nome do pacote como
 * argumento */
void uninstall(const char *pkg_name);

/* Atualiza a lista 
 * de pacotes */
void update(void);

/* Pesquisa se um determinado pacote
 * existe no repositorio
 * 
 * Recebe o nome do pacote a ser pesquisado
 * como parametro */
void search(const char *pkg_name);

/* Cria um pacote atraves de um diretorio
 * 
 * Recebe como 1º argumento o nome do diretorio e 
 * o nome do pacote como 2º argumento */
void compactar(const char *folder, char *pkg);

/* We took this function in: https://code-examples.net/en/q/18f7ed */
size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream);

/* Get the day and the hour in that the package
 * was installed */
void get_date_time(int *day, int *month,
                   int *year, int *hour,
                   int *minute, int *second);

/* Verifica a extensão de um pacote
 * passado como parametro
 * 
 * Retorna -1 se o pacote for tar.bz2,
 * retorna 0 se o pacote for tar.xz,
 * ou retorna 1 se o pacote for tar.gz */
int verifica_pacote(const char *pkg);

#endif
