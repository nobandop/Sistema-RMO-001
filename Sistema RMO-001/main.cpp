#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

int main(){
    Controlador principal;
    Producto listaProductos[20];
    Cliente listaClientes[20];
    Proveedor listaProveedores[20];
	Factura listaFacturas[20];

	bool salida = false;

	do{
        titulo();
        cout<<"1. Productos."<<endl;
		cout<<"2. Clientes."<<endl;
		cout<<"3. Proveedores."<<endl;
		cout<<"4. Facturacion."<<endl;
		cout<<"5. Reporte."<<endl;
		cout<<"6. Salir."<<endl;

		cout<<"1. Inventario"<<endl;
		cout<<"2. Ventas"<<endl;
		cout<<"3. Reportes"<<endl;

	}while(salida == false);

    return 0;
}

void titulo(){
	system("cls");
	cout<<"\tSistema de Gestion de productos RMO-001"<<endl;
	cout<<"Nombre del Supermercado: Tienda Los Angeles"<<endl;
	cout<<"Version del sistema: "<<endl;    //falta cambiar la version
	cout<<"Empresa creadora: RMO Software"<<endl;
	cout<<"------------------------------------------------"<<endl;
}
