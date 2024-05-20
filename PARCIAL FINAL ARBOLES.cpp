#include <iostream>
#include <conio.h>
#include <cstring>
#include <malloc.h>
using namespace std;


struct nodo{
	
	double Preciodelviaje;
	char destino[50];
	char MatriculaEmbarcacion[50];
 	char NombreEmbarcacion[50];
    //Fecha del viaje 
	int dia, mes, year;
	int CapacidadEmbarcacion;
	nodo *izq, *der;
	nodo *sig;
};

nodo *raiz, *aux, aux2, *aux3, *aux4;

void RegistrarViaje();
void BuscarViaje();
void ListarViaje();
void EliminarViaje();
void registrarPasajero();
void listarPasajero();

void RegistrarViaje(){
	
	double PreciodelviajeIngresado;
	string destinoIngresado;
	string MatriculaEmbarcacionIngresado;
 	string NombreEmbarcacionIngresado;
    //Fecha del viaje 
	int diaIngresado, mesIngresado, yearIngresado;
	int CapacidadEmbarcacionIngresado;
	
	aux = (struct nodo *)malloc(sizeof (struct nodo));	
	aux3 = (struct nodo *)malloc(sizeof (struct nodo));	

	cout<<"\n\tBIENVENIDO AL APARTADO DE REGISTRO, POR FAVOR DIGITE LOS DATOS SOLICITADOS"<<endl;
		
	cout<<"\nDigite el precio del viaje: ";
	cin>>PreciodelviajeIngresado;
	
	cout<<"\n Digite el destino del viaje: ";
	cin.ignore();
    getline(cin, destinoIngresado);
	
	cout<<"\n";
	cin>>;
	
	cout<<"\n";
	cin>>;
	
	cout<<"\n";
	cin>>;
	
	cout<<"\n";
	cin>>;
	
	cout<<"\n";
	cin>>;
	
	cout<<"\n";
	cin>>;
	
	cout<<"\n";
	cin>>;
	
	cout<<"\n";
	cin>>;
	
	cout<<"\n";
	cin>>;
	
	cout<<"\n";
	cin>>;

}

void BuscarViaje(){
	
	
}

void ListarViaje(){
	
	
}

void EliminarViaje(){
	
	
}

void registrarPasajero(){
	
}


void listarPasajero(){
	
	
}


int main(){
	
	int opcion=0;
	
	do{
	
	cout<<"\n\tMENU\n";
	cout<<"\n\t1) Registrar un nuevo viaje";
	cout<<"\n\t2) Buscar un viaje por identificador";
	cout<<"\n\t3) Listar todos los viajes";
	cout<<"\n\t4) Eliminar un viaje por identificador";
	cout<<"\n\t5) Registrar un pasajero en un viaje";
	cout<<"\n\t6) Listar todos los pasajeros de un viaje";
	cout<<"\n\t7) Salir"<<endl;
	
	cout<<"\nDigite la opcion que desea realizar: ";cin>>opcion;
	
	switch(opcion){
		
		case 1:
			RegistrarViaje();
			break;
			
		case 2:
			BuscarViaje();
			break;
			
		case 3:
			ListarViaje();
			break;
			
		case 4:
			EliminarViaje();
			break;
			
		case 5:
			registrarPasajero();
			break;
			
		case 6:
			listarPasajero();
			break;
			
		case 7:
		cout<<"\nGracias por usar nuestro programa... Saliendo\n";	
			cout<<"...finalized...";
			break;
		
		default:
			cout<<"\nLa opcion que digitaste no se encuentra disponible, por favor digite la opcion nuevamente: \n";
			break;
	}
		
	}while(opcion!=7);
	
	getch();
	return 0;
}
