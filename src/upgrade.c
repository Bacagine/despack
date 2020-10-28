/* GitHub: 
 * 
 * Copyright (C) 2020
 * 
 * upgrade.c: Upgrade one package
 * 
 * Development by Gustavo Bcagine <gustavo.bacagine@protonmail.com>
 * 
 * Begin's date: 24/10/2020
 * Date of last modification: 26/10/2020
 */

#include <stdio.h>
#include "../include/package.h"

int upgrade(const char *pkg_name){
    uninstall(pkg_name);
    install(repository, pkg_name);
    return OK;
}
