#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <iostream>
using namespace std;

class Proveedor{
    private:
        char codigoProveedor[8];
        char nombreProveedor[30];
        char rucProveedor[20];
        char telefonoProveedor[9];
        char direccionProveedor[40];
    public:
        Proveedor();
        void leerProveedor();
        void mostrarProveedor();
        void modificarProveedor(int);
        char* getNomProveedor();
};

#endif // PROVEEDOR_H
