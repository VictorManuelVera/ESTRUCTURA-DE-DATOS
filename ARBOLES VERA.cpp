/*
Realizar un
sistema que permita el registro de estudiantes con el uso de �rboles binarios,
el sistema debe permitir realizar la indexaci�n (orden de inserci�n) a trav�s
del c�digo del estudiante (cada estudiante ya tiene un c�digo asignado por
tanto se le debe preguntar) y tambi�n por la fecha de nacimiento.



El sistema debe
permitir recorrer la soluci�n planteada con el uso de los m�todos de Inorden,
Preorden y Postorden.



Puede darse el
caso de que dos estudiantes proporcionen la misma fecha de nacimiento en cuyo
caso deber� ubicarse al nuevo nodo a la derecha de su igual



El sistema debe
permitir eliminar el registro del estudiante. 



Del alumno se
deben solicitar: c�digo, nombres, apellidos y fecha de nacimiento (a�o, mes y d�a)
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
	
	*sig;
};

	arbol *aux, *aux2, *raiz, *izq, *der;

void registro();
void mostrar();
void eliminar();

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
	
		switch (opc){
		
		case 1:
			
			registro();
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


void registrar(){


	
}

void mostrar(){

	
	
}

void eliminar(){


	
}
























