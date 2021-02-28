#include "Factura.h"
#include "string.h"

Factura::Factura(){
    strcpy(codigoFactura,"-");
    strcpy(fechaFactura,"-");
    nProductos = 0;
    subtotal = 0;
}

void Factura::leerFactura(){
    cout<<"Codigo: ";cin.sync();gets(codigoFactura);
    cout<<"Fecha: ";cin.sync();gets(fechaFactura);
}

void Factura::mostrarFactura(){cout<<"| "<<left<<setw(15)<<codigoFactura<<"| "<<setw(40)<<cliente->nombreCliente<<"| "<<setw(15)<<fechaFactura<<"| "<<setw(15)<<subtotal<<"|"<<endl;}

void Factura::asignarCliente(Cliente* c){cliente = c;}