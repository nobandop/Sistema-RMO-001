#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include <string.h>
#include "Cliente.h"
#include "Producto.h"
using namespace std;

class Factura
{
    private:
        char codigoFactura[10];
        char fechaFactura[10];
        Cliente* cliente;
        Producto* producto[20];
        int nProductos = 0;
        float subtotal = 0;
    public:
        Factura();
        void leerFactura();
        void asignarCliente(Cliente*);
        void productosComprados();
        void mostrarFactura();
};

#endif // FACTURA_H
