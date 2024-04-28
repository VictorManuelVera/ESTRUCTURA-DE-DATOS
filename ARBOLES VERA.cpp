/*
Realizar un
sistema que permita el registro de estudiantes con el uso de árboles binarios,
el sistema debe permitir realizar la indexación (orden de inserción) a través
del código del estudiante (cada estudiante ya tiene un código asignado por
tanto se le debe preguntar) y también por la fecha de nacimiento.



El sistema debe
permitir recorrer la solución planteada con el uso de los métodos de Inorden,
Preorden y Postorden.



Puede darse el
caso de que dos estudiantes proporcionen la misma fecha de nacimiento en cuyo
caso deberá ubicarse al nuevo nodo a la derecha de su igual



El sistema debe
permitir eliminar el registro del estudiante. 



Del alumno se
deben solicitar: código, nombres, apellidos y fecha de nacimiento (año, mes y día)
*/

#include <iostream>
using namespace std;
#include <conio.h>
#include <malloc.h>

struct arbol{
	
	int codigo;
	char nombre[50];
	char apellido[50];
	
	int year;
	int mes;
	int dia;
	arbol *izq, *der;
	
};

	arbol *raiz,*raizF,*aux, *aux2;
/*
void registro();{
posicionar();
}

void mostrar();
void eliminar();
*/

//hay un error al implementar esta funcion en registrar

void posicionar(){
    if(aux->codigo < aux2->codigo){
        if(aux2->izq != NULL){
            aux2 = aux2->izq;
            posicionar();	
        }
        else{
            aux2->izq = aux;
        }
    } else if(aux->codigo > aux2->codigo){
        if(aux2->der != NULL){
            aux2 = aux2->der;
            posicionar();
        } else{
            aux2->der = aux;
        }
    }
}


void registrar(){

aux = (struct arbol *)malloc(sizeof(struct arbol)); 
	
cout<<"\nDigite el codigo del estudiante: ";
cin>>aux->codigo;
	
cout<<"\nDigite el nombre del estudiante: ";
cin>>aux->nombre;
	
cout<<"\nDigite el apellido del estudiante: ";
cin>>aux->apellido;
	
cout<<"\nDigite la fecha de nacimiento del estudiante: \n";

cout<<"\nDigite el dia en el que nacio el estudiante: ";
cin>>aux->dia;

cout<<"\nDigite el mes en el que nacio el estudiante: ";
cin>>aux->mes;

cout<<"\nDigite el year en el que nacio el estudiante: ";
cin>>aux->year;

aux->izq = aux->der = NULL;

if(raiz==NULL){
	
	raiz = aux;
	aux = NULL;
	free(aux);
}

else if(raiz!=NULL){
	aux2=raiz;
	posicionar();
}

}

void mostrar(){

	
	
}

void eliminar(){


	
}

int main(){
	
	
	int opc=0;
	
	
	do{
	
	cout<<"\n\tMENU\n";
	cout<<"\n\t1. Registrar\n";
	cout<<"\t2. Mostrar\n";
	cout<<"\t3. Eliminar\n";
	cout<<"\t4. Salir\n";
	cout<<"\nDigite la opcion que desea realizar: ";
	cin>>opc;
		
	switch(opc){
		
		case 1:
			registrar();
			break;
			
		case 2:
			mostrar();
			break;
			
		case 3:
			eliminar();
			break;
			
		case 4:
			cout<<"\nGracias por usar nuestro programa... Saliendo\n";	
				cout<<"...finalized...";
			break;
			
		default:
			cout<<"\nLa opcion que digitaste no se encuentra disponible, por favor digite la opcion nuevamente: \n";
			break;
	}
		
	}while(opc!=4);
	
	getch();
	return 0;
}
