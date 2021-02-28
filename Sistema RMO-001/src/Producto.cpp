#include "Producto.h"
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>

using namespace std;

Producto::Producto(){
    strcpy(codigoProducto,"-");
    strcpy(nombreProducto,"-");
    strcpy(categoriaProducto,"-");
    cantidadProducto = 0;
    precioProducto = 0;
}

void Producto::leerProducto(){
    cout<<"Codigo (Ejm.: PROD-001): "; fflush(stdin); gets(codigoProducto);
	cout<<"Nombre: "; gets(nombreProducto);
	cout<<"Categoria: "; gets(categoriaProducto);
	cout<<"Cantidad: "; cin.sync(); cin>>cantidadProducto;
	cout<<"Precio Unitario: "; cin.sync(); cin>>precioProducto;
}

void Producto::mostrarProducto(){
    cout<<left<<"| ";
    cout<<setw(15)<<codigoProducto<<"| ";
    cout<<setw(25)<<nombreProducto<<"| ";
    cout<<setw(15)<<cantidadProducto<<"| ";
    cout<<setw(20)<<categoriaProducto<<"| ";
    cout<<setw(15)<<precioProducto<<"| ";
    cout<<setw(20)<<proveedor->getNomProveedor()<<"|";
    cout<<endl;
}

void Producto::modificarProducto(int n){
    switch(n){
		case 1: cout<<"Codigo (Ejm: 001): "; fflush(stdin); gets(codigoProducto); cout<<"Modificacion exitosa."<<endl; break;
		case 2: cout<<"Nombre: "; fflush(stdin); gets(nombreProducto); cout<<"Modificacion exitosa."<<endl; break;
		case 3: cout<<"Cantidad: "; cin>>cantidadProducto; cout<<"Modificacion exitosa."<<endl; break;
		case 4: cout<<"Categoria: "; fflush(stdin); gets(categoriaProducto); cout<<"Modificacion exitosa."<<endl; break;
		case 5: cout<<"Precio Unitario: "; cin>>precioProducto; cout<<"Modificacion exitosa."<<endl; break;
		case 6: cout<<"Proveedor: "; break;
		default: cout<<"Opción incorrecta."; break;
	}
}

void Producto::asignarProveedor(Proveedor *p1){proveedor = p1;}
