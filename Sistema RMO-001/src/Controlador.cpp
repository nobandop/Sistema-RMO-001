#include "Controlador.h"
#include <fstream>

Controlador::Controlador(){
    ifstream archivo;
    archivo.open("usuario.txt",ios::in | ios::binary);

}

bool Controlador::verificarAcceso(char *nom,char *contra){
    int cont=0;
    if(strcmp(nom,nomusuario)==0){
        cont = cont + 1;
    }
    if(strcmp(contra,contrasenia)==0){
        cont = cont + 1;
    }
    if(cont==2){
        return true;
    }else{
        return false;
    }
}

void Controlador::asignarDatos(){
    ofstream archivo;

    archivo.open("usuario.txt",ios::out);

    if(archivo.is_open()){
        
    }
}