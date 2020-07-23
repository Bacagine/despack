#include "../include/fatec/str.h"

char *strupper(char *str){
    for(int count = 0; str[count] != '\0'; count++){
        str[count] = toupper(str[count]);
    }
    return str;
}


char *strlower(char *str){
    for(int count = 0; str[count] != '\0'; count++){
        str[count] = tolower(str[count]);
    }
    return str;
}

void replace(char *str, int i, const char *newStr){
    
}

int palindromo(const char *str){
    for(int count = 0; str[count] != '\0'; count++){
        
    }
}

int count_str(const char *str){
    int count;
    for(count = 0; str[count] != '\0'; count++);
    return count;
}

void sswap(char *str1, char *str2){
    char aux;
    strcpy(&aux, str1);
    strcpy(str1, str2);
    strcpy(str2, &aux);
}
