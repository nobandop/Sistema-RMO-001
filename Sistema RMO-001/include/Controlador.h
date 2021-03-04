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
        int nProd = 0;
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
        void asignarProducto(Producto*);
        void ordenarProductos();
        void buscar();
};

#endif // CONTROLADOR_H
