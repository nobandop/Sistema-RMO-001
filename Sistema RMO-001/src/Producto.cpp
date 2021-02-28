#include "Producto.h"
#include <iostream>
#include <string.h>
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
    cout<<"Codigo (Ejm.: PRO-001): "; fflush(stdin); gets(codigoProducto);
	cout<<"Nombre: "; fflush(stdin); gets(nombreProducto);
	cout<<"Categoria: "; fflush(stdin); gets(categoriaProducto);
	cout<<"Cantidad: "; cin.sync(); cin>>cantidadProducto;
	cout<<"Precio Unitario: "; cin.sync(); cin>>precioProducto;
}

void Producto::mostrarProducto()
{
    cout<<"Codigo: "<<codigoProducto<<endl;
    cout<<"Nombre: "<<nombreProducto<<endl;
    cout<<"Categoria: "<<categoriaProducto<<endl;
    cout<<"Cantidad: "<<cantidadProducto<<endl;
    cout<<"Precio: "<<precioProducto<<endl;
    cout<<"Proveedor: "<<proveedor->getNomProveedor()<<endl;
}

void Producto::modificarProducto(int n)
{
    cout<<"";
}

void Producto::asignarProveedor(Proveedor *p1){proveedor = p1;}
