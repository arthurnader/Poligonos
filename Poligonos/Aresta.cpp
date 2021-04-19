#include "Aresta.h"
#include <iostream>

using namespace std;

Aresta::Aresta(Point vert1, Point vert2)
{
	this->vertice1 = vert1;
	this->vertice2 = vert2;
	calcularCoeficientes();
}


void Aresta::setVertice1(Point v1)
{
	this->vertice1 = v1;
	calcularCoeficientes();
}

void Aresta::setVertice2(Point v2)
{
	this->vertice2 = v2;
	calcularCoeficientes();
}

Point Aresta::getVertice1()
{
	return vertice1;
}

Point Aresta::getVertice2()
{
	return vertice2;
}

double Aresta::getCoefAngular()
{
	return this->coeficienteAngular;
}

double Aresta::getCoefLinear()
{
	return this->coeficienteLinear;
}

void Aresta::calcularCoeficientes()
{
	if ((vertice2.get_x() - vertice1.get_x()) != 0) {
		coeficienteAngular = (vertice2.get_y() - vertice1.get_y()) / (vertice2.get_x() - vertice1.get_x());
		coeficienteLinear = (vertice2.get_y()) - coeficienteAngular * vertice2.get_x();
	}
	else {
		coeficienteAngular = DBL_MAX;
		coeficienteLinear = vertice2.get_x();
	}
}

void Aresta::mostrarAresta()
{
	if (coeficienteAngular == DBL_MAX) {
		cout << "X = " << coeficienteLinear << " ligando o ponto "
			<< "(" << vertice1.get_x() << " , " << vertice1.get_y() << ")"
			<< " ao ponto " << "(" << vertice2.get_x()
			<< " , " << vertice2.get_y() << ")" << "\n";
	}
	else {
		cout << "Y = " << coeficienteAngular << "X + " << coeficienteLinear
			<< " ligando o ponto " << "(" << vertice1.get_x() << " , "
			<< vertice1.get_y() << ")" << " ao ponto " << "("
			<< vertice2.get_x() << " , " << vertice2.get_y() << ")" << "\n";
	}

}