#ifndef ESCULTURA_H
#define ESCULTURA_H

#include "ObraDeArte.h"

class Escultura : public ObraDeArte
{
    public:
        Escultura(string titulo, string artista, string material, int ano, double altura);
        virtual ~Escultura();

        void setAltura(double altura);

        double getAltura();

        int getCategoria();

        void imprimeFicha();
    private:
        double altura;
};

#endif // ESCULTURA_H
