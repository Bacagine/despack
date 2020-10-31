/* GitHub: https://github.com/Bacagine/despack/src/upgrade.c
 * 
 * Copyright (C) 2020
 * 
 * upgrade.c: Upgrade one package
 * 
 * Development by Gustavo Bcagine <gustavo.bacagine@protonmail.com>
 * 
 * Begin's date: 24/10/2020
 * Date of last modification: 30/10/2020
 */

#include <stdio.h>
#include "../include/package.h"

int upgrade(const char *pkg_name){
    /* Remove old package */
    uninstall(pkg_name);
    /* Installing the new package */
    install(repository, pkg_name);
    return EXIT_SUCCESS;
}
