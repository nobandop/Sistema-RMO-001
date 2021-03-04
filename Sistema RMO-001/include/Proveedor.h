#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <iostream>
using namespace std;

class Proveedor{
    private:
        string codigoProveedor;
        string nombreProveedor;
        char rucProveedor[20];
        char telefonoProveedor[12];
        char direccionProveedor[40];
    public:
        Proveedor();
        void leerProveedor();
        void mostrarProveedor();
        void modificarProveedor(int);
        string getNomProveedor();
};

#endif // PROVEEDOR_H
