#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <iostream>
using namespace std;

class Libro: public Material
{
    private:
        int iNumPag;
        string sAutor;

    public:
        Libro();
        Libro(int, string, int, string);

        int getNumPag();
        string getAutor();
        void setNumPag(int);
        void setAutor(string);
        void muestra();
        int cantidadDeDiasDePrestamo();
};

Libro::Libro(): Material()
{
    iNumPag = 1;
    sAutor = "NA";
}

Libro::Libro(int iM, string sT, int iN, string sA): Material(iM, sT)
{
    iNumPag = iN;
    sAutor = sA;
}

int Libro::getNumPag()
{
    return iNumPag;
}

string Libro::getAutor()
{
    return sAutor;
}

void Libro::setNumPag(int iN)
{
    iNumPag = iN;
}

void Libro::setAutor(string sA)
{
    sAutor = sA;
}

void Libro::muestra()
{
    cout << "Libro:" << endl;
    cout << "IdMaterial: " << iIdMaterial << endl;
    cout << "Titulo: " << sTitulo << endl;
    cout << "NumPag: " << iNumPag << endl;
    cout << "Autor: " << sAutor << endl;
}

int Libro::cantidadDeDiasDePrestamo()
{
    return 10;
}

#endif
