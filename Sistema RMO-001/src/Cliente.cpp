#include "Cliente.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

Cliente::Cliente(){
    strcpy(codigoCliente,"-");
    strcpy(nombreCliente,"-");
    strcpy(dniCliente,"00000000");
    strcpy(telefonoCliente,"000000000");
    nFacturas = 0;
}

void Cliente::asignarFactura(Factura* fact){
    facturas[nFacturas] = fact;
    nFacturas = nFacturas +1;
}

void Cliente::leerCliente(){
	cout<<"Codigo (Ejm.: cli-001): "; fflush(stdin); gets(codigoCliente);
	cout<<"Nombre completo: "; gets(nombreCliente);
	cout<<"DNI: "; gets(dniCliente);
	cout<<"Telefono: "; gets(telefonoCliente);
}

void Cliente::modificarCliente(int n){
    switch(n){
		case 1: cout<<"Codigo (Ejm: cli-001): "; fflush(stdin); gets(codigoCliente); cout<<"Modificacion exitosa."<<endl; break;
		case 2: cout<<"Nombre completo: "; fflush(stdin); gets(nombreCliente); cout<<"Modificacion exitosa."<<endl; break;
		case 3: cout<<"DNI: "; fflush(stdin); gets(dniCliente); cout<<"Modificacion exitosa."<<endl; break;
		case 4: cout<<"Telefono: "; fflush(stdin); gets(telefonoCliente); cout<<"Modificacion exitosa."<<endl; break;
		default: cout<<"Opción incorrecta."; break;
	}
}

void Cliente::mostrarCliente(){
    cout<<"| "<<left;
    cout<<setw(12)<<codigoCliente<<"| ";
    cout<<setw(40)<<nombreCliente<<"| ";
    cout<<setw(15)<<dniCliente<<"| ";
    cout<<setw(15)<<telefonoCliente<<"|";
	cout<<endl;
}

char* Cliente::getNomCliente(){
    return nombreCliente;
}
