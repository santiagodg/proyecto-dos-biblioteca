#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string>
using namespace std;

class Fecha
{
    private:
        int iDia;
        int iMes;
        int iAno;
        bool esBisiesto();
        string nombreMes();

    public:
        Fecha();
        Fecha(int, int, int);

        int getAno();
        int getDia();
        int getMes();
        void setAno(int);
        void setDia(int);
        void setMes(int);
        void setFecha(int, int, int);
        Fecha operator+(int);
        bool operator>=(Fecha);
        bool operator<=(Fecha);
        bool operator>(Fecha);
        bool operator<(Fecha);
        bool operator==(Fecha);
        friend istream& operator>>(istream&, Fecha&);
        friend ostream& operator<<(ostream&, Fecha);
};

Fecha::Fecha()
{
    iDia = 1;
    iMes = 1;
    iAno = 0;
}

Fecha::Fecha(int iD, int iM, int iA)
{
    iDia = iD;
    iMes = iM;
    iAno = iA;
}

int Fecha::getAno()
{
    return iAno;
}

int Fecha::getDia()
{
    return iDia;
}

int Fecha::getMes()
{
    return iMes;
}

void Fecha::setAno(int iA)
{
    iAno = iA;
}

void Fecha::setDia(int iD)
{
    iDia = iD;
}

void Fecha::setMes(int iM)
{
    iMes = iM;
}

void Fecha::setFecha(int iD, int iM, int iA)
{
    iDia = iD;
    iMes = iM;
    iAno = iA;
}

Fecha Fecha::operator+(int iD)
{
    int iDiaRes = iDia;
    int iMesRes = iMes;
    int iAnoRes = iAno;
    int iDiasEnMes;
    bool bSePasa = false;
    Fecha fecha(iDiaRes, iMesRes, iAnoRes);

    switch (iMesRes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if (iDiaRes + iD > 31)
            {
                bSePasa = true;
                iDiasEnMes = 31;
            }
            break;

        case 2:
            if (this -> esBisiesto())
            {
                if (iDiaRes + iD > 29)
                {
                    bSePasa = true;
                    iDiasEnMes = 29;
                }
            }
            else
            {
                if (iDiaRes + iD > 28)
                {
                bSePasa = true;
                iDiasEnMes = 28;
                }
            }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (iDiaRes + iD > 30)
            {
                bSePasa = true;
                iDiasEnMes = 30;
            }
            break;

        case 12:
            if (iDiaRes + iD > 31)
            {
                bSePasa = true;
                iDiasEnMes = 31;
                iMesRes = 0;
                iAnoRes++;
                iAnoRes %= 100;
                fecha.setAno(iAnoRes);
            }
            break;
    }
    if (bSePasa)
    {
        iMesRes++;
        fecha.setMes(iMesRes);
        fecha = fecha + (iD - iDiasEnMes);
    }
    else
    {
        iDiaRes += iD;
        fecha.setDia(iDiaRes);
    }
    return fecha;
}

bool Fecha::operator>=(Fecha f)
{
    if (iAno > f.getAno())
    {
        return true;
    }
    else if (iAno == f.getAno())
    {
        if (iMes > f.getMes())
        {
            return true;
        }
        else if (iMes == f.getMes())
        {
            if (iDia >= f.getDia())
            {
                return true;
            }
        }
    }
    return false;
}

bool Fecha::operator<=(Fecha f)
{
    /*
    if (iAno < f.getAno())
    {
        return true;
    }
    else if (iAno == f.getAno())
    {
        if (iMes < f.getMes())
        {
            return true;
        }
        else if (iMes == f.getMes())
        {
            if (iDia <= f.getDia())
            {
                return true;
            }
        }
    }
    return false;
    */
    return iAno < f.getAno() ? 1 : iAno == f.getAno() ? iMes < f.getMes() ? 1 : iMes == f.getMes() ? iDia <= f.getDia() ? 1 : 0 : 0 : 0;
}

bool Fecha::operator>(Fecha f)
{
    return iAno >= f.getAno() && iMes >= f.getMes() && iDia > f.getDia();
}

bool Fecha::operator<(Fecha f)
{
    return iAno <= f.getAno() && iMes <= f.getMes() && iDia < f.getDia();
}

bool Fecha::operator==(Fecha f)
{
    return iAno == f.getAno() && iMes == f.getMes() && iDia == f.getDia();
}

istream& operator>>(istream& is, Fecha& f)
{
    cout << "Dia (DD): ";
    is >> f.iDia;
    cout << "Mes (MM): ";
    is >> f.iMes;
    cout << "Ano (AA): ";
    is >> f.iAno;
    return is;
}

ostream& operator<<(ostream& os, Fecha f)
{
    if (f.iDia < 10)
    {
        os << '0';
    }
    os << f.iDia << '-' << f.nombreMes() << '-';
    if (f.iAno < 10)
    {
        os << '0';
    }
    os << f.iAno;
    return os;
}

bool Fecha::esBisiesto()
{
    return iAno % 4 == 0;
}

string Fecha::nombreMes()
{
    switch (iMes)
    {
        case 1:
            return "Ene";
            break;
        case 2:
            return "Feb";
            break;
        case 3:
            return "Mar";
            break;
        case 4:
            return "Abr";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "Jun";
            break;
        case 7:
            return "Jul";
            break;
        case 8:
            return "Ago";
            break;
        case 9:
            return "Sep";
            break;
        case 10:
            return "Oct";
            break;
        case 11:
            return "Nov";
            break;
        case 12:
            return "Dic";
            break;
        default:
            return "Inv";
            break;
    }
}

#endif
