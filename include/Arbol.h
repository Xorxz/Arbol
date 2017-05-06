#include <stack>
#include "NodoA.h"
#include <cstring>


class Arbol
{
	public:
     
	NodoA* BuscarRec(int ref, NodoA* aux);
	NodoA* Raiz;
	Arbol(int Dato);
	NodoA* Buscar(int ref);
	bool Insertar(int Dato,int ref);
	bool Borrar(int ref);
	std::stack<NodoA*> Camino(NodoA* aux);
    void Imprimir(void);
	void Imprimir(char* espacio,NodoA* aux);
    bool ExistenciaArbol(int Res);

};