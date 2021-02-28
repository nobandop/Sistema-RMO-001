#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include "Cliente.h"
#include "Controlador.h"
#include "Factura.h"
#include "Producto.h"
#include "Proveedor.h"

using namespace std;

void titulo();

int main(){
    Controlador principal;
    Producto listaProductos[50];
    Cliente listaClientes[50];
    Proveedor listaProveedores[50];
	Factura listaFacturas[50];
	Reporte listaReporte;
	int nProductos=0,nClientes=0,nProveedores=0,nFacturas=0,nReportes=0,a;

	bool salida = false;
	int equivocacion=0,opc1,opc2,resp1,f,c;
	char nombre[30],nomu[20],contra[20],h;

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
                cout<<"3. Datos del usuario"<<endl;
                cout<<"4. Salir"<<endl;
                cout<<"Elija una opcion: "; cin>>opc1;
                switch(opc1){
                    case 1:                                     //INVENTARIO
                        system("cls");
                        cout<<"===================="<<endl;
                        cout<<"|Opcion: Inventario|"<<endl;
                        cout<<"===================="<<endl;
                        cout<<"1. Registrar Productos"<<endl;
                        cout<<"2. Ver Lista de Productos"<<endl;
                        cout<<"3. Registrar Proveedor"<<endl;
                        cout<<"4. Ver Lista de Proveedores"<<endl;
                        cout<<"5. Salir"<<endl;
                        cout<<"Elija una opcion: "; cin>>opc2;
                        switch(opc2){
                            case 1:
                                system("cls");                       //REGISTRAR PRODUCTOS
                                cout<<"============================="<<endl;
                                cout<<"|Opcion: Registrar Productos|"<<endl;
                                cout<<"============================="<<endl;
                                listaProductos[nProductos].leerProducto();
                                if(nProveedores == 0){        //si no existen proveedores
                                    cout<<"\nNo se han registrado proveedores aun."<<endl;
                                    cout<<"Ingrese los datos del proveedor: "<<endl;
                                    listaProveedores[nProveedores].leerProveedor();
                                    listaProductos[nProductos].asignarProveedor(&listaProveedores[nProveedores]);
                                    nProveedores++;
                                }else{      //si existen 1 o mas proveedores
                                    cout<<"\nAsigne un proveedor de la lista de proveedores."<<endl;
                                    cout<<left<<setw(3)<<"#"<<setw(17)<<"| Codigo"<<setw(22)<<"| Nombre"<<setw(17)<<"| RUC"<<setw(17)<<"| Telefono"<<setw(42)<<"| Direccion"<<"|"<<endl;
                                    for(int i = 0; i <= 118; i++){cout<<"=";} cout<<endl;
                                    for(int i = 0; i < nProveedores; i++){
                                        cout<<left<<setw(3)<<i+1;
                                        listaProveedores[i].mostrarProveedor();
                                    }
                                    cout<<endl;
                                    if(nProveedores == 1){      //cuando hay un solo proveedor
                                        cout<<"\nDesea asignar al producto el proveedor mostrado? [S/N]: "; cin>>h; //h=si o no
                                        if(h=='S'||h=='s'){
                                            listaProductos[nProductos].asignarProveedor(&listaProveedores[nProveedores-1]);
                                            cout<<"\nRegistro exitoso."<<endl;
                                        }else{
                                            cout<<"Ingrese los datos del proveedor: "<<endl;
                                            listaProveedores[nProveedores].leerProveedor();
                                            listaProductos[nProductos].asignarProveedor(&listaProveedores[nProveedores]);
                                            nProveedores++;
                                        }
                                    }else if(nProductos>1){     //cuando hay varios
                                        cout<<"\nDesea asignar al producto alguno de los proveedores que se muestran? [S/N]: "; cin>>h;
                                        if(h=='S'||h=='s'){
                                            cout<<"\nDigite el numero del proveedor que desea asignar al producto: "; cin>>a;       //a = variable ocasional de decision
                                            listaProductos[nProductos].asignarProveedor(&listaProveedores[a-1]);
                                            cout<<"\nRegistro exitoso."<<endl;
                                        }else{
                                            cout<<"Ingrese los datos del proveedor: "<<endl;
                                            listaProveedores[nProveedores].leerProveedor();
                                            listaProductos[nProductos].asignarProveedor(&listaProveedores[nProveedores]);
                                            nProveedores++;
                                        }
                                    }
						        }
                                nProductos++;
                                system("pause");
                            break;
                            case 2:                     //VER LISTA Y MODIFICAR PRODUCTOS
                                system("cls");
                                cout<<"================================="<<endl;
                                cout<<"|Opcion: Ver Lista de  Productos|"<<endl;
                                cout<<"================================="<<endl<<"\n";
                                cout<<left<<setw(17)<<"| Codigo (1)"<<setw(27)<<"| Nombre (2)"<<setw(17)<<"| Cantidad (3)"<<setw(22)<<"| Categoria (4)"<<setw(17)<<"| Precio (5)"<<setw(22)<<"| Proveedor (6)"<<"|"<<endl;
								for(int i = 0; i <= 122; i++){cout<<"=";}
								cout<<endl;
								for(int i = 0; i < nProductos; i++){listaProductos[i].mostrarProducto();}
                                cout<<endl<<"Desea modificar algun producto? [S/N]: "; cin>>h;
                                if(h=='S'||h=='s'){
                                    cout<<"Fila: "; cin>>f;
									if(f <= nProductos){
										cout<<"Columna: "; cin>>c;
                                        listaProductos[f-1].modificarProducto(c);
                                        if(c==6){
                                            cout<<left<<setw(3)<<"\n#"<<setw(17)<<"| Codigo"<<setw(22)<<"| Nombre"<<setw(17)<<"| RUC"<<setw(17)<<"| Telefono"<<setw(42)<<"| Direccion"<<"|"<<endl;
                                            for(int i = 0; i <= 118; i++){cout<<"=";} cout<<endl;
                                            for(int i = 0; i < nProveedores; i++){
                                                cout<<left<<setw(3)<<i+1;
                                                listaProveedores[i].mostrarProveedor();
                                            }
                                            cout<<"\nDesea asignar al producto alguno de los proveedores que se muestran? [S/N]: "; cin>>h;
                                            if(h=='S'||h=='s'){
                                                cout<<"\nDigite el numero del proveedor que desea asignar al producto: "; cin>>a;
                                                listaProductos[nProductos].asignarProveedor(&listaProveedores[a-1]);
                                                cout<<"Modificacion exitosa."<<endl;
                                            }else{
                                                cout<<"\nIngrese los datos del proveedor: "<<endl;
                                                listaProveedores[nProveedores].leerProveedor();
                                                listaProductos[nProductos].asignarProveedor(&listaProveedores[nProveedores]);
                                                nProveedores++;
                                            }
                                        }
                                    }else{cout<<"\nIngrese una fila correcta, hay "<<nProductos<<" filas."<<endl;}
                                }
                                cout<<"\n";
                                system("pause");
                            break;
                            case 3:             //REGISTRAR PROVEEDORES
                                system("cls");
                                cout<<"============================="<<endl;
                                cout<<"|Opcion: Registrar Proveedor|"<<endl;
                                cout<<"============================="<<endl;
                                listaProveedores[nProveedores].leerProveedor();
                                nProveedores++;
                                system("pause");
                            break;
                            case 4:             //VER LISTA Y MODIFICAR PROVEEDORES
                                system("cls");
                                cout<<"==================================="<<endl;
                                cout<<"|Opcion: Ver Lista de  Proveedores|"<<endl;
                                cout<<"==================================="<<endl<<"\n";
                                cout<<left<<setw(17)<<"| Codigo (1)"<<setw(22)<<"| Nombre (2) "<<setw(17)<<"| RUC (3) "<<setw(17)<<"| Telefono (4) "<<setw(42)<<"| Direccion (5) "<<"|"<<endl;
								for(int i = 0; i <= 115; i++){cout<<"=";} cout<<endl;
								for(int i = 0; i < nProveedores; i++){listaProveedores[i].mostrarProveedor();}
                                cout<<endl<<"Desea modificar algun producto? [S/N]: "; cin>>h;
                                if(h=='S'||h=='s'){
                                    cout<<"Fila: "; cin>>f;
									if(f <= nProveedores){
										cout<<"Columna: "; cin>>c;
                                        listaProveedores[f-1].modificarProveedor(c);
                                    }else{cout<<"\nIngrese una fila correcta, hay "<<nProveedores<<" filas."<<endl;}
                                }
                                cout<<"\n";
                                system("pause");
                            break;
                            case 5: break;
                            default: cout<<"\nNo ingreso una opcion correcta."<<endl; system("pause"); break;
                        }
                    break;
                    case 2:                                     //VENTAS
                        system("cls");
                        cout<<"================"<<endl;
                        cout<<"|Opcion: Ventas|"<<endl;
                        cout<<"================"<<endl;
                        cout<<"1. Registrar Factura"<<endl;
                        cout<<"2. Ver Lista de Facturas"<<endl;
                        cout<<"3. Registrar Clientes"<<endl;
                        cout<<"4. Ver Lista de Clientes"<<endl;
                        cout<<"5. Modificar Clientes"<<endl;
                        cout<<"6. Generar Reporte de Ventas"<<endl;
                        cout<<"7. Salir"<<endl;
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
                            case 6:
                                system("cls");
                                cout<<"==================================="<<endl;
                                cout<<"|Opcion: Generar Reporte de ventas|"<<endl;
                                cout<<"==================================="<<endl<<"\n";
                                cout<<left<<setw(15)<<"| Codigo "<<setw(40)<<"| Nombre del cliente "<<setw(15)<<"| Fecha "<<setw(15)<<"| Monto "<<endl;
                                for(int i = 0; i <= 85; i++){cout<<"=";} cout<<endl;
                                for(int i = 0; i <= nFacturas; i++){
                                    listaFacturas[i].mostrarFactura();
                                }
                                system("pause");
                            break;
                            case 7: break;
                            default: cout<<"\nNo ingreso una opcion correcta."<<endl; system("pause"); break;
                        }
                    break;
                    case 3:                                     //DATOS DEL USUARIO
                        cout<<"Ingrese sus datos:";
                        cout<<"Usuario: "; fflush(stdin); gets(nomu);
		                cout<<"Contrasenia: "; fflush(stdin); gets(contra);
                        if(principal.verificarAcceso(nomu,contra) == true){
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
                                    cout<<"Ingrese el nuevo Nombre y Apellido:";cin.sync();gets(nombre);
                                    principal.actualizarNombre(nombre);
                                break;
                                case 2:
                                    cout<<"Ingrese el nuevo Usuario: ";cin.sync();gets(nomu);
                                    principal.actualizarNomUsuario(nomu);
                                break;
                                case 3:
                                    cout<<"Ingrese la nueva Contraseña: ";cin.sync();gets(contra);
                                    principal.actualizarContrasenia(contra);
                                break;
                                case 4: break;
                                default: cout<<"\nNo ingreso una opcion correcta."<<endl; system("pause"); break;
                            }
                        }else{
                            cout<<"Nombre de usuario o contrasenia incorrectos..."<<endl;
                            system("pause");
                        }
                    break;
                    case 4: salida=true; system("pause"); break;
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
	cout<<"========================================================="<<endl;
	cout<<left<<setw(50)<<"|\tSistema de Gestion de productos RMO-001"<<"|"<<endl;
	cout<<left<<setw(56)<<"| Nombre del Supermercado: Tienda Los Angeles"<<right<<"|"<<endl;
	cout<<left<<setw(56)<<"| Version del sistema: "<<right<<"|"<<endl;    //falta cambiar la version
	cout<<left<<setw(56)<<"| Empresa creadora: RMO Software"<<right<<"|"<<endl;
	cout<<"========================================================="<<endl;
}
