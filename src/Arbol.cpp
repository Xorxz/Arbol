#include "Arbol.h"

Arbol::Arbol(int Dato)
{
	this->Raiz = new NodoA(Dato);
}

bool Arbol::Insertar(int Dato,int ref)
{
	if(this->Raiz==NULL)
	{
		this->Raiz=new NodoA(Dato);
		std::cout<<"El arbol esta vacio, no existe la referencia"<<std::endl;
		return false;
	}
	NodoA* Padre=Buscar(ref);
	if(Padre==NULL)
	{
		std::cout<<"No existe la referencia"<<std::endl;
		return false;
	}
	else
	{
		NodoA* Hijo=new NodoA(Dato,Padre);
		Padre->Hijos.push_back(Hijo);
	}
	return true;
}
bool Arbol::ExistenciaArbol(int Res){
	if (Buscar(Res)!=NULL){
		std::cout<<"El dato si existe en el arbol"<<std::endl;
	}
}

bool Arbol::Borrar(int ref)
{
	if (this->Raiz==NULL)
	{
		std::cout<<"No existe el valor en el arbol"<<std::endl;
		return false;		
	}
	NodoA* aux=Buscar(ref);
	if (aux == NULL)
	{
		std::cout<<"No existe el valor en el arbol"<<std::endl;
		return false;
	}
	for (int i = 0; i < aux->Hijos.size(); ++i)
	{
		aux->Padre->Hijos.push_back(aux->Hijos[i]);
		aux->Hijos[i]=aux->Padre;
	}
	aux->Hijos.clear();
	aux->Padre=NULL;
	for (int i = 0; i < aux->Padre->Hijos.size(); ++i)
	{
		if (aux==aux->Padre->Hijos[i]){
			aux->Padre->Hijos.erase(aux->Padre->Hijos.begin()+i);
			return true;
		}
	}
	return false;
}

std::stack<NodoA*> Arbol::Camino(NodoA* aux)
{

	std::stack<NodoA*> Camino;
	while(aux!=Raiz){
		Camino.push(aux);
		aux=aux->Padre;
	}
	return Camino;
}

NodoA* Arbol::Buscar(int ref)
{
	if(Raiz==NULL)
	{
		std::cout<<"No existen elementos en el arbol"<<std::endl;
		return NULL;
	} 
	if(BuscarRec(ref,Raiz)==NULL){
		std::cout<<"no se encontro el dato"<<std::endl;
	}
	return BuscarRec(ref,Raiz);

}

NodoA* Arbol::BuscarRec(int ref, NodoA* aux)
{
	
	NodoA* Busque=aux;
	NodoA* 	Res;
	if(Busque->getDato()==ref)
	{
		return Busque;
	}
	if(Busque->Hijos.empty()){
		return NULL;
	}
	for(int i=0; i<Busque->Hijos.size();++i){
		Res = BuscarRec(ref,Busque->Hijos[i]);
		if(Res!=NULL)	
			return Res;		
	}
	
	return NULL;
}
void Arbol::Imprimir(char* espacio,NodoA* aux)
{
	for(int i=0; i<aux->Hijos.size(); ++i)
	{
		std::cout<<espacio;
		std::cout<<aux->Hijos[i]->getDato();
		if (i+1==aux->Hijos.size()){
			strcat(espacio," ");
			std::cout<<std::endl;
		}
		Imprimir(espacio,aux->Hijos[i]);
	}
}

void Arbol::Imprimir()
{
	NodoA* aux = this->Raiz;
	std::cout<<aux->getDato()<<std::endl;
	char espacio[90] = " ";
	Imprimir(espacio, aux);
}