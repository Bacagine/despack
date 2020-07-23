/* Git Hub: https://github.com/Bacagine/fatec
 * 
 * physics.h: Biblioteca com as constantes e os prototipo 
 * das funções de física
 * 
 * Biblioteca criada por Gustavo Bacagine <gustavo.bacagine@protonmail.com>
 * 
 * Data de início: 19/10/2019
 * Data da última modificação: 20/07/2020
 */

#ifndef _PHYSICS_H
#define _PHYSICS_H

#include <math.h>
#include "my_math.h"

#define PLANK_CONST 0000000000000000000000000000000000.662607015 //
#define UNIVERSAL_GRAVITY 00000000000.6674184 //
#define SPEED_LIGTH 299792458 //
#define GRAVITY_EARTH 9.81 // m/s²

/* Calcula a velocidade media */
double vm(double space, double time);

/* Calcula a Força Relativa */
double fr(double mass, double aceleration);

/* Calcula a altura */
double weight(double mass, double gravity);

/* Calcula a Energia Cinetica */
double ec(double mass, double vm);

/* Calcula a Energia Potencial Gravitacional */
double epg(double mass, double gravity, double heigth);

/* Calcula a Energia Potencial Elastica */
double epe(double k, double x);

/* Calcula a Energia Mecanica */
double em(double ec, double ep);

/* Calcula a Intensidade */
double im(double force, double time);

/*  */
double qm(double mass, double velocity);

/* Calcula a pressão */
double pressure(double force, double area);

/* Calcula a densidade */
double density(double mass, double volume);

#endif
