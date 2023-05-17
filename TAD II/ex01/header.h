#ifndef header_h
#define header_h

typedef struct
{
    double lado;
} Cubo;

void dadosCubo(Cubo *cubo);
double cuboLado(Cubo *cubo);
double cuboArea(Cubo *cubo);
double cuboVolume(Cubo *cubo);

#endif