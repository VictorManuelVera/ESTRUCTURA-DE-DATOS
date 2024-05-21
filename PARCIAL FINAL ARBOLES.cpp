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
	nodo *izq, *der; //arbol
	nodo *sig; //FIFO-COLA

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

	cout<<"\n\tBIENVENIDO AL APARTADO DE REGISTRO, POR FAVOR DIGITE LOS DATOS SOLICITADOS"<<endl;
		
	cout<<"\nDigite el precio del viaje: ";
	cin>>PreciodelviajeIngresado;
	
	cout<<"\nDigite el destino del viaje: ";
	cin.ignore();
    getline(cin, destinoIngresado);
	
	cout<<"\nDigite la matricula de la embarcacion: ";
    getline(cin, MatriculaEmbarcacionIngresado);
	
	cout<<"\nDigite el nombre de la embarcacion: ";
    getline(cin, NombreEmbarcacionIngresado);
	
	cout<<"\n\n\tDigite la Fecha del Viaje:\n";
	
	cout<<"\nDigite el dia: ";
	cin>>diaIngresado;
	
	cout<<"\nDigite el mes: ";
	cin>>mesIngresado;
	
	cout<<"\nDigite el year: ";
	cin>>yearIngresado;
	
	cout<<"\n\nDigite la capacidad de la embarcacion: ";
	cin>>CapacidadEmbarcacionIngresado;
	
	//Asignando al arbol los datos	

	aux->Preciodelviaje = PreciodelviajeIngresado;
    strcpy(aux->destino, destinoIngresado.c_str());
    strcpy(aux->MatriculaEmbarcacion, MatriculaEmbarcacionIngresado.c_str());
    strcpy(aux->NombreEmbarcacion, NombreEmbarcacionIngresado.c_str());
    aux->dia = diaIngresado;
    aux->mes = mesIngresado;
    aux->year = yearIngresado;
    aux->CapacidadEmbarcacion = CapacidadEmbarcacionIngresado;
    aux->izq = NULL;
    aux->der = NULL;
    
     if (raiz == NULL) {
        raiz = aux;
    } else {
        nodo *actual = raiz;
        nodo *padre;
        while (true) {
            padre = actual;
            if (PreciodelviajeIngresado < actual->Preciodelviaje) {
                actual = actual->izq;
                if (actual == NULL) {
                    padre->izq = aux;
                    return;
                }
            } else {
                actual = actual->der;
                if (actual == NULL) {
                    padre->der = aux;
                    return;
                }
            }
        }
    }

    cout << "\nViaje registrado con éxito.\n";
}



void BuscarViaje(){
	
	
}

void ListarViaje(){
	
	
}

void EliminarViaje(){
	
	
}

void registrarPasajero(){
	
	aux3 = (struct nodo *)malloc(sizeof (struct nodo));	

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
