#include "../include/fatec/my_math.h"

int soma(int n1, int n2){
    return n1 + n2;
}

int subtracao(int n1, int n2){
    return n1 - n2;
}

int multiplicacao(int n1, int n2){
    return n1 * n2;
}

int divisao(int n1, int n2){
    return n1 / n2;
}

int fsoma(float n1, float n2){
    return n1 + n2;
}


int fsubtracao(float n1, float n2){
    return n1 - n2;
}

int fmultiplicacao(float n1, float n2){
    return n1 * n2;
}


int fdivisao(float n1, float n2){
    return n1 / n2;
}

int dsoma(double n1, double n2){
    return n1 + n2;
}


int dsubtracao(double n1, double n2){
    return n1 - n2;
}

int dmultiplicacao(double n1, double n2){
    return n1 * n2;
}


int ddivisao(double n1, double n2){
    return n1 / n2;
}

long long int fatorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    else{
        return n * fatorial(n - 1);
    }
}

int my_pow(int n, int e){
    register int t = 1;
    for(; e; e--){
        t = t*n;
    }
    return t;
}

int bin2dec(const int bin){
    return 0;
}

int dec2bin(const int dec){
    return 0;
}

int area(int raio){
    int a;
    
    a = 4 * PI * pow(raio, 2);
    
    return a;
}

int volume_esfera(int raio){
    int vol;
    
    vol = (4 * PI * pow(raio, 3)) / 3;
    
    return vol;
}

void transforma_segundos(int s_int, int *h, int *min, int *s){
    *h = s_int / 3600;
    *min = (s_int / 60) % 60;
    *s = s_int % 60;
}

void circunferencia(float r, float *dim, float *per, float *a){
    *dim = 2 * r;
    *per = 2 * PI * r;
    *a = PI * pow(r, 2);
}

void converte(float m, double *pol, double *jards, double *mils){
    *pol = (m * 39.37) / 1.0;
    *jards = (m * 1.0936) / 1.0;
    *mils = (m * 0.00062) / 1.0;
}

void file_size(int b, float * kb, float * mb){
    *kb = b / 1024.0;
    *mb = *kb / 1024;
}
