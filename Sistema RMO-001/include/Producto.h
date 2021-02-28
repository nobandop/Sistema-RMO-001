#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include "Proveedor.h"
using namespace std;

class Producto{
    private:
        char codigoProducto[12];
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
