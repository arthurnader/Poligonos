#include "Poligono.h"

Poligono::Poligono(vector<Point> pontos)
{
	vertices = pontos;
	this->numeroDeVertices = pontos.size();
	this->gerarArestas();
	this->calcularArea();
}

vector<Point> Poligono::getVertices()
{
	return this->vertices;
}

vector<Aresta> Poligono::getArestas()
{
	return this->arestas;
}

void Poligono::gerarArestas()
{
	for (int i = 0; i != vertices.size() - 1; i++) {
		arestas.push_back(Aresta(vertices[i], vertices[i + 1]));
	}
	arestas.push_back(Aresta(vertices[vertices.size() - 1], vertices[0]));
}

void Poligono::mostrarTodosVertices()
{
	cout << "Os vertices do poligono sao: " << endl;
	for (Point iterator : vertices) {
		cout << "(" << iterator.get_x() << " , " << iterator.get_y() << ")" << endl;
	}
}

void Poligono::mostrarTodasArestas()
{
	cout << "As arestas do poligono sao: " << endl;
	for (Aresta iterator : arestas) {
		iterator.mostrarAresta();
	}
}


bool Poligono::ehConvexo()
{
	vector<Point> vertices2 = vertices;
	vertices2.push_back(vertices[0]);
	vertices2.push_back(vertices[1]);

	for (int i = 0; i < vertices.size(); i++) {
		Aresta diagonalAnalisada(vertices2[i], vertices2[i + 2]);
		double projecao = vertices2[i + 1].get_x() * diagonalAnalisada.getCoefAngular() + diagonalAnalisada.getCoefLinear();

		if (diagonalAnalisada.getCoefAngular() == DBL_MAX) {

			if (vertices2[i].get_y() < vertices2[i + 2].get_y()) {
				if (vertices2[i + 1].get_x() < vertices2[i].get_x()) {
					return false;
				}
			}
			else {
				if (vertices2[i + 1].get_x() > vertices2[i].get_x()) {
					return false;
				}
			}
		}
		else if (diagonalAnalisada.getCoefAngular() > 0) {
			if (vertices2[i].get_y() < vertices2[i + 2].get_y()) {
				if (projecao < vertices2[i + 1].get_y()) {
					return false;
				}
			}
			else {
				if (projecao > vertices2[i + 1].get_y()) {
					return false;
				}
			}

		}
		else if (diagonalAnalisada.getCoefAngular() < 0) {
			if (vertices2[i].get_y() < vertices2[i + 2].get_y()) {
				if (projecao > vertices2[i + 1].get_y()) {
					return false;
				}
			}
			else {
				if (projecao < vertices2[i + 1].get_y()) {
					return false;
				}
			}
		}
		else {
			if (vertices2[i].get_x() > vertices2[i + 2].get_x()) {
				if (vertices2[i + 1].get_y() < vertices2[i].get_y()) {
					return false;
				}
			}
			else {
				if (vertices2[i + 1].get_y() > vertices2[i].get_y()) {
					return false;
				}
			}
		}
	}
	return true;
}

bool Poligono::contemPonto(Point ponto)
{
	vector<Point> vertices2 = vertices;
	vertices2.push_back(vertices[0]);

	for (int i = 0; i < arestas.size(); i++) {
		cout << i;
		double projecao = ponto.get_x() * arestas[i].getCoefAngular() + arestas[i].getCoefLinear();

		if (arestas[i].getCoefAngular() == DBL_MAX) {
			if (vertices2[i].get_y() < vertices2[i + 1].get_y()) {
				if (ponto.get_x() > vertices2[i].get_x()) {
					return false;
				}
			}
			else {
				if (ponto.get_x() < vertices2[i].get_x()) {
					return false;
				}
			}
		}

		else if (arestas[i].getCoefAngular() > 0) {
			if (vertices2[i].get_y() < vertices2[i + 1].get_y()) {
				if (projecao < ponto.get_y()) {
					return false;
				}
			}
			else {
				if (projecao > ponto.get_y()) {
					return false;
				}
			}
		}

		else if (arestas[i].getCoefAngular() < 0) {
			if (vertices2[i].get_y() < vertices2[i + 1].get_y()) {
				if (projecao < ponto.get_y()) {
					return false;
				}
			}
			else {
				if (projecao > ponto.get_y()) {
					return false;
				}
			}
		}
		
		else {
			if (vertices2[i].get_x() < vertices2[i + 1].get_x()) {
				if (ponto.get_y() < vertices2[i].get_y()) {
					return false;
				}
			}
			else {
				if (ponto.get_y() > vertices2[i].get_y()) {
					return false;
				}
			}
		}
	}
	return true;
}

void Poligono::calcularArea()
{
	double areaPoligono = 0;

	for (int i = 0; i != vertices.size()-1; i++) {
		areaPoligono += vertices[i].get_x() * vertices[i + 1].get_y() - vertices[i + 1].get_x() * vertices[i].get_y();
	}
	areaPoligono += vertices[vertices.size() - 1].get_x() * vertices[0].get_y() - vertices[0].get_x() * vertices[vertices.size() - 1].get_y();
	areaPoligono /= 2;

	this->area = areaPoligono;
}

double Poligono::getArea()
{
	return this->area;
}
