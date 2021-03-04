#ifndef FACTURA_H
#define FACTURA_H

#include <iostream>
#include "Cliente.h"
#include "Producto.h"
using namespace std;

class Cliente;
class Factura{
    public:
        string codigoFactura;
        string fechaFactura;
        Cliente* cliente;
        Producto* producto[20];
        int nProductos = 0;
        float totalPagar = 0;
    public:
        Factura();
        void leerFactura();
        void desarrolloFactura(Producto*,int);
        void asignarCliente(Cliente*);
        void productosComprados();
        void mostrarFactura();
        string getCodigo(){return codigoFactura;}
        string getNombreCli(){return cliente;}
        string getFecha(){return fechaFactura;}
        float getMonto(){return totalPagar;}
};

#endif // FACTURA_H
