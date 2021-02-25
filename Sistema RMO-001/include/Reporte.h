#ifndef REPORTE_H
#define REPORTE_H

#include <iostream>
#include <string.h>
#include "Factura.h"
using namespace std;

class Factura;

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
