#include "Arbol.h"

int main()
{

Arbol A = Arbol(1);
A.Insertar(2,1);
A.Insertar(3,1);
A.Insertar(4,2);
A.Insertar(5,2);
A.Insertar(6,3);
A.Insertar(7,3);
A.Insertar(10,3);
A.Insertar(9,5);
A.Insertar(8,5);
A.ExistenciaArbol(9);
A.Imprimir();
	return 0;
}