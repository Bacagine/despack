/* GitHub: 
 * 
 * Copyright (C) 2020
 * 
 * register_package.c: 
 * 
 * Developed by Gustavo Bacagine <gustavo.bacagine@gmail.com>
 * 
 * Date of begin: 22/07/2020
 * Date of last modification: 26/10/2020 */

#include <fatec/fatec.h>
#include "../include/package.h"

int register_package(package *pkg){
    /* List with the packages
     * installed on system */
    FILE *installed_list;
    
    /* Verify if the list of installed packages exist on user's system */
    if((installed_list = fopen(PKG_INSTALLED_LIST, "ab")) == NULL){
        fprintf(stderr, "Error: %s no such file or directory!\n", PKG_INSTALLED_LIST);
        return FILE_ERR;
    }
    
    /* Move the cursor to the eof */
    fseek(installed_list, sizeof(package), SEEK_END);
    
    /* Write packeage on list */
    fwrite(pkg, sizeof(package), 1, installed_list);
    
    return OK;
}
