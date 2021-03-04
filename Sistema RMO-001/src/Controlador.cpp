#include "Controlador.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

Controlador::Controlador(){
	nombre = "admin";
    nomusuario = "admin";
    contrasenia = "admin";
}

bool Controlador::verificarAcceso(string nom,string contra){
    int cont=0;
    if(nom == nomusuario){cont = cont + 1;}
    if(contra == contrasenia){cont = cont + 1;}
    if(cont==2){
        return true;
    }else{
        return false;
    }
}

void Controlador::actualizarNombre(string nom){nombre = nom;}

void Controlador::actualizarNomUsuario(string nomu){nomusuario = nomu;}

void Controlador::actualizarContrasenia(string contra){contrasenia = contra;}

int cadenaNum(string cadena){
    string subcadena=cadena.substr(5,8);
    int numero=stoi(subcadena);
    return numero;
}

void ordenarProductos(Producto *Productos, int n){
    Producto aux;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n-i;j++){
            if(cadenaNum(Productos[j].getCodigo()) > cadenaNum(Productos[j+1].getCodigo())){
                aux = Productos[j];
                Productos[j] = Productos[j+1];
                Productos[j+1] = aux;
            }
        }
    }
}