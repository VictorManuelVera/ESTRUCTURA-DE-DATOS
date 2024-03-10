/*
Taller FIFO (Dia) PACIENTES...
Volver a: Memoria Dinámic...
Realizar un programa que permita registrar pacientes, se debe captura el nombre del paciente y el numero de documento.

1. Mostrar los pacientes de tal manera que se muestre 1, 2, 3, etc según el orden de registro (Colas).

2. El proyecto ser subido por cada miembro del grupo en GitHub.

Subir su repositorio a GitHub.... y compartir el repositorio aqui.
*/



#include <iostream>

using namespace std;
#include <conio.h>
#include <malloc.h>

//Creamos la estructura que almacena las variables
struct Pacientes{

char nombre[20];
char apellido[20];
int doc;
int *apuntador;
int aumento=0;
struct Pacientes *sig;	
}paciente;

struct Pacientes *cab, *aux, *aux2;

void Registrar();//Funcion registrar
void MostrarDatos();//Funcion Mostrar Datos

int main(){
	
	int opcion=0;
	
		
		
		
		do{
			
		cout<<"\n\tMENU:";
		cout<<"\n\t1. Registrar pacientes\n";
		cout<<"\t2. Mostrar los pacientes registrados\n";
		cout<<"\t3. Salir del programa\n";
		cout<<"\nBienvenido(a), por favor digite la opcion que desea realizar: ";
		cin>>opcion;
		
			switch(opcion){
				
			
		
	case 1:
		Registrar();
		break;
		
	case 2:
		MostrarDatos();
		break;
	
	case 3:
		cout<<"\nGracias por usar nuestro programa... Saliendo\n";	
			cout<<"...finalized...";
			break;
			
	default:
		
		cout<<"\nLa opcion que digitaste no se encuentra disponible, por favor digite la opcion nuevamente: \n";
		break;
			
	
		
	} 
		}while(opcion!=3);
			
		
		
		
	
	
getch();
return 0;
	
}


void Registrar(){
	
if (cab == NULL)
    {
        cab = (struct Pacientes *)malloc(sizeof(struct Pacientes));

        cout << "ingrese su primer nombre: ";
        cin >> cab->nombre;

        cout << "ingrese su primer apellido: ";
        cin >> cab->apellido;
        
        cout << "Ingrese su numero de documento: ";
        cin >> cab->doc;
        cab->sig = NULL;

        if (cab == NULL)
        {
            cab = aux;
            cab->aumento = 1;
            aux = NULL;

            free(aux);
        }
        
    }
    else
    {
        aux = (struct Pacientes *)malloc(sizeof(struct Pacientes));
        

        cout << "ingrese su primer nombre: ";
        cin >> aux->nombre;

        cout << "ingrese su primer apellido: ";
        cin >> aux->apellido;
        
        cout << "ingrese su numero de documento: ";
        cin >> aux->doc;

        aux->sig = NULL;
        aux2 = cab;

        while (aux2->sig != NULL)
        {
            aux2 = aux2->sig;
        }

        aux->aumento = aux2->aumento + 1;
        aux2->sig = aux;
        aux = NULL;
        aux2 = aux;

        free(aux);
        free(aux2);
		
	}	

	
	
	}
	
	 			 
	      
	


void MostrarDatos(){
	
	for(aux=cab; aux!=NULL; aux=aux->sig){
		
	cout<<"\nCodigo de registro: "<<aux->aumento<<endl<<"Documento del paciente: "<<aux->doc<<endl<<"Nombre del paciente: "<<aux->nombre<< " "<<aux->apellido<<endl;
	
	}
        
    }

