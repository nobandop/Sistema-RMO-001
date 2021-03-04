#include "Producto.h"
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>

using namespace std;

Producto::Producto(){
    codigoProducto = "-";
    nombreProducto = "-";
    categoriaProducto = "-";
    cantidadProducto = 0;
    precioProducto = 0;
}

void Producto::leerProducto(){
    cout<<"Codigo (Ejm.: PROD-001): "; cin>>codigoProducto;
	cout<<"Nombre: "; cin>>nombreProducto;
	cout<<"Categoria: "; fflush(stdin); cin>>categoriaProducto;
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
    cout<<setw(20)<<proveedor->getNombre()<<"|";
    cout<<endl;
}

void Producto::modificarProducto(int n){
    switch(n){
		case 1: cout<<"Codigo (Ejm.: PROD-001): "; cin>>codigoProducto; cout<<"Modificacion exitosa."<<endl; break;
		case 2: cout<<"Nombre: "; cin>>nombreProducto; cout<<"Modificacion exitosa."<<endl; break;
		case 3: cout<<"Cantidad: "; cin>>cantidadProducto; cout<<"Modificacion exitosa."<<endl; break;
		case 4: cout<<"Categoria: "; cin>>categoriaProducto; cout<<"Modificacion exitosa."<<endl; break;
		case 5: cout<<"Precio Unitario: "; cin>>precioProducto; cout<<"Modificacion exitosa."<<endl; break;
		case 6: cout<<"Proveedor: "; break;
		default: cout<<"Opción incorrecta."; break;
	}
}

void Producto::asignarProveedor(Proveedor *p1){proveedor = p1;}

void Producto::actualizarCantProductos(int c){cantidadProducto = cantidadProducto - c;}

void Producto::agregarCantSolicitada(int c){cantidadSolicitada = c;}

void Producto::agregarSubTotal(int c){subtotal = precioProducto * c;}

string Producto::getCodigo(){return codigoProducto;}

string Producto::getNombre(){return nombreProducto;}

int Producto::getCantProducto(){return cantidadProducto;}

int Producto::getCantsolicitada(){return cantidadSolicitada;}

float Producto::getPrecio(){return precioProducto;}

float Producto::getSubTotal(){return subtotal;}
