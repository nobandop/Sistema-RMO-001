#include "Cliente.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

Cliente::Cliente(){
    codigoCliente="-";
    nombreCliente="-";
    dniCliente="00000000";
    telefonoCliente="000000000";
    nFacturas = 0;
}

void Cliente::asignarFactura(Factura* fact){
    facturas[nFacturas] = fact;
    nFacturas = nFacturas +1;
}

void Cliente::leerCliente(){
	cout<<"Codigo (Ejm.: cli-001): "; cin>>codigoCliente;
	cout<<"Nombre completo: "; cin>>nombreCliente;
	cout<<"DNI: "; cin>>dniCliente;
	cout<<"Telefono: "; cin>>telefonoCliente;
}

void Cliente::modificarCliente(int n){
    switch(n){
		case 1: cout<<"Codigo (Ejm: cli-001): "; cin>>codigoCliente; cout<<"Modificacion exitosa."<<endl; break;
		case 2: cout<<"Nombre completo: "; cin>>nombreCliente; cout<<"Modificacion exitosa."<<endl; break;
		case 3: cout<<"DNI: "; cin>>dniCliente; cout<<"Modificacion exitosa."<<endl; break;
		case 4: cout<<"Telefono: "; cin>>telefonoCliente; cout<<"Modificacion exitosa."<<endl; break;
		default: cout<<"Opcion incorrecta."; break;
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

string Cliente::getNomCliente(){return nombreCliente;}
