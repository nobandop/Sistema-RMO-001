#include "Reporte.h"
#include "Factura.h"
#include <iostream>
#include <string.h>

using namespace std;

Reporte::Reporte()
{
    nFacturas = 0;
}

void Reporte::generarReporte(int nFac)
{
    for(int i = 1; i <= nFac; i++){
        factura[i]->mostrarFactura();
    }
}

void Reporte::mostrarReporte()
{
    
}