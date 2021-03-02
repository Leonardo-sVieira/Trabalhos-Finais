#include "Escultura.h"

Escultura::Escultura(string titulo, string artista, string material, int ano, double altura):
    ObraDeArte(titulo, artista, material, ano), altura(altura){
}

Escultura::~Escultura(){
}

void Escultura::setAltura(double altura){
    this->altura = altura;
}

double Escultura::getAltura(){
    return altura;
}

int Escultura::getCategoria(){
    return ESCULTURA;
}

/*Metodo responsavel por imprimir as informações de uma escultura.*/
void Escultura::imprimeFicha(){
    ObraDeArte::imprimeFicha();
    cout << "Altura: " << altura << endl << endl;
}
