#include "Factura.h"
#include <iomanip>
#include "string.h"

Factura::Factura(){
    codigoFactura = "-";
    fechaFactura = "-";
    nProductos = 0;
}

void Factura::leerFactura(){
    cout<<"Codigo: "; fflush(stdin); cin>>codigoFactura;
    cout<<"Fecha: "; cin>>fechaFactura;
}

void Factura::desarrolloFactura(Producto* p,int c){
    p->actualizarCantProductos(c);
    p->agregarCantSolicitada(c);
    p->agregarSubTotal(c);
    producto[nProductos] = p;
    nProductos = nProductos + 1;
    totalPagar = totalPagar + p->getSubTotal();
}

void Factura::asignarCliente(Cliente* c){cliente = c;}

void Factura::mostrarFactura(){cout<<"| "<<left<<setw(15)<<codigoFactura<<"| "<<setw(40)<<cliente->getNomCliente()<<"| "<<setw(15)<<fechaFactura<<"| "<<setw(13)<<totalPagar<<"|"<<endl;}

void Factura::productosComprados(){
    cout<<"Productos comprados: "<<endl;
	cout<<left;
	cout<<setw(15)<<"| Codigo";
	cout<<setw(26)<<"| Nombre de Prod.";
	cout<<setw(20)<<"| Cantidad sol.";
	cout<<setw(20)<<"| Precio unitario";
	cout<<setw(20)<<"| subtotal";
	cout<<"|"<<endl;
	for(int j = 0; j <= 101; j++){
		cout<<"=";
	}
	cout<<endl;
	for(int i = 0; i < nProductos; i++){
		cout<<"| ";
		cout<<left;
		cout<<setw(13)<<producto[i]->getCodigo()<<"| ";
		cout<<setw(24)<<producto[i]->getNombre()<<"| ";
		cout<<setw(18)<<producto[i]->getCantsolicitada()<<"| ";
		cout<<setw(18)<<producto[i]->getPrecio()<<"| ";
		cout<<setw(18)<<producto[i]->getSubTotal()<<"|"<<endl;
	}
	cout<<endl;
}
