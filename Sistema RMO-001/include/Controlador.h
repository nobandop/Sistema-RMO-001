#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>
#include "Producto.h"
#include "Proveedor.h"
#include "Cliente.h"
#include "Factura.h"
using namespace std;

class Producto;
class Proveedor;
class Cliente;
class Factura;
class Reporte;
class Controlador{
    private:
        char nombre[30];
        char nomusuario[20];
        char contrasenia[15];
        Producto* productos[100];
        Proveedor* proveedores[100];
        Cliente* clientes[100];
        Factura* facturas[100];
        Reporte* reportes[100];
    public:
        Controlador();
        bool verificarAcceso(char*,char*);
        void asignarDatos();
        void actualizarNombre(char*);
        void actualizarNomUsuario(char*);
        void actualizarContrasenia(char*);
        void ordenar();
        void buscar();
};

#endif // CONTROLADOR_H
