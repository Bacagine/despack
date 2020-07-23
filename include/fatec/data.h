/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2020
 * 
 * data.h: Biblioteca criada pelos alunos de ADSM
 * contendo o prototipo de funções e estruturas usadas
 * para manipulação de datas
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
 * Versão: 21.07.20
 * 
 * Desenvolvedores: Gustavo Bacagine          <gustavo.bacagine@protonmail.com>
 *                  Lucas Pereira de Matos    <lucas.pereira.matos.000@gmail.com>
 * 
 * Data de ínicio: 20/07/2020
 * Data da última modificação: 21/07/2020
 */

#ifndef _DATA_H
#define _DATA_H

/* Biblioteca usada
 * para manipulação
 * de variaveis booleanas */
#include <stdbool.h>

/* Estrutura criada por Gustavo Bacagine
 * 
 * Ela representa uma data */
typedef struct{
    int dia;
    int mes;
    int ano;
} date;

/* Função criada por Gustavo Bacagine e
 * Lucas Pereira de Matos
 * 
 * Essa função que devolve um valor negativo
 * se a primeira data for menor que a segunda,
 * 0 se as duas datas são iguais, ou um valor
 * positivo se a primeira data for maior que 
 * a segunda */
int compara_datas(date , date );

/* Função criada por Gustavo Bacagine
 * 
 * Essa função compara se as duas datas
 * passadas pelo usuário são iguais ou
 * não. */
bool datas_iguais(date , date );

/*  */
int valida_mes(int mes);

/* Função criada por Gustavo Bacagine
 * 
 * Essa função faz uma listagem entre
 * o periodo das duas datas passadas
 * como argumentos. */
void listar_por_data(date , date);

/* Função criada pelo Profº Ciro Cirne Trindade.
 *
 * Essa função recebe uma data no formato ddmmaaaa, 
 * e devolve o dia, o mês e o ano separadamente. */
void separa_data(int, int *, int *, int *);

#endif // _DATA_H
