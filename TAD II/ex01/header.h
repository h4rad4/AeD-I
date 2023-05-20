#ifndef MAIN_H
#define MAIN_H

typedef struct {
    double lado;
} Cubo;

void dadosCubo(Cubo *cubo);
double cuboLado(Cubo *cubo);
double cuboArea(Cubo *cubo);
double cuboVolume(Cubo *cubo);

#endif