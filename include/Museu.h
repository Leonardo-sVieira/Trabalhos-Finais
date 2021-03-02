#ifndef MUSEU_H
#define MUSEU_H

#include <vector>
#include <algorithm>
#include <string>
#include "ObraDeArte.h"
#include "Pintura.h"
#include "Escultura.h"

using namespace std;

class Museu
{
    public:
        Museu(string nome);
        virtual ~Museu();

        bool adicionaObra(ObraDeArte* obra);

        bool removeObra(string titulo);

        ObraDeArte* obtemObra(string titulo);

        int qtdeObras();

        int qtdePinturas();

        int qtdeEsculturas();

        void imprime();

        void imprimePorCategoria(int categoria);
    private:
        string nome;
        vector<ObraDeArte*> obras;

};

#endif // MUSEU_H
