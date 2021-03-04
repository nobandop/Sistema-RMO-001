#include "Proveedor.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>

using namespace std;

Proveedor::Proveedor(){
    codigoProveedor="-";
    nombreProveedor="-";
    strcpy(rucProveedor,"-");
    strcpy(telefonoProveedor,"-");
    strcpy(direccionProveedor,"-");
}

void Proveedor::leerProveedor(){
    cout<<"Codigo (Ejm.: PROV-001): "; cin>>codigoProveedor;
	cout<<"Nombre: "; cin>>nombreProveedor;
	cout<<"RUC: "; fflush(stdin);gets(rucProveedor);
	cout<<"Telefono: "; gets(telefonoProveedor);
	cout<<"Direccion: "; gets(direccionProveedor);
}

void Proveedor::mostrarProveedor(){
    cout<<left<<"| ";
    cout<<setw(15)<<codigoProveedor<<"| ";
    cout<<setw(20)<<nombreProveedor<<"| ";
    cout<<setw(15)<<rucProveedor<<"| ";
    cout<<setw(15)<<telefonoProveedor<<"| ";
    cout<<setw(40)<<direccionProveedor<<"| ";
    cout<<endl;
}

void Proveedor::modificarProveedor(int n){
    switch(n){
		case 1: cout<<"Codigo (Ejm: PROV-001): "; cin>>codigoProveedor; cout<<"Modificacion exitosa."<<endl; break;
		case 2: cout<<"Nombre: "; cin>>nombreProveedor; cout<<"Modificacion exitosa."<<endl; break;
		case 3: cout<<"RUC: "; fflush(stdin); gets(rucProveedor); cout<<"Modificacion exitosa."<<endl; break;
		case 4: cout<<"Telefono: "; fflush(stdin); gets(telefonoProveedor); cout<<"Modificacion exitosa."<<endl; break;
		case 5: cout<<"Direccion: "; fflush(stdin); gets(direccionProveedor); cout<<"Modificacion exitosa."<<endl; break;
		default: cout<<"Opción incorrecta."; break;
	}
}

string Proveedor::getCodigo(){return codigoProveedor;}
string Proveedor::getNombre(){return nombreProveedor;}
