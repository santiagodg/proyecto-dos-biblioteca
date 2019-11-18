// Santiago Díaz Guevara
// A01252554 

// Este programa no está optimizado ni organizado.

#include "Material.h"
#include "Reserva.h"
#include "Fecha.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    /*
    1. 	Escribe ahora un programa que tenga un arreglo de apuntadores a objeto
        de tipo Material (con un máximo de 20 elementos) y un arreglo de
        Reservaciones (con un máximo de 50 elementos).
    */
    Material* listaMaterial[20];
    int iContadorListaMaterial = 0;
    Reserva listaReservaciones[50];
    int iContadorListaReservaciones = 0;

    /*
    2.  Carga los datos para el arreglo de Material de un archivo de texto
        llamado “Material.txt” que contiene en cada renglón el id del material,
        la clave (L para libro, D para disco y S para software) que indica el
        tipo de material de que se trata y los datos particulares de cada
        material.
        Para libro tiene el formato:
            idMaterial titulo L numPag Autor
        Para los Discos tiene el formato:
            IdMaterial titulo D duración
        Para el software tiene el formato:
            idMaterial titulo S sistemaOperativo
        Para todos los casos considera que el título del material es un string
        de una sola palabra. Para la clase Libro, considera que el autor es un
        string de una sola palabra, para la clase Software considera que el
        sistema operativo es un string de una sola palabra.
    */
    int iIdMaterial, iNumPag, iDuracion;
    string sTitulo, sAutor, sSistemaOper;
    char cTipo;
    ifstream ifMaterial;
    ifMaterial.open("Material.txt");
    while (iContadorListaMaterial < 20 && ifMaterial >> iIdMaterial >> sTitulo >> cTipo)
    {
        switch (cTipo)
        {
            case 'B':
                ifMaterial >> iNumPag >> sAutor;
                listaMaterial[iContadorListaMaterial] = new Libro(iIdMaterial, sTitulo, iNumPag, sAutor);
                break;
            case 'C':
                ifMaterial >> iDuracion;
                listaMaterial[iContadorListaMaterial] = new Disco(iIdMaterial, sTitulo, iDuracion);
                break;
            case 'S':
                ifMaterial >> sSistemaOper;
                listaMaterial[iContadorListaMaterial] = new Software(iIdMaterial, sTitulo, sSistemaOper);
                break;
        }
        ++iContadorListaMaterial;
        if (ifMaterial.eof()) break;
    }
    ifMaterial.close();

    /*
    3.  Carga los datos para el arreglo de Reservaciones de un archivo de texto
        llamado “Reserva.txt” que contiene en cada renglón el dia, mes y año de
        la fecha de inicio del reserva, el id del material y el id del cliente.
        Formato:
            dd mm aa idMaterial idCliente
        Hay archivos de material y de reservaciones disponibles en Blackboard;
        al entrar al programa se deberán cargar los datos de los archivos y al
        salir del programa se deben actualizar los datos de los archivos, de
        manera que se conserven las reservaciones realizadas la última vez que
        se utilizó el programa.
    */
    int iDia, iMes, iAno, iIdCliente, iReservasEnArchivo;
    ifstream ifReserva;
    ifReserva.open("Reserva.txt");
    while (iContadorListaReservaciones < 50 && ifReserva >> iDia >> iMes >> iAno >> iIdMaterial >> iIdCliente)
    {
        listaReservaciones[iContadorListaReservaciones] = Reserva(iIdMaterial, iIdCliente, Fecha(iDia, iMes, iAno % 2000));
        ++iContadorListaReservaciones;
        if (ifReserva.eof()) break;
    }
    ifReserva.close();
    iReservasEnArchivo = iContadorListaReservaciones;

    /*
    4.  Tu programa deberá tener un menú con las siguientes opciones:
        a.  Consultar la lista de Materiales. Que muestre todos los datos de
            cada material.
        b.  Consultar la lista de reservaciones, al hacerlo deberás mostrar la
            fecha en la que inicia la reservación, la fecha en la que termina
            la reservación, el nombre del material y el id del cliente.
        c.  Consultar las reservaciones de un material dado, que muestre para
            cada reservación el nombre del material, su fecha de inicio de
            reservación y su fecha de terminación.
        d.  Consultar las reservaciones de una fecha dada, que muestre la lista
            de los materiales que se encuentren reservados en la fecha dada.
            Debe mostrar el nombre del material y el id del cliente. Nota que
            tienes que revisar el rango de fechas de cada reservación para
            verificar si el material está reservado o no en una fecha dada.
        e.  Hacer una reservación, en esta opción pregunta al usuario el id del
            cliente y del material, así como la fecha en que desea reservar. El
            programa validará que id del material sea válido y que el material
            este disponible en esa fecha (o sea debe revisar las reservaciones
            existentes) y en caso de que sí se pueda, se reservará.
        f.  Terminar. Al ejecutar esta opción se debe actualizar la información
            del archivo de reservaciones de manera que se conserve la
            información para la siguiente vez que se ejecute el programa.
    Nota: Es necesario que al pedir un id de material el programa verifique que
    exista y si no existe que vuelva a pedir el dato tantas veces como el
    usuario se equivoque.
    */
    int iX, iY;
    Material* material;
    bool bExiste, bEsValido, bEstaOcupado;
    Fecha fecha;
    char cOpcion;
    ofstream ofReserva;
    do
    {
        cout << endl;
        cout << "MENU" << endl;
        cout << "a. Consultar la lista de Materiales." << endl;
        cout << "b. Consultar la lista de reservaciones." << endl;
        cout << "c. Consultar las reservaciones de un material dado." << endl;
        cout << "d. Consultar las reservaciones de una fecha dada." << endl;
        cout << "e. Hacer una reservacion." << endl;
        cout << "f. Terminar." << endl;
        cout << "Opcion: ";
        cin >> cOpcion;
        cout << endl;
        switch (cOpcion)
        {
            case 'a':
            case 'A':
                for (iX = 0; iX < iContadorListaMaterial; ++iX)
                {
                    listaMaterial[iX] -> muestra();
                    cout << endl;
                }
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                break;

            case 'b':
            case 'B':
                for (iX = 0; iX < iContadorListaReservaciones; ++iX)
                {
                    cout << "Reservacion:" << endl;
                    cout << "Fecha de inicio: ";
                    cout << listaReservaciones[iX].getFechaReservacion() << endl;
                    cout << "Fecha de terminacion: ";
                    for (iY = 0; iY < iContadorListaMaterial; ++iY)
                    {
                        if (listaReservaciones[iX].getIdMaterial() == listaMaterial[iY] -> getIdMaterial())
                        {
                            material = listaMaterial[iY];
                            break;
                        }
                    }
                    cout << listaReservaciones[iX].calculaFechaFinReserva(material -> cantidadDeDiasDePrestamo()) << endl;
                    cout << "Material: ";
                    cout << material -> getTitulo() << endl;
                    cout << "Cliente: ";
                    cout << listaReservaciones[iX].getIdCliente() << endl << endl;
                }
                cout << "Presione enter para continuar...";
                cin.ignore();
                cin.get();
                break;

            case 'c':
            case 'C':
                do
                {
                    do
                    {
                        cout << "Ingrese el Id del Material (-1 para salir): ";
                        cin >> iIdMaterial;

                        if (iIdMaterial == -1) break;
                        cout << endl;

                        bExiste = false;
                        for (iX = 0; iX < iContadorListaMaterial; ++iX)
                        {
                            if (iIdMaterial == listaMaterial[iX] -> getIdMaterial())
                            {
                                bExiste = true;
                                material = listaMaterial[iX];
                                break;
                            }
                        }
                        if (!bExiste)
                        {
                            cout << "No se encontro Material." << endl;
                            cout << "Desea intentar con otro Id? (s/n): ";
                            cin >> cOpcion;
                            if (cOpcion != 's' && cOpcion != 'S') break;
                            cout << endl;
                        }
                    }
                    while (!bExiste);

                    if (iIdMaterial == -1 || cOpcion != 's' && cOpcion != 'S' && !bExiste)
                    {
                        cout << "Regresando al menu..." << endl << endl;
                        break;
                    }

                    bExiste = false;
                    for (iX = 0; iX < iContadorListaReservaciones; ++iX)
                    {
                        if (iIdMaterial == listaReservaciones[iX].getIdMaterial())
                        {
                            bExiste = true;
                            cout << "Reservacion:" << endl;
                            cout << "Material: ";
                            cout << material -> getTitulo() << endl;
                            cout << "Fecha de inicio: ";
                            cout << listaReservaciones[iX].getFechaReservacion() << endl;
                            cout << "Fecha de terminacion: ";
                            cout << listaReservaciones[iX].calculaFechaFinReserva(material -> cantidadDeDiasDePrestamo()) << endl << endl;
                        }
                    }
                    if (!bExiste)
                    {
                        cout << "No se encontro ninguna reservacion." << endl;
                    }
                    cout << "Desea buscar reservaciones con otro Id? (s/n): ";
                    cin >> cOpcion;
                    if (cOpcion != 's' && cOpcion != 'S')
                    {
                        cout << "Regresando al menu..." << endl << endl;
                        break;
                    }
                    cout << endl;
                }
                while (cOpcion == 's' || cOpcion == 'S');
                break;

            case 'd':
            case 'D':
                do
                {
                    do
                    {
                        cout << "Ingrese la fecha:" << endl;
                        cin >> fecha;
                        cout << endl;
                        iDia = fecha.getDia();
                        iMes = fecha.getMes();
                        iAno = fecha.getAno();
                        bEsValido =  ((1 <= iDia && iDia <= 31) &&
                                    (1 <= iMes && iMes <= 12) &&
                                    (0 <= iAno && iAno <= 99)) ?
                                        (iMes == 1 || iMes == 3 ||
                                        iMes == 5 || iMes == 7 ||
                                        iMes == 8 || iMes == 10 ||
                                        iMes == 12) ?
                                            1 :
                                            iMes == 2 ?
                                                iAno % 4 == 0 ?
                                                    iDia <= 29 :
                                                    iDia <= 28 :
                                                (iMes == 4 || iMes == 6 ||
                                                iMes == 9 || iMes == 11) ?
                                                    iDia <= 30 :
                                                    0 :
                                        0;
                        if (!bEsValido)
                        {
                            cout << "La fecha ingresada no es valida." << endl;
                            cout << "Desea intentar con otra fecha? (s/n): ";
                            cin >> cOpcion;
                            if (cOpcion != 's' && cOpcion != 'S') break;
                            cout << endl;
                        }
                    }
                    while (!bEsValido);

                    if (cOpcion != 's' && cOpcion != 'S' && !bEsValido)
                    {
                        cout << "Regresando al menu..." << endl << endl;
                        break;
                    }

                    bExiste = false;
                    for (iX = 0; iX < iContadorListaReservaciones; ++iX)
                    {
                        for (iY = 0; iY < iContadorListaMaterial; ++iY)
                        {
                            if (listaReservaciones[iX].getIdMaterial() == listaMaterial[iY] -> getIdMaterial())
                            {
                                material = listaMaterial[iY];
                                break;
                            }
                        }
                        if (listaReservaciones[iX].getFechaReservacion() <= fecha &&
                        fecha <= listaReservaciones[iX].calculaFechaFinReserva(material -> cantidadDeDiasDePrestamo()))
                        {
                            bExiste = true;
                            cout << "Material:" << endl;
                            cout << "Titulo: " << material -> getTitulo() << endl;
                            cout << "Cliente: " << listaReservaciones[iX].getIdCliente() << endl << endl;
                        }
                    }
                    if (!bExiste)
                    {
                        cout << "No se encontro reservacion." << endl;
                    }
                    cout << "Desea buscar reservaciones en otra fecha? (s/n): ";
                    cin >> cOpcion;
                    if (cOpcion != 's' && cOpcion != 'S')
                    {
                        cout << "Regresando al menu..." << endl << endl;
                        break;
                    }
                    cout << endl;
                }
                while (cOpcion == 's' || cOpcion == 'S');
                break;

            case 'e':
            case 'E':
                do
                {
                    cout << "Ingrese el Id del Cliente (-1 para cancelar): ";
                    cin >> iIdCliente;

                    if (iIdCliente == -1)
                    {
                        cout << "La reservacion ha sido cancelada." << endl;
                        cout << "Regresando al menu..." << endl << endl;
                        break;
                    }

                    bExiste = false;
                    do
                    {
                        cout << "Ingrese el Id del Material (-1 para cancelar): ";
                        cin >> iIdMaterial;
                        if (iIdMaterial == -1) break;
                        cout << endl;
                        for (iX = 0; iX < iContadorListaMaterial; ++iX)
                        {
                            if (iIdMaterial == listaMaterial[iX] -> getIdMaterial())
                            {
                                bExiste = true;
                                material = listaMaterial[iX];
                                break;
                            }
                        }
                        if (!bExiste)
                        {
                            cout << "No se encontro el Material." << endl;
                            cout << "Desea intentar con otro Id? (s/n): ";
                            cin >> cOpcion;
                            if (cOpcion != 's' && cOpcion != 'S') break;
                            cout << endl;
                        }
                    }
                    while (!bExiste);

                    if (iIdMaterial == -1 || cOpcion != 's' && cOpcion != 'S' && !bExiste)
                    {
                        cout << "La reservacion ha sido cancelada." << endl;
                        cout << "Regresando al menu..." << endl << endl;
                        break;
                    }

                    do
                    {
                        cout << "Ingrese la fecha en que desea reservar:" << endl;
                        cin >> fecha;
                        cout << endl;
                        iDia = fecha.getDia();
                        iMes = fecha.getMes();
                        iAno = fecha.getAno();
                        bEsValido =  ((1 <= iDia && iDia <= 31) &&
                                    (1 <= iMes && iMes <= 12) &&
                                    (0 <= iAno && iAno <= 99)) ?
                                        (iMes == 1 || iMes == 3 ||
                                        iMes == 5 || iMes == 7 ||
                                        iMes == 8 || iMes == 10 ||
                                        iMes == 12) ?
                                            1 :
                                            iMes == 2 ?
                                                iAno % 4 == 0 ?
                                                    iDia <= 29 :
                                                    iDia <= 28 :
                                                (iMes == 4 || iMes == 6 ||
                                                iMes == 9 || iMes == 11) ?
                                                    iDia <= 30 :
                                                    0 :
                                        0;

                        bEstaOcupado = false;

                        if (!bEsValido)
                        {
                            cout << "La fecha ingresada no es valida." << endl;
                            cout << "Desea intentar con otra fecha? (s/n): ";
                            cin >> cOpcion;
                            if (cOpcion != 's' && cOpcion != 'S') break;
                            cout << endl;
                            continue;
                        }

                        for (iX = 0; iX < iContadorListaReservaciones; ++iX)
                        {
                            if (listaReservaciones[iX].getIdMaterial() == iIdMaterial && listaReservaciones[iX].getFechaReservacion() <= fecha && fecha <= listaReservaciones[iX].calculaFechaFinReserva(material -> cantidadDeDiasDePrestamo()))
                            {
                                bEstaOcupado = true;
                                cout << "El Material esta ocupado de " << listaReservaciones[iX].getFechaReservacion() << " a " << listaReservaciones[iX].calculaFechaFinReserva(material -> cantidadDeDiasDePrestamo()) << '.' << endl << endl;
                                break;
                            }
                        }
                        if (bEstaOcupado)
                        {
                            cout << "Desea intentar con otra fecha? (s/n): ";
                            cin >> cOpcion;
                            if (cOpcion != 's' && cOpcion != 'S') break;
                            cout << endl;
                        }
                    }
                    while (!bEsValido || bEstaOcupado);

                    if (cOpcion != 's' && cOpcion != 'S' && (!bEsValido || bEstaOcupado))
                    {
                        cout << "La reservacion ha sido cancelada." << endl;
                        cout << "Regresando al menu..." << endl << endl;
                        break;
                    }

                    listaReservaciones[iContadorListaReservaciones] = Reserva(iIdMaterial, iIdCliente, fecha);
                    ++iContadorListaReservaciones;

                    cout << "El Material se reservo con exito." << endl;
                    cout << "Desea hacer otra reservacion? (s/n): ";
                    cin >> cOpcion;
                    if (cOpcion != 's' && cOpcion != 'S')
                    {
                        cout << "Regresando al menu..." << endl << endl;
                        break;
                    }
                    cout << endl;
                }
                while (cOpcion == 's' || cOpcion == 'S');
                break;

            case 'f':
            case 'F':
                ofReserva.open("Reserva.txt", ios::app);
                for (iX = iReservasEnArchivo; iX < iContadorListaReservaciones; ++iX)
                {
                    ofReserva << listaReservaciones[iX].getFechaReservacion().getDia() << ' ' << listaReservaciones[iX].getFechaReservacion().getMes() << ' ';
                    if (listaReservaciones[iX].getFechaReservacion().getAno() < 10)
                    {
                        ofReserva << "200" << listaReservaciones[iX].getFechaReservacion().getAno() << ' ';
                    }
                    else
                    {
                        ofReserva << "20" << listaReservaciones[iX].getFechaReservacion().getAno() << ' ';
                    }
                    ofReserva << listaReservaciones[iX].getIdMaterial() << ' ' << listaReservaciones[iX].getIdCliente() << '\n';
                }
                ofReserva.close();

                cout << "Adios! :)" << endl << endl;
                break;

            default:
                cout << "La opcion ingresada no es valida." << endl;
                cout << "Intente ingresar otra opcion (f para terminar)." << endl << endl;
                break;
        }
    }
    while (cOpcion != 'f' && cOpcion != 'F');

    return 0;
}
