#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <Controlador.h>

class Proveedor
{
    private:
        char codigoProveedor[10];
        char nombreProveedor[30];
        char rucProveedor[20];
        char telefonoProveedor[10];
        char direccionProveedor[20];
    public:
        Proveedor();
        void leerProveedor();
        void mostrarProveedor();
        void modificarProveedor();
        char* getNomProveedor();
};

#endif // PROVEEDOR_H
