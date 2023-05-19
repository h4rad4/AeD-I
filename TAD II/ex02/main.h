#ifndef MAIN_H
#define MAIN_H

typedef struct {
    int real;
    int img;
} Complexo;

Complexo *criarComplexo(int real, int img);
void destruirComplexo(Complexo *complexo);
Complexo *somarComplexos(Complexo *z1, Complexo *z2);
Complexo *subtrairComplexos(Complexo *z1, Complexo *z2);
Complexo *multiplicarComplexos(Complexo *z1, Complexo *z2);
Complexo *dividirComplexos(Complexo *z1, Complexo *z2);

#endif 
