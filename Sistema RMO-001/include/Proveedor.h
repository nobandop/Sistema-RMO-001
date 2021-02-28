#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <iostream>
#include <string.h>
using namespace std;

class Proveedor
{
    private:
        char codigoProveedor[15];
        char nombreProveedor[30];
        char rucProveedor[20];
        char telefonoProveedor[15];
        char direccionProveedor[40];
    public:
        Proveedor();
        void leerProveedor();
        void mostrarProveedor();
        void modificarProveedor();
        char* getNomProveedor();
};

#endif // PROVEEDOR_H
