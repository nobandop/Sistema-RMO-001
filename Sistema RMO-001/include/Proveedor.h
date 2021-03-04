#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <iostream>
using namespace std;

class Proveedor{
    private:
        string codigoProveedor;
        string nombreProveedor;
        string rucProveedor;
        string telefonoProveedor;
        string direccionProveedor;
    public:
        Proveedor();
        void leerProveedor();
        void mostrarProveedor();
        void modificarProveedor(int);
        string getCodigo();
        string getNombre();
};

#endif // PROVEEDOR_H
