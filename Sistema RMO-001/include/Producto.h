#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include "Proveedor.h"
using namespace std;

class Producto{
    private:
        string codigoProducto;
        string nombreProducto;
        char categoriaProducto[20];
        int cantidadProducto;
        float precioProducto;
        int cantidadSolicitada = 0;
        float subtotal = 0;
        Proveedor* proveedor;
    public:
        Producto();
        void leerProducto();
        void mostrarProducto();
        void modificarProducto(int);
        void asignarProveedor(Proveedor*);
        void actualizarCantProductos(int);
        void agregarSubTotal(int);
        void agregarCantSolicitada(int);
        string getCodigo();
        string getNombre();
        int getCantProducto();
        int getCantsolicitada();
        float getPrecio();
        float getSubTotal();
};

#endif // PRODUCTO_H
