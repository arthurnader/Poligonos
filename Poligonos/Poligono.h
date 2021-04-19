#ifndef POLIGONO_H_INCLUDED
#define POLIGONO_H_INCLUDED

#pragma once
#include "Aresta.h"

using namespace std;

class Poligono
{
private:
	vector<Point> vertices;
	vector<Aresta> arestas;
	double area;
	bool convexo;
	int numeroDeVertices;

	void gerarArestas();

public:
	Poligono() {};
	Poligono(vector<Point> pontos);

	vector<Point> getVertices();
	vector<Aresta> getArestas();

	void mostrarTodosVertices();
	void mostrarTodasArestas();

	bool ehConvexo();

	//bool contemPonto(Point* ponto);

	//void calcularArea();

};

#endif // POLIGONO_H_INCLUDED

