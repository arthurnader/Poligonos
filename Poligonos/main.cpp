#include <iostream>
#include "Poligono.h"

using namespace std;

int main() {
	int numeroPontos;
	vector<Point> pontos;

	cout << "Digite o numero de vertices do poligo: ";
	cin >> numeroPontos;
	cout << "Agora, entre com as coordenadas de cada vertice em sentido anti-horario: ";

	double x = 0; double y = 0;

	for (int i = 0; i != numeroPontos; i++) {
		Point pnt(NULL, NULL, 0);
		cin >> x;
		cin >> y;
		pnt.set_x(x);
		pnt.set_y(y);
		pontos.push_back(pnt);
	}

	Poligono* pol = new Poligono(pontos);
	cout << pol->ehConvexo() << endl;
	cout << pol->getArea() << endl;

	Point pontoAnalisado(NULL, NULL, 0);
	cin >> x;
	cin >> y;
	pontoAnalisado.set_x(x);
	pontoAnalisado.set_y(y);

	cout << pol->contemPonto(pontoAnalisado);

	return 0;
}
