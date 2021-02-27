#include "Cliente.h"
#include <iostream>
#include <string.h>

using namespace std;

Cliente::Cliente(){
    strcpy(codigoCliente,"-");
    strcpy(nombreCliente,"-");
    strcpy(dniCliente,"00000000");
    strcpy(telefonoCliente,"000000000");
    nFacturas = 0;
}

void Cliente::leerCliente(){
    //cout<<"\tClientes: Registrar cliente."<<endl;
//	cout<<"Codigo (Ejm.: 001): "; fflush(stdin); gets(codCli);
//	cout<<"Nombres: "; fflush(stdin); gets(nomCli);
//	cout<<"Apellidos: "; fflush(stdin); gets(apeCli);
//	cout<<"DNI: "; cin>>dni;
	//cout<<"RUC: "; cin>>rucCli;
	//cout<<"Telefono: "; cin>>telfCli;
	//cout<<"\nRegistro exitoso."<<endl;
	system("pause");
}
