#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <string>
#include <iostream>
using namespace std;

class Software: public Material
{
    private:
        string sSistemaOper;

    public:
        Software();
        Software(int, string, string);

        string getSistemaOper();
        void setSistemaOper(string);
        void muestra();
        int cantidadDeDiasDePrestamo();
};

Software::Software(): Material()
{
    sSistemaOper = "NA";
}

Software::Software(int iM, string sT, string sSO): Material(iM, sT)
{
    sSistemaOper = sSO;
}

string Software::getSistemaOper()
{
    return sSistemaOper;
}

void Software::setSistemaOper(string sSO)
{
    sSistemaOper = sSO;
}

void Software::muestra()
{
    cout << "Software:" << endl;
    cout << "IdMaterial: " << iIdMaterial << endl;
    cout << "Titulo: " << sTitulo << endl;
    cout << "SistemaOper: " << sSistemaOper << endl;
}

int Software::cantidadDeDiasDePrestamo()
{
    return 1;
}

#endif
