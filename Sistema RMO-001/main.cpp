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
    Producto listaProductos[50];
    Cliente listaClientes[50];
    Proveedor listaProveedores[50];
	Factura listaFacturas[50];
	Reporte listaReportes[20];
	int nProductos=0,nClientes=0,nProveedores=0,nFacturas=0,nReportes=0;

	bool salida = false;
	int equivocacion=0,opc1,opc2,resp1;
	char nomu[20],contra[20];

	do{
        titulo();
		cout<<"Ingrese su nombre de usuario: "; fflush(stdin); gets(nomu);
		cout<<"Ingrese su contrasenia: "; fflush(stdin); gets(contra);
		if(principal.verificarAcceso(nomu,contra) == true){
            cout<<"Acceso concedido."<<endl;
            do{
                titulo();
                cout<<"1. Inventario"<<endl;
                cout<<"2. Ventas"<<endl;
                cout<<"3. Reportes"<<endl;
                cout<<"4. Datos del usuario"<<endl;
                cout<<"5. Salir"<<endl;
                cout<<"Elija una opcion: "; cin>>opc1;
                switch(opc1){
                    case 1:                                     //INVENTARIO
                        system("cls");
                        cout<<"Opcion: Inventario."<<endl;
                        cout<<"----------------------------"<<endl;
                        cout<<"1. Registrar Productos"<<endl;
                        cout<<"2. Ver Lista de Productos"<<endl;
                        cout<<"3. Registrar Proveedor"<<endl;
                        cout<<"4. Ver Lista de Proveedores"<<endl;
                        cout<<"5. Salir"<<endl;
                        cout<<"Elija una opcion: "; cin>>opc2;
                        switch(opc2){
                            case 1:
                                system("cls");
                                cout<<"Opcion: Registrar Productos."<<endl;
                                cout<<"-----------------------------"<<endl;
                                listaProductos[nProductos].leerProducto();
                                cout<<"Ahora ingrese el numero del proveedor que asignara: "<<endl;
                                cout<<left;
                                cout<<setw(15)<<"Codigo";
                                cout<<setw(30)<<"Nombre";
                                cout<<setw(20)<<"RUC";
                                cout<<setw(15)<<"Telefono";
                                cout<<setw(40)<<"Direccion";
                                cout<<endl;
                                for(int i = 0; i < nProveedores; i++){
									listaProveedores[i].mostrarProveedor();
								}
                                cout<<"Respuesta: ";cin>>resp1;
                                listaProductos[nProductos].asignarProveedor(&listaProveedores[nProveedores]);
                                system("pause");
                            break;
                            case 2:
                            break;
                            case 3:
                            break;
                            case 4:
                            break;
                            case 5: break;
                            default: cout<<"\nNo ingreso una opcion correcta."<<endl; system("pause"); break;
                        }
                    break;
                    case 2:                                     //VENTAS
                        system("cls");
                        cout<<"Opcion: Ventas."<<endl;
                        cout<<"-------------------------"<<endl;
                        cout<<"1. Registrar Factura"<<endl;
                        cout<<"2. Ver Lista de Facturas"<<endl;
                        cout<<"3. Registrar Clientes"<<endl;
                        cout<<"4. Ver Lista de Clientes"<<endl;
                        cout<<"5. Modificar Clientes"<<endl;
                        cout<<"6. Salir"<<endl;
                        cout<<"Elija una opcion: "; cin>>opc2;
                        switch(opc2){
                            case 1:
                            break;
                            case 2:
                            break;
                            case 3:
                            break;
                            case 4:
                            break;
                            case 5:
                            break;
                            case 6: break;
                            default: cout<<"\nNo ingreso una opcion correcta."<<endl; system("pause"); break;
                        }
                    break;
                    case 3:                                     //REPORTES
                        system("cls");
                        cout<<"Opcion: Reportes."<<endl;
                        cout<<"-------------------------"<<endl;
                        cout<<"1. Generar Reporte"<<endl;
                        cout<<"2. Ver Lista de Reportes"<<endl;
                        cout<<"3. Salir"<<endl;
                        cout<<"Elija una opcion: "; cin>>opc2;
                        switch(opc2){
                            case 1:
                            break;
                            case 2:
                            break;
                            case 3:
                            break;
                            default: cout<<"\nNo ingreso una opcion correcta."<<endl; system("pause"); break;
                        }
                    break;
                    case 4:                                     //DATOS DEL USUARIO
                        system("cls");
                        cout<<"Opcion: Datos de usuario."<<endl;
                        cout<<"-------------------------"<<endl;
                        cout<<"1. Actualizar Nombres y Apellidos"<<endl;
                        cout<<"2. Actualizar Nombre de Usuario"<<endl;
                        cout<<"3. Actualizar Contrasenia"<<endl;
                        cout<<"4. Salir"<<endl;
                        cout<<"Elija una opcion: "; cin>>opc2;
                        switch(opc2){
                            case 1:
                            break;
                            case 2:
                            break;
                            case 3:
                            break;
                            case 4: break;
                            default: cout<<"\nNo ingreso una opcion correcta."<<endl; system("pause"); break;
                        }
                    break;
                    case 5: salida=true; system("pause"); break;
                    default: cout<<"\nNo ingreso una opcion correcta."<<endl; system("pause"); break;
                }
            }while(salida==false);
		}else{
		    equivocacion = equivocacion + 1;
            if(equivocacion==3){
                cout<<"\nAcceso denegado, se supero el numero de intentos permitidos, se procedera a cerrar el programa."<<endl;
            }else{
                cout<<"\nAcceso denegado, vuelva a intentarlo."<<endl;
            }
            system("pause");
		}
	}while((equivocacion!=3)&&(salida==false));

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
