#ifndef RESERVA_H
#define RESERVA_H

#include "Fecha.h"

class Reserva
{
    private:
        int iIdMaterial;
        int iIdCliente;
        Fecha fechaReservacion;

    public:
        Reserva();
        Reserva(int, int, Fecha);

        int getIdMaterial();
        int getIdCliente();
        Fecha getFechaReservacion();
        void setIdMaterial(int);
        void setIdCliente(int);
        void setFechaReservacion(Fecha);
        Fecha calculaFechaFinReserva(int);
};

Reserva::Reserva()
{
    iIdMaterial = 1;
    iIdCliente = 1;
    fechaReservacion = Fecha();
}

Reserva::Reserva(int iM, int iC, Fecha f)
{
    iIdMaterial = iM;
    iIdCliente = iC;
    fechaReservacion = f;
}

int Reserva::getIdMaterial()
{
    return iIdMaterial;
}

int Reserva::getIdCliente()
{
    return iIdCliente;
}

Fecha Reserva::getFechaReservacion()
{
    return fechaReservacion;
}

void Reserva::setIdMaterial(int iM)
{
    iIdMaterial = iM;
}

void Reserva::setIdCliente(int iC)
{
    iIdCliente = iC;
}

void Reserva::setFechaReservacion(Fecha f)
{
    fechaReservacion = f;
}

Fecha Reserva::calculaFechaFinReserva(int iD)
{
    return fechaReservacion + iD;
}

#endif
