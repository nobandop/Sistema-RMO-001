#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string.h>
#include "Factura.h"
using namespace std;

class Factura;

class Cliente
{
    private:
        char codigoCliente[10];
        char nombrecompletoCliente[30];
        char dniCliente[10];
        char rucCliente[10];
        char telefonoCliente[10];
        Factura* facturas[100];
        int nFacturas;
    public:
        Cliente();
        void leerCliente();
        void modificarCliente();
        void mostrarCliente();
        void verFacturas();
};

#endif // CLIENTE_H
