#ifndef OBRADEARTE_H
#define OBRADEARTE_H

#include <string>
#include <iostream>

using namespace std;

enum CATEGORIA {PINTURA = 1, ESCULTURA};

class ObraDeArte
{
    public:
        ObraDeArte(string titulo, string artista, string material, int ano);
        virtual ~ObraDeArte();

        void setTitulo(string titulo);

        void setArtista(string artista);

        void setMaterial(string material);

        void setAno(int ano);

        string getTitulo();

        string getArtista();

        string getMaterial();

        int getAno();

        virtual int getCategoria() = 0;

        virtual void imprimeFicha();
    private:
        string titulo, artista, material;
        int ano;
};

#endif // OBRADEARTE_H
