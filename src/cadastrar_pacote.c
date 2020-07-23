/* Date of begin: 22/07/2020 */

#include "../include/fatec/fatec.h"
#include "../include/package.h"

void cadastrar_pacote(package pkg){
    /* Lista com os pacotes
     * instalados no sistema */
    FILE *installed_list;
    
    if((installed_list = fopen(PKG_INSTALLED_LIST, "ab")) == NULL){
        fprintf(stderr, "Error: %s no such file or directory!\n", PKG_INSTALLED_LIST);
        return;
    }
    
    fseek(installed_list, sizeof(package), SEEK_END);
    
    fwrite(&pkg, sizeof(package), 1, installed_list);    
}