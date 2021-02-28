#include "Proveedor.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>

using namespace std;

Proveedor::Proveedor()
{
    strcpy(codigoProveedor,"-");
    strcpy(nombreProveedor,"-");
    strcpy(rucProveedor,"-");
    strcpy(telefonoProveedor,"-");
    strcpy(direccionProveedor,"-");
}

void Proveedor::leerProveedor()
{
    cout<<endl<<"Leer Proveedor"<<endl<<endl;
    cout<<"Ingrese el codigo: ";cin.sync();gets(codigoProveedor);
    cout<<"Ingrese el nombre: ";cin.sync();gets(nombreProveedor);
    cout<<"Ingrese el RUC: ";cin.sync();gets(rucProveedor);
    cout<<"Ingrese el telefono: ";cin.sync();cin>>telefonoProveedor;
    cout<<"Ingrese la direccion: ";cin.sync();cin>>direccionProveedor;
}

void Proveedor::mostrarProveedor()
{
    cout<<"Codigo: "<<codigoProveedor<<endl;
    cout<<"Nombre: "<<nombreProveedor<<endl;
    cout<<"RUC: "<<rucProveedor<<endl;
    cout<<"telefono: "<<telefonoProveedor<<endl;
    cout<<"direccion: "<<direccionProveedor<<endl;

    cout<<left;
    cout<<setw(15)<<codigoProveedor;
    cout<<setw(30)<<nombreProveedor;
    cout<<setw(20)<<rucProveedor;
    cout<<setw(15)<<telefonoProveedor<<"| ";
    cout<<setw(40)<<direccionProveedor<<"|";
    cout<<endl;
}

void Proveedor::modificarProveedor()
{
    cout<<"en proceso..."<<endl;
    system("pause");
}

char* Proveedor::getNomProveedor()
{
    return nombreProveedor;
}