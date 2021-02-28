#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "Factura.h"
using namespace std;

class Factura;
class Cliente{
    private:
        char codigoCliente[7];
        char nombreCliente[40];
        char dniCliente[8];
        char telefonoCliente[9];
        Factura *facturas[50];
        int nFacturas;
    public:
        Cliente();
        void asignarFactura(Factura*);
        void leerCliente();
        void modificarCliente(int);
        void mostrarCliente();
        char* getNomCliente();
};

#endif // CLIENTE_H
