#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

#pragma once
#include <iostream>
#include <stdlib.h>
#include <list>
#include "Class_Point.h"

class Aresta
{
private:
    double coeficienteAngular;
    double coeficienteLinear;
    Point vertice1;
    Point vertice2;

public:
    Aresta(Point vert1, Point vert2);

    void setVertice1(Point v1);
    void setVertice2(Point v2);

    Point getVertice1();
    Point getVertice2();

    double getCoefAngular();
    double getCoefLinear();

    void calcularCoeficientes();

    void mostrarAresta();
};

#endif // ARESTA_H_INCLUDED