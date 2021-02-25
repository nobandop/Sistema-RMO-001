#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <string.h>
#include "Cliente.h"
#include "Producto.h"
using namespace std;

class Cliente;
class Producto;

class Factura
{
    private:
        char codigoFactura[10];
        char fechaFactura[10];
        int nProductos;
        Cliente* cliente;
        Producto* productos[100];
        float subtotal;
    public:
        Factura();
        void generarFactura();
        void mostrarFactura();
};

#endif // FACTURA_H
