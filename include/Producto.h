#ifndef PRODUCTO_H
#define PRODUCTO_H

#include<Proveedor.h>

class Producto
{
    private:
        char codigoProducto[10];
        char nombreProducto[10];
        char categoriaProducto[10];
        int cantidadProducto;
        float precioProducto;
        Proveedor* proveedor;
    public:
        Producto();
        void leerProducto();
        void mostrarProducto();
        void modificarProducto();
};

#endif // PRODUCTO_H
