#ifndef PINTURA_H
#define PINTURA_H

#include "ObraDeArte.h"

class Pintura : public ObraDeArte
{
    public:
        Pintura(string titulo, string artista, string material, int ano, string tipo);
        virtual ~Pintura();

        void setTipo(string tipo);

        string getTipo();

        int getCategoria();

        void imprimeFicha();
    private:
        string tipo;
};

#endif // PINTURA_H
