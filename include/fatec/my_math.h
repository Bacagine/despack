/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2020
 * 
 * my_math.h: Biblioteca criada pelos alunos de ADSM
 * contendo o prototipo de funções usadas para calculos
 * matematicos
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
 * Versão: 20.07.20
 * 
 * Desenvolvedor: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 * 
 * Data de ínicio: 20/07/2020
 * Data da última modificação: 20/07/2020
 */

#ifndef _MY_MATH_H
#define _MY_MATH_H

#include <math.h>

#define PI 3.1415

/* Função criada por Gustavo Bacagine.
 *
 * Essa função soma dois numeros inteiros */
int soma(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função subtração dois numeros inteiros */
int subtracao(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros inteiros */
int multiplicacao(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função divide dois numeros inteiros */
int divisao(int n1, int n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função soma dois numeros do tipo ponto flutuante */
int fsoma(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função subtração dois numeros numeros do tipo ponto flutuante */
int fsubtracao(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros numeros do tipo ponto flutuante */
int fmultiplicacao(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função divide dois numeros numeros do tipo ponto flutuante */
int fdivisao(float n1, float n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função soma dois numeros do tipo double */
int dsoma(double n1, double n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função subtração dois numeros numeros do tipo double */
int dsubtracao(double n1, double n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função multiplicação dois numeros numeros do tipo double */
int dmultiplicacao(double n1, double n2);

/* Função criada por Gustavo Bacagine.
 *
 * Essa função divide dois numeros numeros do tipo double */
int ddivisao(double n1, double n2);

/* Função criada por Gustavo Bacagine.
 * 
 * Essa função faz um calculo de um número fatorial
 * de maneira recursiva */
long long int fatorial(int n);

/* Essa função foi criada por Herbert Schildt
 * Pegamos ela de seu livro "C Completo e Total"
 * 
 * Essa função funciona semelhante à função pow
 * calculando o expoente (e) de um número (n) */
int my_pow(int n, int e);

/* Função criada por Gustavo Bacagine
 * 
 * Essa função transforma um número
 * binario em decimal */
int bin2dec(const int bin);

/* Função criada por Gustavo Bacagine
 * 
 * Essa função transforma um número
 * decimal em binario */
int dec2bin(const int dec);

/* Função criada por Gustavo Bacagine
 * 
 * Calcula a area de uma esfera */
int area(int raio);

/* Função criada por Gustavo Bacagine
 * 
 * Calcula o volume de uma esfera */
int volume_esfera(int raio);

// Lista 5 Ponteiros 2019 2º Semestre

/* Função criada por Gustavo Bacagine e José Eduardo.
 *
 * Essa função transforma o tempo digitado pelo usuario em
 * segundos para o formato 00h:00min:00s */
void transforma_segundos(int, int *, int *, int *);

/* Função criada por Gustavo Bacagine e José Eduardo.
 *
 * Essa função calcula o diâmetro, perímetro e área de uma 
 * circunferência. */
void circunferencia(float, float *,float *,float *);

/* Função criada por Gustavo Bacagine e José Eduardo.
 *
 * Essa função recebe como parâmetro uma distância 
 * em metros a devolve, também através de seus parâmetros,
 * essa distância em polegadas, jardas e milhas. */
void converte(float, double *, double *, double *);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe o tamanho de um arquivo em bytes e devolve 
 * o tamanho desse arquivo em KB e MB. */
void file_size(int, float *, float *);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função pega uma sequência de n 
 * números inteiros e os imprime em ordem
 * inversa. */
//void inverse_num(int *nums);

#endif
