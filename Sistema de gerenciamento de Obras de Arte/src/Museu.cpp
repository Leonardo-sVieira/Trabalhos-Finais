#include "Museu.h"

Museu::Museu(string nome):
    nome(nome){
}

Museu::~Museu(){
}

/*Função recebe uma obra por referência
  e retorna true se foi possivel adiciona-la no vetor e false caso contrário devido a sua existencia*/
bool Museu::adicionaObra(ObraDeArte* obra){
    int qtd_obras = obras.size();

    for(int i = 0; i < qtd_obras; i++)
        if(obras[i]->getTitulo() == obra->getTitulo())
            return false;

    obras.push_back(obra);

    return true;
}

/*A função recebe uma string titulo
  retorna true se existe alguma obra com o titulo especificado e false caso contrário*/
bool Museu::removeObra(string titulo){
    int qtd_obras = obras.size();

    for(int i = 0; i < qtd_obras; i++){
        ObraDeArte* obra = obras[i];

        if(obra->getTitulo() == titulo){
            obras.erase(obras.begin() + i);

            return true;
        }
    }

    return false;
}

/*A função receber uma string titulo
 retorna um ponteiro para o titulo especificado ou NULL caso não exista*/
ObraDeArte* Museu::obtemObra(string titulo){
    int qtd_obras = obras.size();

    for(int i = 0; i < qtd_obras; i++){
        ObraDeArte* obra = obras[i];

        if(obra->getTitulo() == titulo)
            return obras[i];
    }

    return NULL;
}

/*A função não tem parametros apenas retorna a quantidade de obras do museu*/
int Museu::qtdeObras(){
    return obras.size();
}

/*A função não tem parametros apenas retorna a quantidade de Pinturas que tem no museu*/
int Museu::qtdePinturas(){
    int cont = 0;
    int qtd_obras = obras.size();

    for(int i = 0; i < qtd_obras; i++){
        ObraDeArte* obra = obras[i];
        if(obra->getCategoria() == 1)
            cont++;
    }

    return cont;
}

/*A função não tem parametros apenas retorna a quantidade de Esculturas que tem no museu*/
int Museu::qtdeEsculturas(){
    int cont = 0;
    int qtd_obras = obras.size();

    for(int i = 0; i < qtd_obras; i++){
        ObraDeArte* obra = obras[i];

        if(obra->getCategoria() == 2)
            cont++;
    }

    return cont;
}

/*A função recebe dois ponteiros e retorna as seguinte valores lógicos:
  true se a obra mais a esquerda na posição do vetor é menor
  false se o a obra mais a esquerda na posição do vetor é maior
  true se o ano da obra mais a esquerda na posição do vetor é menor
  false se o ano da obra mais a esquerda na posição do vetor é maior*/
bool compara_TituloAno(ObraDeArte* obra1, ObraDeArte* obra2){
    if(obra1->getTitulo() < obra2->getTitulo())
        return true;
    else if(obra1->getTitulo() > obra2->getTitulo())
        return false;
    else if(obra1->getAno() < obra2->getAno())
        return true;
    else
        return false;
}

/*O metodo não possui parametros e imprime as informações ordenadas por titulo+ano*/
void Museu::imprime(){
    int qtd_obras = obras.size();

    sort(obras.begin(), obras.end(), compara_TituloAno);

    for(int i = 0; i < qtd_obras; i++)
        obras[i]->imprimeFicha();
}

/*O metodo não possui parametros e imprime as informações de uma categoria especifica de obra e ordenadas por titulo+ano*/
void Museu::imprimePorCategoria(int categoria){
    vector<ObraDeArte*> obras_categoria;
    int qtd_obras = obras.size(), j = 0;

    for(int i = 0; i < qtd_obras; i++)
        if(obras[i]->getCategoria() == categoria){
            obras_categoria.push_back(obras[i]);
            j++;
        }

    qtd_obras = obras_categoria.size();

    sort(obras_categoria.begin(), obras_categoria.end(), compara_TituloAno);

    for(int i = 0; i < qtd_obras; i++)
        obras_categoria[i]->imprimeFicha();
}
