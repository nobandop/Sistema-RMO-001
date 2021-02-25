#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Producto.h"
#include "Proveedor.h"
#include "Cliente.h"
#include "Factura.h"
#include "Reporte.h"
using namespace std;

class Producto;
class Proveedor;
class Cliente;
class Factura;
class Reporte;

class Controlador
{
    private:
        char nombre[10];
        char nomusuario[10];
        char contrasenia[10];
        Producto* productos[100];
        Proveedor* proveedores[100];
        Cliente* clientes[100];
        Factura* facturas[100];
        Reporte* reportes[100];
    public:
        Controlador();
        void actualizarNombre();
        void actualizarNomUsuario();
        void actualizarContrasenia();
        void ordenar();
        void buscar();
};

#endif // CONTROLADOR_H
