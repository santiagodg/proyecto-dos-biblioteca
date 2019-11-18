#ifndef DISCO_H
#define DISCO_H

#include <string>
#include <iostream>
using namespace std;

class Disco: public Material
{
    private:
        int iDuracion;

    public:
        Disco();
        Disco(int, string, int);

        int getDuracion();
        void setDuracion(int);
        void muestra();
        int cantidadDeDiasDePrestamo();
};

Disco::Disco(): Material()
{
    iDuracion = 1;
}

Disco::Disco(int iM, string sT, int iD): Material(iM, sT)
{
    iDuracion = iD;
}

int Disco::getDuracion()
{
    return iDuracion;
}

void Disco::setDuracion(int iD)
{
    iDuracion = iD;
}

void Disco::muestra()
{
    cout << "Disco:" << endl;
    cout << "IdMaterial: " << iIdMaterial << endl;
    cout << "Titulo: " << sTitulo << endl;
    cout << "Duracion: " << iDuracion << endl;
}

int Disco::cantidadDeDiasDePrestamo()
{
    return 3;
}

#endif
