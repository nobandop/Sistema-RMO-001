#include "Controlador.h"

Controlador::Controlador(){
    strcpy(nombre,"admin");
    strcpy(nomusuario,"admin");
    strcpy(contrasenia,"admin");
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
