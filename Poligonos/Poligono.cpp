#include "Poligono.h"

Poligono::Poligono(vector<Point> pontos)
{
	vertices = pontos;
	this->numeroDeVertices = pontos.size();
	this->gerarArestas();
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
