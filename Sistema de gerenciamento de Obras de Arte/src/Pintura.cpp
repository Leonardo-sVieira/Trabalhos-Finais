#include "Pintura.h"

Pintura::Pintura(string titulo, string artista, string material, int ano, string tipo):
    ObraDeArte(titulo, artista, material, ano), tipo(tipo){
}

Pintura::~Pintura(){
}

void Pintura::setTipo(string tipo){
    this->tipo = tipo;
}

string Pintura::getTipo(){
    return tipo;
}

int Pintura::getCategoria(){
    return PINTURA;
}

/*Metodo responsavel por imprimir as informações de uma pintura.*/
void Pintura::imprimeFicha(){
    ObraDeArte::imprimeFicha();

    cout << "Tipo: " << tipo << endl << endl;
}
