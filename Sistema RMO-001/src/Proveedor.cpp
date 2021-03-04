#include "Proveedor.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>

using namespace std;

Proveedor::Proveedor(){
    codigoProveedor = "-";
    nombreProveedor = "-";
    rucProveedor = "-";
    telefonoProveedor = "-";
    direccionProveedor = "-";
}

void Proveedor::leerProveedor(){
    cout<<"Codigo (Ejm.: PROV-001): "; fflush(stdin); getline(cin,codigoProveedor);
	cout<<"Nombre: "; getline(cin,nombreProveedor);
	cout<<"RUC: "; getline(cin,rucProveedor);
	cout<<"Telefono: "; getline(cin,telefonoProveedor);
	cout<<"Direccion: "; getline(cin,direccionProveedor);
}

void Proveedor::mostrarProveedor(){
    cout<<left<<"| ";
    cout<<setw(15)<<codigoProveedor<<"| ";
    cout<<setw(40)<<nombreProveedor<<"| ";
    cout<<setw(15)<<rucProveedor<<"| ";
    cout<<setw(15)<<telefonoProveedor<<"| ";
    cout<<setw(40)<<direccionProveedor<<"| ";
    cout<<endl;
}

void Proveedor::modificarProveedor(int n){
    switch(n){
		case 1: cout<<"Codigo (Ejm: PROV-001): "; cin>>codigoProveedor; cout<<"Modificacion exitosa."<<endl; break;
		case 2: cout<<"Nombre: "; cin>>nombreProveedor; cout<<"Modificacion exitosa."<<endl; break;
		case 3: cout<<"RUC: "; cin>>rucProveedor; cout<<"Modificacion exitosa."<<endl; break;
		case 4: cout<<"Telefono: "; cin>>telefonoProveedor; cout<<"Modificacion exitosa."<<endl; break;
		case 5: cout<<"Direccion: "; cin>>direccionProveedor; cout<<"Modificacion exitosa."<<endl; break;
		default: cout<<"Opción incorrecta."; break;
	}
}

string Proveedor::getCodigo(){return codigoProveedor;}
string Proveedor::getNombre(){return nombreProveedor;}
