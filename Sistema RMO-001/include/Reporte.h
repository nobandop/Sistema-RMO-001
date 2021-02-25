#ifndef REPORTE_H
#define REPORTE_H

#include <Controlador.h>

class Reporte
{
    private:
        Factura* facturas[100];
    public:
        Reporte();
        void generarReporte();
        void mostrarReporte();
};

#endif // REPORTE_H
