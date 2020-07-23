/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2020
 * 
 * fatec.h: Biblioteca criada pelos alunos de ADSM
 * contendo o prototipo das funções e estruturas que
 * foram usadas no primeiro ano do curso
 * 
 * fatec.h é um software livre; você pode redistribui-lo e/ou
 * modificalo sob os termos da Licença GNU Lesser General Public
 * publicada pela Free Software Foundation; ou
 * versão 2 da licença ou (a seu critério) qualquer versão posterior.
 * 
 * Você deve ter recebido uma copia da Licença GNU Lesser General Public
 * junto com o fatec.h; case contrario, veja:
 * <http://www.gnu.org/licenses/>.
 * 
 * Versão: 20.06.15
 * 
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 *                  José Eduardo              <joseeduardoolimpio@gmail.com>
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>
 *                  Caio Elias Emerick Regino <caioregino.147@gmail.com>
 *                  Luiz Dionizio             <luizgdsoares@hotmail.com>
 *                  Profº Ciro Cirne Trindade <ciroct@gmail.com>
 * 
 * Data de início: 02/12/2019
 * Data da última modificação: 08/07/2020 */

// Evita que a biblioteca seja incluida inumeras vezes
#ifndef _FATEC_H
#define _FATEC_H

#include <stdio.h>
#include <locale.h>    /* Biblioteca para poder usar a função setlocale 
                        * usada para colocar acentuação nas palavras */
#include <string.h>
#include <math.h>    // Biblioteca para usar funções matematicas
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Verifica se o sistema é do tipo unix like
#ifdef __unix__
	#define UNIX
    #include <stdlib.h> // Biblioteca usada para ultilizar comandos do Sistema Operacional
    #define clear_terminal() system("clear");
	#define stay() printf("\nPress enter to continue..."); getchar();
// Verificar se o sistema é Windows ou se o programa foi compilado para Windows
#elif defined(_WIN32) || defined(WIN32) || defined(__MINGW32__) || defined(_MCS_VER)
	#define WIN
    #include <stdlib.h>
    #define clear_terminal() system("cls");
#endif // __unix__

// Definições por Gustavo Bacagine

#define __FATEC_VERSION__ "20.07.01"

/* Mensagem de erro caso 
 * o usuario digite uma 
 * opção inválida */
#define ERROR "ERROR: Invalid option!"

/* A seguir as funções mais usadas pelos alunos 
 * de ADSM da FATEC de Carapicuíba */

/* Função usada para evitar 
 * Buffer Overflow
 * 
 * Você pode se perguntar o motivo
 * para se usar uma função propia para
 * limpar o buffer do terminal ao invés
 * de usar uma função já pronta encontrada
 * na propia linguagem
 * 
 * Existem muitas funções que poderiamos
 * usar como: fflush(), setbuf(), etc...
 * 
 * O motivo para usarmos essa função está
 * no fato de que as funções listadas acima
 * não funcionam em todos os Sistemas Operacionais.
 * O fflush() funciona no Windows mas não funciona no
 * Linux e no MasOS; já o setbuf() funciona tanto no
 * Linux como no Windows, porém não funciona no MasOS.
 * 
 * Está função que usamos funciona em todos os
 * Sistemas Operacionais. Por isso achamos que essa seja
 * a melhor opção a ser usada.
 * 
 * OBS: Essa função não foi 
 * desenvolvida por nós. Percebemos 
 * que muitos programadores 
 * se utilizam dessa função e 
 * passamos a usa-lá em nossos programas */
void clear_buffer(void);

/* Função cirada pelo professor Ciro Cirne Trindade
 * 
 * Outra maneira de limpar o buffer
 * do terminal. */
void buffer_clean(void);

/* Função criada por 
 * Gustavo Bacagine
 * 
 * Ela printa um menu no terminal
 * Foi feita como um exemplo apenas pois,
 * o menu normalmente fica na função main.
 * Você pode usa-lá para criar seus propios menus*/
void menu(void);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função receba uma string de 0s e 1s, interprete
 * essa string como um número binário e 
 * informe o valor desse número na base decimal. */
//void binario_decimal(void);


/* Essa função foi criada por Herbert Schildt
 * Pegamos ela de seu livro "C Completo e Total"
 * e fizemos uma adaptação para que ela pule uma
 * linha no final da string.
 * 
 * Essa função funciona semelhante à puts
 * printando uma string na saída do terminal. */
void print(char *s);

/* Função criada por Gustavo Bacagine
 * 
 * Ela exibe o conteudo de um
 * arquivo */
int cat(const char *file);

/* Função Criada por Gustavo Bacagine
 * 
 * Ela exibe as 10 primeiras linhas
 * de um arquivo */
int head(const char *file);

/* Função criada por Gustavo Bacagine
 * 
 * Ela copia o conteudo de um arquivo
 * para outro */
int cp(const char *ori, const char *dest);

/* Função criada por Gustavo Bacagine
 * 
 * Ela limpa o terminal (semelhante ao comando
 * clear do linux) */
void clear(void);

/* Função criada por Gustavo Bacagine
 * 
 * Ela cria um diretorio com a permissão escolhida
 * pelo desenvolvedor.
 * Recebe como 1º argumento o nome do diretorio e
 * como 2º argumento o número da permissão */
void mkfolder(const char *folder, int permission);

/* Função criada por Gustavo Bacagine
 * 
 * Ela busca uma palavra em um arquivo
 * Recebe como 1º argumento a palavra a ser
 * procurada e como 2º o arquivo onde será
 * procurada. */
int grep(const char *word, const char *file);

/* Função criada por Gustavo Bacagine
 * 
 * Ela move um arquivo para outro lugar, ela
 * pode ser usada também para renomear arquivos.
 * Recebe como 1º argumento o nome do arquivo
 * e como 2º o destino para onde ele deve ser 
 * movido. */
void mv(const char *ori, const char *dest);

/* Função criada por Gustavo Bacagine
 * 
 * Remove um ou mais arquivos e diretorios
 * vazios */
void rm(const char *arqs);

/* Função criada por Gustavo Bacagine
 * 
 * Ela inverte os valores de x e y */
void swap(int *x, int *y);

/* Função criada por Gustavo Bacagine
 * 
 * Armazena o valor de uma string em
 * uma variaves */
//char *rstr(char *str, char *var);

/* Função criada por 
 * Gustavo Bacagine
 * 
 * Ela é usada para mostrar
 * os desenvolvedores da 
 * aplicação */
void developers(int qtd, const char **names, 
                const char **emails, int year, 
                const char *university, const char *city, 
                const char *desc);

#endif // _FATEC_H
