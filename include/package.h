/* GitHub: https://github.com/Bacagine/despack/
 * 
 * Copyright: (C) 2020
 * 
 * package.h: Library with functions that were useds in package managment
 * 
 * Developers: Gustavo Bacagine       <gustavo.bacagine@protnomail.com>
 *             Lucas Pereira de Matos <lucas.pereira.matos.000@gmail.com>
 * 
 * Begin's date: 20/07/2020
 * Date of last modification: 28/12/2020
 */

#ifndef _PACKAGE_H
#define _PACKAGE_H

#include <stdlib.h>
//#include <arpa/inet.h>
#include <curl/curl.h>
//#include <libtar.h>
//#include <fatec/date.h>

/* Name of package manager */
#define NAME       "despack"

/* Version of package manager */
#define VERSION    "despack 20.12.28"

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

/* Description of the software */
#define DESCRIPTION "despack is a commandline package maneger created by\n\
students of FATEC Caraicuíba.\n"

/* File containing the packages list on the
 * repository */
#define PKG_LIST     "/usr/share/despack/despack.list"

/* File containing a old packages list on the
 * repository */
#define PKG_LIST_OLD "/usr/share/despack/despack.list.old"

/* File where it will be listed the 
 * packages installed in system */
#define PKG_INSTALLED_LIST   "/usr/share/despack/pkgs.dat"

/* Directory where it will be salved 
 * the packages */
#define PKG_FOLDER "/usr/share/despack/packages/"

/* Man page of package manager */
#define PKG_MAN    "/usr/share/man/man8/despack.8.gz"

/* Directory where the package will
 * be unpacked for compilation */
#define PKG_SRC    "/usr/src/"

/* Directory where the binary
 * package is installed */
#define BIN_DIR    "/usr/bin"

/* Packages repository */
#define repository "https://www.despack.github.io/packages/"

/* Link where is the list of existing
 * packages on repository */
#define pkg_list_url "https://www.despack.github.io/packages/despack.list"

/* Year of last software
 * modification */
#define dev_year 2020

/* City of college */
#define dev_city "Carapicuíba"

/* College name */
#define dev_university "FATEC"

/* Error message when the memory
 * is insuffitient */
#define NO_MEMORY "Error: Not enough memory to carry out the allocation!\n"

/*
 * RETURN VALUES
 * --------------
 * Installed package     2 -> The package is installed on system with sucess
 * 
 * Files
 * ---------
 * is a zip file         3 -> zip     package
 * is a tar.gz file      4 -> tar.gz  package
 * is a tar.xz file      5 -> tar.xz  package
 * is a tar.bz2 file     6 -> tar.bz2 package
 * 
 * Erros values
 * ------------
 * Arguments error      22 -> User pass invalid parameters or don't pass parameters
 * File error           25 -> No such file
 * No package           35 -> Package not found
 * Memory error        525 -> When not enough memory to carry out the memory allocation
 */
enum RETURN_VALUES{ INSTALLED_PKG = 2, IS_ZIP, IS_TAR_GZ,
                    IS_TAR_XZ, IS_TAR_BZ, ARG_ERR = 22,
                    FILE_ERR = 25, NO_PACK = 35, MEM_ERR = 525 };

/* Structure that represent
 * a date of package's instalation*/
typedef struct{
    int day;
    int month;
    int year;
} date;
                    
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
    //double memory;
    char memory[7];
    date dt_instalacao;
    time_i tm_instalacao;
} package;

/* Package install process
 * 
 * Receive the package name as parameter */
int install_process(const char *pkg_name);

/* Download of package
 * 
 * Receive the name of the package as the 1º parameter,
 * The saved package is used as the 2º parameter,
 * The package in the directory that the download
 * will be is the 3º parameter,
 * And as the 4º parameter is the package unpacked in
 * the directory for compilation */
int download(const char *pkg_name, char *pack, char *pkg_downloaded, char *pkg_despack);

/* Unpack a package
 * 
 * Receive the package as 1º parameter and the 
 * local to unpack as 2º parameter */
int unpack(const char *pkg_downloaded, const char *pkg_despack);

/* Compile and install a package */
int compile(char *pkg_src);

/* Verify if the package was
 * installed with sucess.
 * 
 * In positive case return 0,
 * in negative case return 1 */
int verify_instalation(const char *pkg_name);

/* Register the installed package on
 * archvie in /usr/share/pkgs.dat */
int register_package(package *pkg);

/* List the installed packages
 * on system */
int list_packages(void);

/* Install a package on system
 * 
 * Receive as 1º parameter the name of package and
 * the destiny as 2º parameter */
int install(const char *pkg_name, const char *pkg_despack);

/* Uninstall the package of system
 * 
 * Receive the package name as a
 * parameter */
int uninstall(const char *pkg_name);

/* Update the package
 * list */
void update(void);

/* Search if a determite package
 * exist on repository
 * 
 * Gets the name of the package to be searched
 * as parameter */
int search(const char *pkg_name);

/* Create a package atraves of directory
 * 
 * Receive as 1st parameter the directory name and 
 * the name of package as 2nd parameter */
int compress(const char *folder, char *pack);

/* We took this function in: https://code-examples.net/en/q/18f7ed */
size_t write_data(void *ptr, size_t size, size_t nmeb, FILE *stream);

/* Get the date and the hour in that the package
 * was installed */
void get_date_time(int *day, int *month,
                   int *year, int *hour,
                   int *minute, int *second);

/* Verify the package extension
 * passed with parameter
 * 
 * Return IS_TAR_BZ if the package is .tar.bz2,
 * return IS_TAR_XZ if the package is .tar.xz,
 * return IS_TAR_GZ if the package is .tar.gz
 * or return IS_ZIP if the package is .zip */
int verify_package(const char *pack);

/* Upgrade one package passed
 * with parameter */
int upgrade(const char *pkg_name);

/* Upgrade all packages */
int full_upgrade(void);

#endif
