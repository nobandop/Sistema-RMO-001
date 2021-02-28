#include "Factura.h"
#include "string.h"

Factura::Factura()
{
    strcpy(codigoFactura,"-");
    strcpy(fechaFactura,"-");
    nProductos = 0;
    subtotal = 0;
}

void Factura::leerFactura()
{
    cout<<"Codigo: ";cin.sync();gets(codigoFactura);
    cout<<"Fecha: ";cin.sync();gets(fechaFactura);
}
void Factura::asignarCliente(Cliente* c)
{
    cliente = c;
}