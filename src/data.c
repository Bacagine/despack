/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * Copyright (C) 2019 - 2020
 * 
 * data.c: 
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

#include "../include/fatec/data.h"

int compara_datas(date dt1, date dt2){
    int d1, d2;
    
    d1 = dt1.ano * 10000 + dt1.mes * 100 + dt1.dia;
    d2 = dt2.ano * 10000 + dt2.mes * 100 + dt2.dia;
    
    /* Verifica se as datas 
     * são iguais */
    bool dts_iguais = d1 == d2;
    /* Verifica se a primeira 
     * data é menor que a 
     * segunda */
    bool dt1_menor = d1 < d2;
    
    /* Se as datas forem iguais a
     * função retorna 0 */
    if(dts_iguais == true){
        return 0;
    }
    /* Se a primeira data for menor 
     * que a data escolhida pelo
     * usuário a função retorna -1 */
    else if(dt1_menor == true){
        return -1;
    }
    /* Se a primeira data for maior
     * que a segunda data a função
     * retorna 1 */
    else{
        return 1;
    }
}

bool datas_iguais(date dt1, date dt2){
    int d1, d2;
    
    d1 = dt1.ano * 10000 + dt1.mes * 100 + dt1.dia;
    d2 = dt2.ano * 10000 + dt2.mes * 100 + dt2.dia;
    
    /* Se as datas forem iguais a
     * função retorna verdadeiro */
    if(d1 == d2){
        return true;
    }
    /* Se as datas forem diferentes
     * a função retorna false */
    else{
        return false;
    }
}

int valida_mes(int mes){
    
}


void listar_por_data(date dt_inicial, date dt_final){
    
}

void separa_data(int dt, int * d, int * m, int * a){
    *d = dt / 1000000;
    *m = (dt / 10000) % 100;
    *a = dt % 10000;
}

