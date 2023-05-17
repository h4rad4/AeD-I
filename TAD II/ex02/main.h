#ifndef main_h
#define main_h

typedef struct {
    int real;     
    int img;     
} Complexo;

void *criarComplexo(int real, int img);
void destruirComplexo(Complexo *complexo);
Complexo *somarComplexos(Complexo *z1, Complexo *z2);
Complexo *subtrairComplexos(Complexo *z1, Complexo *z2);
Complexo *multiplicarComplexos(Complexo *z1, Complexo *z2);

#endif