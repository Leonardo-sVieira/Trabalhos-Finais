#include "ObraDeArte.h"

/*Construtor responsavel por inicializar as seguintes variaveis
 *titulo, artista material e ano*/
ObraDeArte::ObraDeArte(string titulo, string artista, string material, int ano):
    titulo(titulo), artista(artista), material(material), ano(ano){
}

ObraDeArte::~ObraDeArte(){
}

void ObraDeArte::setTitulo(string titulo){
    this->titulo = titulo;
}

string ObraDeArte::getTitulo(){
    return titulo;
}

void ObraDeArte::setArtista(string artista){
    this->artista = artista;
}

string ObraDeArte::getArtista(){
    return artista;
}

void ObraDeArte::setMaterial(string material){
    this->material = material;
}

string ObraDeArte::getMaterial(){
    return material;
}

void ObraDeArte::setAno(int ano){
    this->ano = ano;
}

int ObraDeArte::getAno(){
    return ano;
}

/*Metodo responsavel por diferenciar a obra e mostras as informações especificas da mesma.*/
void ObraDeArte::imprimeFicha(){
    cout << "Categoria: ";
    (getCategoria() == 1)? cout << "Pintura" << endl : cout << "Escultura" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Artista: " << artista << endl;
    cout << "Material: " << material << endl;
    cout << "Ano: " << ano << endl;
}
