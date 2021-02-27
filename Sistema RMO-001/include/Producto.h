#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string.h>
#include "Proveedor.h"
using namespace std;

class Proveedor;

class Producto
{
    private:
        char codigoProducto[7];
        char nombreProducto[30];
        char categoriaProducto[20];
        int cantidadProducto;
        float precioProducto;
        Proveedor* proveedor;
    public:
        Producto();
        void leerProducto();
        void mostrarProducto();
        void modificarProducto(int);
        void asignarProveedor(Proveedor*);
};

#endif // PRODUCTO_H
