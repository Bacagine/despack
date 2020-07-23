/**********************************************************************************
 * Git Hub: https://github.com/Bacagine/fatec                                     *
 *                                                                                *
 * Copyright (C) 2019 - 2020                                                      *
 *                                                                                *
 * fatec.c: Arquivo com o desenvolvimento do prototipo das funções da biblioteca  *
 * fatec.h                                                                        *
 *                                                                                *
 * fatec.c é um software livre; você pode redistribui-lo e/ou modificalo sob os   *
 * termos da Licença GNU Lesser General Public publicada pela Free Software       *
 * Foundation; ou versão 2 da licença ou (a seu critério) qualquer                *
 * versão posterior.                                                              *
 *                                                                                *
 * Você deve ter recebido uma copia da Licença GNU Lesser General Public junto    *
 * com o fatec.c; caso contrario, veja: <http://www.gnu.org/licenses/>.           *
 *                                                                                *
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>   *
 *                  José Eduardo              <joseeduardoolimpio@gmail.com>      *
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com> *
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>          *
 *                  Luiz Dionizio             <luizgdsoares@hotmail.com>          *
 *                  Profº Ciro Cirne Trindade <ciroct@gmail.com>                  *
 *                                                                                *
 * Data: 02/12/2019                                                               *
 * Data da última modificação: 21/07/2020                                         *
 **********************************************************************************/

#include <stdio.h>
#include "../include/fatec/fatec.h"

void clear_buffer(void){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

void buffer_clean(void){
    while(getchar() != '\n');
}

void print(char *s){
    while(*s++){
        putchar(*s);
    }
    putchar('\n');
}

int cat(const char* file){
    FILE *arq;
	char line[100000];
	//for(int i = 0; i < qtd; i++){
	arq = fopen(file, "r");
	//}
	if(arq == NULL){
		fprintf(stderr, "Erro ao ler o arquivo %s\n", file);
		return 1;
	}
	//for(int count = 0; count < qtd; count++){
		while(fgets(line, 100000, arq) != NULL){
			fputs(line, stdout);
		}
	//}
	fclose(arq);
    return 0;
}

int head(const char* file){
    FILE *arq;
	//for(int i = 0; i < qtd; i++){
	//}
	arq = fopen(file, "r");
	if(arq == NULL){
		fprintf(stderr, "Erro ao ler o arquivo %s\n", file);
		return 1;
	}
	int count = 0;
	char line[100000];
	//for(int count = 0; count < qtd; count++){
		while(fgets(line, 100000, arq) && count != 10){
			fputs(line, stdout);
            count++;
		}
	//}
	fclose(arq);
    return 0;
}

int cp(const char* ori, const char* dest){
    FILE *arq_ori, *arq_dest;
	arq_ori = fopen(ori, "r");
	if(arq_ori == NULL){
		fprintf(stderr, "Erro: Não foi possivel encontrar o arquivo %s", ori);
		return 1;
	}
	
	char line[100000];
	arq_dest = fopen(ori, "w");
	
	while(fgets(line, 100000, arq_ori) != NULL){
		fputs(line, arq_dest);
	}

	fclose(arq_ori);
	fclose(arq_dest);
    
    return 0;
}

void clear(void){
    #ifdef UNIX
		printf("\033\143");
	#elif defined(WIN)
		printf("\x0");
	#endif
}

void mkfolder(const char *folder, int permission){
    int a;
    #ifdef UNIX
        a = mkdir(folder, permission);
    #elif defined(WIN)
        a = _mkdir(folder, permission);
    #endif
}

int grep(const char *word, const char *file){
    FILE *arq;
    
    arq = fopen(file, "r");
    
    if(arq == NULL){
        fprintf(stderr, "Erro ao abrir o arquivo %s!\n", file);
        return 1;
    }
    
    char linha[100000];
    
    while(fgets(linha, 100000, arq) != NULL){
        if(strstr(word, linha)){
            fputs(linha, stdout);
        }
    }
    fclose(arq);
    return 0;
}

void mv(const char* ori, const char* dest){
    
}

void rm(const char* arqs){
    remove(arqs);
}

void swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}
/*
char *rstr(char *str, char *var){
    return str;
}
*/
void developers(int qtd, const char ** names,
                const char ** emails, int year,
                const char* university, const char* city,
                const char* desc){
    setlocale(LC_ALL, "");

    clear_terminal();
	if(qtd > 0 && qtd == 1){
		fprintf(stdout, "************************DESENVOLVEDOR*************************\n");
	}
	else{
		fprintf(stdout, "************************DESENVOLVEDORE(S)************************\n");
	}
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "* %s  -                %s            -         %d *\n", university, city, year);
    fprintf(stdout, "*---------------------------------------------------------------*\n");
    fprintf(stdout, "*                                                               *\n");
	for(int count = 0, count < qtd; count++){
    	fprintf(stdout, "* %s          <%s>   *\n", names[count], emails[count]);
	}
    fprintf(stdout, "*                                                               *\n");
	fprintf(stdout, "* %s *", desc);
	/*
    fprintf(stdout, "* fatec.h é uma Biblioteca criada pelos alunos de ADSM contendo *\n");
    fprintf(stdout, "* o prototipo das funções e estruturas que foram usadas no      *\n");
    fprintf(stdout, "* primeiro ano do curso                                         *\n"); */
    fprintf(stdout, "*                                                               *\n");
    fprintf(stdout, "*****************************************************************\n");
    
    stay(); /* Simula o system("pause") do windows */
}

