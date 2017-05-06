#include <iostream>
#include <vector>

class NodoA
{
	
public:
	int Dato;
	NodoA* Padre;
	std::vector<NodoA*> Hijos;

	NodoA(int Dato);
	NodoA(int Dato, NodoA* Padre);
	void setDato(int Dato);
	void setPadre(NodoA* Padre);
	int getDato();
	NodoA* getPadre();

};