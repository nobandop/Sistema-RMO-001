#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>
#include <string.h>
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
        string nombre;
        string nomusuario;
        string contrasenia;
        Producto* productos[100];
        int nProductos;
        Proveedor* proveedores[100];
        Cliente* clientes[100];
        Factura* facturas[100];
        Reporte* reportes[100];
    public:
        Controlador();
        bool verificarAcceso(string,string);
        void actualizarNombre(string);
        void actualizarNomUsuario(string);
        void actualizarContrasenia(string);
        void asignarProductos(Producto *);
        void ordenarProductos();
        void buscar();
        int cadenaNum(string);
};

#endif // CONTROLADOR_H
