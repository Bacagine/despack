#include <stdio.h>
#include "../include/fatec/physics.h"

double vm(double space, double time){
    double vel;
    
    vel = space / time;
    
    return vel;
}

double fr(double mass, double aceleration){
    double force;
    
    force = mass * aceleration;
    
    return force;
}

double weight(double mass, double gravity){
    double p;
    
    p = mass * gravity;
    
    return p;
}

double ec(double mass, double vm){
    double energy;
    
    energy = (mass * pow(vm, 2)) / 2;
    
    return energy;
}

double epg(double mass, double gravity, double heigth){
    double energy;
    
    energy = mass * gravity * heigth;
    
    return energy;
}

double epe(double k, double x){
    double energy;
    
    energy = (k * pow(x, 2)) / 2;
    
    return energy;
}


double em(double ec, double ep){
    double energy;
    
    energy = ec + ep;
    
    return energy;
}

double im(double force, double time){
    double i;
    
    i = force * time;
    
    return i;
}

double qm(double mass, double velocity){
    double q;
    
    q = mass * velocity;
    
    return q;
}

double pressure(double force, double area){
    double p;
    
    p = force / area;
    
    return p;
}

double density(double mass, double volume){
    double d;
    
    d = mass / volume;
    
    return d;
}
