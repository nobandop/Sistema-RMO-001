#ifndef REPORTE_H
#define REPORTE_H

#include <iostream>
#include <string.h>
#include "Factura.h"
using namespace std;

class Reporte
{
    private:
        int nFacturas;
        Factura* factura[100];
    public:
        Reporte();
        void generarReporte(int);
        void mostrarReporte();
};

#endif // REPORTE_H
