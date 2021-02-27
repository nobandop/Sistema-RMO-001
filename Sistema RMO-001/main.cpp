#include <iostream>
#include <string.h>
#include <iomanip>
#include "Cliente.h"
#include "Controlador.h"
#include "Factura.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Reporte.h"

using namespace std;

void titulo();

int main(){
    Controlador principal;
    Producto listaProductos[20];
    Cliente listaClientes[20];
    Proveedor listaProveedores[20];
	Factura listaFacturas[20];

	bool salida = false;
	int opc1;

	do{
        titulo();
		cout<<"1. Inventario"<<endl;
		cout<<"2. Ventas"<<endl;
		cout<<"3. Reportes"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"Elija una opcion: "; cin>>opc1; system("pause");
        switch(opc1){
            case 1:
                system("cls");
                cout<<"Opcion: Inventario."<<endl;
                cout<<"--------------------"<<endl;
                cout<<"1. Registrar Productos"<<endl;
                cout<<"2. Ver lista de Productos"<<endl;
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
        }
	}while(salida == false);

    return 0;
}

void titulo(){
	system("cls");
	cout<<"---------------------------------------------------------"<<endl;
	cout<<left<<setw(50)<<"|\tSistema de Gestion de productos RMO-001"<<"|"<<endl;
	cout<<left<<setw(56)<<"| Nombre del Supermercado: Tienda Los Angeles"<<right<<"|"<<endl;
	cout<<left<<setw(56)<<"| Version del sistema: "<<right<<"|"<<endl;    //falta cambiar la version
	cout<<left<<setw(56)<<"| Empresa creadora: RMO Software"<<right<<"|"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
}
