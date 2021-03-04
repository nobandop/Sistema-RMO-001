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
int cadenaNum(string);
int nombreNum(string);

int main(){
    Controlador principal;
    Producto listaProductos[50],auxProducto;
    Cliente listaClientes[50],auxCliente;
    Proveedor listaProveedores[50],auxProveedor;
	Factura listaFacturas[50];
	int nProductos=0,nClientes=0,nProveedores=0,nFacturas=0,a;

	bool salida = false;
	int equivocacion=0,opc1,opc2,resp,f,c,ind,prod,warning = 0;
	string nombre,nomu,contra;
    char h;

    ofstream archivo;
	do{
        titulo();
		cout<<"Ingrese su nombre de usuario: "; cin>>nomu;
		cout<<"Ingrese su contrasenia: "; cin>>contra;
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
                        cout<<"5. Modo de ordenacion"<<endl;
                        cout<<"6. Salir"<<endl;
                        cout<<"Elija una opcion: "; cin>>opc2;
                        switch(opc2){
                            case 1:
                                system("cls");                       //REGISTRAR PRODUCTOS
                                cout<<"============================="<<endl;
                                cout<<"|Opcion: Registrar Productos|"<<endl;
                                cout<<"============================="<<endl;
                                listaProductos[nProductos].leerProducto();
                                if(nProveedores == 0){        //si no existen proveedores
                                    cout<<"\nNo se han registrado proveedores aun."<<endl<<endl;
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
                                do{
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
                                }while(h=='S'||h=='s');
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
                                do{
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
                                }while(h=='S'||h=='s');
                            break;
                            case 5:
                                system("cls");
                                cout<<"============================"<<endl;
                                cout<<"|Opcion: Modo de ordenacion|"<<endl;
                                cout<<"============================"<<endl<<"\n";
                                cout<<"1. Ordenar por codigo"<<endl;
                                cout<<"2. Ordenar por nombre"<<endl;
                                cout<<"3. Salir"<<endl;
                                cin>>resp;
                                switch(resp){
                                    case 1:                 //Ordenacion por codigo
                                        if(nProductos>1){
                                            for(int i = 1; i < nProductos; i++){
                                                for(int j = 0; j < nProductos-i;j++){
                                                    if(cadenaNum(listaProductos[j].getCodigo()) > cadenaNum(listaProductos[j+1].getCodigo())){
                                                        auxProducto = listaProductos[j];
                                                        listaProductos[j] = listaProductos[j+1];
                                                        listaProductos[j+1] = auxProducto;
                                                    }
                                                }
                                            }
                                            cout<<"Productos ordenados por el codigo..."<<endl;
                                        }
                                        if(nProveedores>1){
                                            for(int i = 1; i < nProveedores; i++){
                                                for(int j = 0; j < nProveedores-i;j++){
                                                    if(cadenaNum(listaProveedores[j].getCodigo()) > cadenaNum(listaProveedores[j+1].getCodigo())){
                                                        auxProveedor = listaProveedores[j];
                                                        listaProveedores[j] = listaProveedores[j+1];
                                                        listaProveedores[j+1] = auxProveedor;
                                                    }
                                                }
                                            }
                                            cout<<"Proveedores ordenados por el codigo..."<<endl;
                                        }
                                        if(nClientes>1){
                                            for(int i = 1; i < nClientes; i++){
                                                for(int j = 0; j < nClientes-i;j++){
                                                    if(cadenaNum(listaClientes[j].getCodigo()) > cadenaNum(listaClientes[j+1].getCodigo())){
                                                        auxCliente = listaClientes[j];
                                                        listaClientes[j] = listaClientes[j+1];
                                                        listaClientes[j+1] = auxCliente;
                                                    }
                                                }
                                            }
                                        cout<<"Clientes ordenados por el codigo..."<<endl;
                                        }

                                        cout<<endl;system("pause");
                                    case 2:                 //Ordenacion por nombre
                                        if(nProductos>1){
                                            for(int i = 1; i < nProductos; i++){
                                                for(int j = 0; j < nProductos-i;j++){
                                                    if(nombreNum(listaProductos[j].getNombre()) > nombreNum(listaProductos[j+1].getNombre())){
                                                        auxProducto = listaProductos[j];
                                                        listaProductos[j] = listaProductos[j+1];
                                                        listaProductos[j+1] = auxProducto;
                                                    }
                                                }
                                            }
                                            cout<<"Productos ordenados por el nombre..."<<endl;
                                        }
                                        if(nProveedores>1){
                                            for(int i = 1; i < nProveedores; i++){
                                                for(int j = 0; j < nProveedores-i;j++){
                                                    if(nombreNum(listaProveedores[j].getNombre()) > nombreNum(listaProveedores[j+1].getNombre())){
                                                        auxProveedor = listaProveedores[j];
                                                        listaProveedores[j] = listaProveedores[j+1];
                                                        listaProveedores[j+1] = auxProveedor;
                                                    }
                                                }
                                            }
                                            cout<<"Proveedores ordenados por el nombre..."<<endl;
                                        }
                                        if(nClientes>1){
                                            for(int i = 1; i < nClientes; i++){
                                                for(int j = 0; j < nClientes-i;j++){
                                                    if(nombreNum(listaClientes[j].getNombre()) > nombreNum(listaClientes[j+1].getNombre())){
                                                        auxCliente = listaClientes[j];
                                                        listaClientes[j] = listaClientes[j+1];
                                                        listaClientes[j+1] = auxCliente;
                                                    }
                                                }
                                            }
                                            cout<<"Clientes ordenados por el nombre..."<<endl;
                                        }
                                        cout<<endl;system("pause");
                                    case 3: break;
                                }
                            break;
                            case 6: break;
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
                        cout<<"5. Generar Reporte de Ventas"<<endl;
                        cout<<"6. Salir"<<endl;
                        cout<<"Elija una opcion: "; cin>>opc2;
                        switch(opc2){
                            case 1:
                                if(nClientes > 0 and nProductos > 0){
                                    cout<<"Codigo 'factura(#)': ";
                                    cin>>listaFacturas[nFacturas].codigoFactura;
                                    cout<<"Fecha de factura (DD/MM/AA): ";
                                    cin>>listaFacturas[nFacturas].fechaFactura;
                                    cout<<endl<<"Ahora debera elegir a que cliente agregar: "<<endl;
                                    cout<<left;
                                    cout<<setw(3)<<"#";
                                    cout<<setw(17)<<"| Codigo";
                                    cout<<setw(42)<<"| Nombre Completo";
                                    cout<<setw(17)<<"| DNI";
                                    cout<<setw(17)<<"| RUC";
                                    cout<<setw(17)<<"| Telefono";
                                    cout<<"|"<<endl;
                                    for(int i = 0; i <= 113; i++){
                                        cout<<"=";
                                    }
                                    cout<<endl;
                                    for(int i = 0; i < nClientes; i++){
                                        cout<<left<<setw(3)<<i+1;
                                        listaClientes[i].mostrarCliente();
                                    }
                                    do{
                                        cout<<endl<<"Ingrese numero (#) de la lista de clientes(1-"<<nClientes<<"): "; cin>>ind;
                                    }while(ind > nClientes);
                                    listaFacturas[nFacturas].asignarCliente(&listaClientes[ind-1]);                          //ASIGNACION DE FACTURAS
                                    listaClientes[ind-1].asignarFactura(&listaFacturas[nFacturas]);
                                    do{
                                        cout<<"Cuantos productos comprara?(1-"<<nProductos<<"): "; cin>>prod;
                                    }while(prod > nProductos);
                                    for(int i = 0; i < prod; i++){
                                        system("cls");
                                        cout<<left;
                                        cout<<setw(3)<<"#";
                                        cout<<setw(17)<<"| Codigo";
                                        cout<<setw(27)<<"| Nombre de Prod.";
                                        cout<<setw(17)<<"| Cantidad";
                                        cout<<setw(22)<<"| Categoria";
                                        cout<<setw(17)<<"| Precio";
                                        cout<<setw(22)<<"| Proveedor";
                                        cout<<"|"<<endl;
                                        for(int i = 0; i <= 125; i++){
                                            cout<<"=";
                                        }
                                        cout<<endl;
                                        for(int i = 0; i < nProductos; i++){
                                            cout<<left<<setw(3)<<i+1;
                                            listaProductos[i].mostrarProducto();
                                        }
                                        cout<<"Ingrese un (#) de la lista de productos: "; cin>>f;
                                        cout<<endl;
                                        if(f <= nProductos){
                                            do{
                                                if(warning > 0){
                                                        cout<<"Ingrese una cantidad menor o igual a la existente: "; cin>>c;
                                                }else{
                                                    cout<<"Cantidad a comprar: "; cin>>c;
                                                    warning = warning + 1;
                                                }
                                            }while(c > listaProductos[f-1].getCantProducto());
                                            cout<<"Producto: "<<listaProductos[f-1].getNombre()<<",Cantidad: "<<c<<endl;
                                            listaFacturas[nFacturas].desarrolloFactura(&listaProductos[f-1],c);
                                            cout<<endl;
                                            system("pause");
                                        }else{
                                            cout<<"Ingrese una fila correcta, hay "<<nProductos<<" filas."<<endl;
                                            i=i-1;
                                            system("pause");
                                        }
                                        warning = 0;
                                    }
                                    system("cls");
                                    cout<<left;
                                    cout<<setw(3)<<"#";
                                    cout<<setw(17)<<"| Codigo";
                                    cout<<setw(27)<<"| Nombre de Prod.";
                                    cout<<setw(17)<<"| Cantidad";
                                    cout<<setw(22)<<"| Categoria";
                                    cout<<setw(17)<<"| Precio";
                                    cout<<setw(22)<<"| Proveedor";
                                    cout<<"|"<<endl;
                                    for(int i = 0; i <= 125; i++){
                                        cout<<"=";
                                    }
                                    cout<<endl;
                                    for(int i = 0; i < nProductos; i++){
                                        cout<<left<<setw(3)<<i+1;
                                        listaProductos[i].mostrarProducto();
                                    }
                                    nFacturas ++;
                                    cout<<endl<<"Factura generada exitosamente!"<<endl;
                                    cout<<endl;
                                    system("pause");
                                }else{
                                    if(nProductos == 0){
                                        cout<<"Necesita almenos un producto registrado."<<endl;
                                    }
                                    if(nClientes == 0){
                                        cout<<"Necesita almenos un cliente registrado."<<endl;
                                    }
                                    cout<<endl;
                                    system("pause");
                                }
                            break;
                            case 2:
                                system("cls");
                                cout<<"============================"<<endl;
                                cout<<"|Opcion: Ver lista Facturas|"<<endl;
                                cout<<"============================"<<endl<<"\n";
                                cout<<left<<setw(17)<<"| Codigo "<<setw(42)<<"| Nombre del cliente "<<setw(17)<<"| Fecha "<<setw(15)<<"| Monto "<<"|"<<endl;
                                for(int i = 0; i <= 85; i++){cout<<"=";} cout<<endl;
                                for(int i = 0; i < nFacturas; i++){
                                    listaFacturas[i].mostrarFactura();
                                    listaFacturas[i].productosComprados();
                                }
                                system("pause");
                            break;
                            case 3:
                                listaClientes[nClientes].leerCliente();
                                nClientes++;
                                cout<<endl<<"Registro Exitoso!"<<endl;
                                system("pause");
                            break;
                            case 4:
                                do{
                                    system("cls");
                                    cout<<left;
                                    cout<<setw(14)<<"| Codigo(1)";
                                    cout<<setw(42)<<"| Nombre(2)";
                                    cout<<setw(17)<<"| DNI(3)";
                                    cout<<setw(17)<<"| Telefono(4)"<<"|";
                                    cout<<endl;
                                    for(int i = 0; i <= 90; i++){cout<<"=";}
                                    cout<<endl;
                                    for(int i = 0; i < nClientes; i++){listaClientes[i].mostrarCliente();}
                                    cout<<endl<<"Quieres Modificar? [S/N]: ";cin>>h;
                                    if(h=='S'||h=='s'){
                                        cout<<"Fila: "; cin>>f;
                                        if(f <= nClientes){
                                            cout<<"Columna: "; cin>>c;
                                            listaClientes[f-1].modificarCliente(c);
                                        }else{cout<<"\nIngrese una fila correcta, hay "<<nClientes<<" filas."<<endl;system("pause");}
                                    }
                                }while(h == 'S' ||h == 's');
                            break;
                            case 5:
                                system("cls");
                                cout<<"==================================="<<endl;
                                cout<<"|Opcion: Generar Reporte de ventas|"<<endl;
                                cout<<"==================================="<<endl<<"\n";
                                cout<<left<<setw(17)<<"| Codigo "<<setw(42)<<"| Nombre del cliente "<<setw(17)<<"| Fecha "<<setw(15)<<"| Monto "<<"|"<<endl;
                                for(int i = 0; i <= 91; i++){cout<<"=";} cout<<endl;
                                for(int i = 0; i < nFacturas; i++){listaFacturas[i].mostrarFactura();}

                                archivo.open("reporte.txt");
                                if(archivo.is_open()){
                                    archivo<<left<<setw(17)<<"| Codigo "<<setw(42)<<"| Nombre del cliente "<<setw(17)<<"| Fecha "<<setw(15)<<"| Monto "<<"|"<<endl;
                                    for(int i = 0; i <= 91; i++){archivo<<"=";} archivo<<endl;
                                    for(int i = 0; i < nFacturas; i++){
                                        archivo<<left<<setw(17)<<listaFacturas[i].getCodigo()<<setw(42)<<listaFacturas[i].mostraCliente()<<setw(17)<<listaFacturas[i].getFecha()<<setw(15)<<listaFacturas[i].getMonto()<<endl;
                                    }
                                }else{
                                    cout<<"No se pudo abrir el archivo."<<endl;
                                }
                                archivo.close();
                                system("pause");
                            break;
                            case 6: break;
                            default: cout<<"\nNo ingreso una opcion correcta."<<endl; system("pause"); break;
                        }
                    break;
                    case 3:                                     //DATOS DEL USUARIO
                        cout<<"Ingrese sus datos:";
                        cout<<"Usuario: "; cin>>nomu;
		                cout<<"Contrasenia: "; cin>>contra;
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
                                    cout<<"Ingrese el nuevo Nombre y Apellido:"; cin>>nombre;
                                    principal.actualizarNombre(nombre);
                                break;
                                case 2:
                                    cout<<"Ingrese el nuevo Usuario: "; cin>>nomu;
                                    principal.actualizarNomUsuario(nomu);
                                break;
                                case 3:
                                    cout<<"Ingrese la nueva Contraseña: "; cin>>contra;
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
                    //default: cout<<"\nNo ingreso una opcion correcta."<<endl; system("pause"); break;
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
	cout<<left<<setw(56)<<"| Version del sistema: v1.00"<<right<<"|"<<endl;    //falta cambiar la version
	cout<<left<<setw(56)<<"| Empresa creadora: RMO Software"<<right<<"|"<<endl;
	cout<<"========================================================="<<endl;
}

int cadenaNum(string cadena){
    string subcadena=cadena.substr(5,8);
    int numero=stoi(subcadena);
    return numero;
}

int nombreNum(string cadena){
    string subcadena=cadena.substr(0,1);
    if(subcadena=="A"||subcadena=="a"){return 1;}
    if(subcadena=="B"||subcadena=="b"){return 2;}
    if(subcadena=="C"||subcadena=="c"){return 3;}
    if(subcadena=="D"||subcadena=="d"){return 4;}
    if(subcadena=="E"||subcadena=="e"){return 5;}
    if(subcadena=="F"||subcadena=="f"){return 6;}
    if(subcadena=="G"||subcadena=="g"){return 7;}
    if(subcadena=="H"||subcadena=="h"){return 8;}
    if(subcadena=="I"||subcadena=="i"){return 9;}
    if(subcadena=="J"||subcadena=="j"){return 10;}
    if(subcadena=="K"||subcadena=="k"){return 11;}
    if(subcadena=="L"||subcadena=="l"){return 12;}
    if(subcadena=="M"||subcadena=="m"){return 13;}
    if(subcadena=="N"||subcadena=="n"){return 14;}
    if(subcadena=="O"||subcadena=="o"){return 15;}
    if(subcadena=="P"||subcadena=="p"){return 16;}
    if(subcadena=="Q"||subcadena=="q"){return 17;}
    if(subcadena=="R"||subcadena=="r"){return 18;}
    if(subcadena=="S"||subcadena=="s"){return 19;}
    if(subcadena=="T"||subcadena=="t"){return 20;}
    if(subcadena=="U"||subcadena=="u"){return 21;}
    if(subcadena=="V"||subcadena=="v"){return 22;}
    if(subcadena=="W"||subcadena=="w"){return 23;}
    if(subcadena=="X"||subcadena=="x"){return 24;}
    if(subcadena=="Y"||subcadena=="y"){return 25;}
    if(subcadena=="Z"||subcadena=="z"){return 26;}
}
