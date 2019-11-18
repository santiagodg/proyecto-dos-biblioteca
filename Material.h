#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
using namespace std;

class Material
{
    protected:
        int iIdMaterial;
        string sTitulo;

    public:
        Material();
        Material(int, string);

        int getIdMaterial();
        string getTitulo();
        void setIdMaterial(int);
        void setTitulo(string);
        virtual void muestra() = 0;
        virtual int cantidadDeDiasDePrestamo() = 0;
};

Material::Material()
{
    iIdMaterial = 1;
    sTitulo = "NA";
}

Material::Material(int iM, string sT)
{
    iIdMaterial = iM;
    sTitulo = sT;
}

int Material::getIdMaterial()
{
    return iIdMaterial;
}

string Material::getTitulo()
{
    return sTitulo;
}

void Material::setIdMaterial(int iM)
{
    iIdMaterial = iM;
}

void Material::setTitulo(string sT)
{
    sTitulo = sT;
}

#endif
