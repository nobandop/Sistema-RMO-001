#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <Producto.h>
#include <Proveedor.h>
#include <Cliente.h>
#include <Factura.h>
#include <Reporte.h>

class Controlador
{
    private:
        char nombre[10];
        char nomusuario[10];
        char contraseña[10];
        Producto* productos[100];
        Proveedor* proveedores[100];
        Cliente* clientes[100];
        Factura* facturas[100];
        Reporte* reportes[100];
    public:
        Controlador();
        void actualizarNombre();
        void actualizarNomUsuario();
        void actualizarContraseña();
        void ordenar();
        void buscar();
};

#endif // CONTROLADOR_H
