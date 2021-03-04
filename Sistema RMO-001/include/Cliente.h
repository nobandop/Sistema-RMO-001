#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string.h>
#include "Factura.h"
using namespace std;

class Factura;
class Cliente{
    private:
        string codigoCliente;
        string nombreCliente;
        string dniCliente;
        string telefonoCliente;
        Factura *facturas[50];
        int nFacturas;
    public:
        Cliente();
        void asignarFactura(Factura*);
        void leerCliente();
        void modificarCliente(int);
        void mostrarCliente();
        string getNomCliente();
};

#endif // CLIENTE_H
