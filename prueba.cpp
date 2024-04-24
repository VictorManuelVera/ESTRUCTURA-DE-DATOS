/*
Tengo un parqueadero de callejón con ocupación para moto y carro. 
Los cuales se parquean en sistema lifo. Los carros tienen un valor de parqueo de 1000 y las motos de 500, 
pero al retirarlos cada movimiento adicional de vehículo cuesta 100 para carro y 50 para moto. 
Calcular el valor delegando en x momento de día
*/

#include <iostream>
using namespace std;
#include <conio.h>
#include <malloc.h> 

struct carro{

int cantidad;
char placa[50];
int ID;
carro *sig;
	
};

carro *cab, *aux;

struct moto{

int cantidad;	
char placa[50];
int ID;
moto *sig2;
		
};

moto *cab2, *aux2;

void registrar();
void calcular();
void mostrar(); 
void retirar(); 

int main(){
	
	int opc=0;
	
	do{
		
	cout<<"\n\tMENU\n";
	
	cout<<"\n\t1. Registrar\n";
	cout<<"\t2. Calcular\n";
	cout<<"\t3. Mostrar\n";
	cout<<"\t4. Retirar\n";
	cout<<"\t5. Salir\n";
	cout<<"\nDigite la opcion que desea realizar: ";
	cin>>opc;

	switch(opc){
		
	case 1: 
		registrar(); break;
		
	case 2: 
		calcular(); break;
	
	case 3: 
		mostrar(); break;	
		
	case 4: 
		retirar(); break;
	case 5:
		cout<<"\nGracias por usar nuestro programa... Saliendo\n";	
			cout<<"...finalized...";
			break;
			
	default:
		
		cout<<"\nLa opcion que digitaste no se encuentra disponible, por favor digite la opcion nuevamente: \n";
		break;
	}

	}while(opc!=5);
	
	getch();
	return 0;
}

void registrar(){
    
    int opc;
    
    cout<<"\n\tMENU\n";
    cout<<"\t\n1. Carro";
    cout<<"\t\n2. Moto\n";
    cout<<"\nDigite el tipo de vehiculo que desea registrar: ";
    cin>>opc;
    
    
    if(opc==1){
    	
   	aux = (struct carro *)malloc(sizeof(struct carro)); 
   	cout<<"\nDigite la placa del carro: ";
   	cin>>aux->placa;
   	cout<<"Digite el ID del carro: ";
   	cin>>aux->ID;
   	
   	
   	if(cab==NULL){
   		
   		aux->cantidad=1;
   		cab=aux;
   		cab->sig=NULL;
   	}
   	
   	else{
   		
   		aux->cantidad=aux->cantidad+1;
   		aux->sig=cab;
   		cab=aux;
   	}
   	
   	aux=NULL;
   	free(aux);
   	
    }
    
    
    if(opc==2){
    
	aux2 = (struct moto *)malloc(sizeof(struct moto)); 	
	
	cout<<"\nDigite la placa de la moto: ";
   	cin>>aux2->placa;
   	cout<<"Digite el ID de la moto: ";
   	cin>>aux2->ID;
   	
   	
   	if(cab2==NULL){
   		
   		cab2=aux2;
   		cab2->sig2=NULL;
   	}
   	
   	else{
   		
   		aux2->sig2=cab2;
   		cab2=aux2;
   	}
   	
   	aux2=NULL;
   	free(aux2);
    }
  
    
}

void calcular(){

	int totalCarros = 0;
    int totalMotos = 0;
    int valorTotal = 0;
    
    carro *temporalCarro = cab;
    while(temporalCarro != NULL){
        totalCarros++;
       temporalCarro = temporalCarro->sig;
    }
    
    moto *temporalMoto = cab2;
    while(temporalMoto != NULL){
        totalMotos++;
        temporalMoto = temporalMoto->sig2;
    }
    
    valorTotal = totalCarros * 1000 + totalMotos * 500; 
    
    
    cout << "\nHay un total de " << totalCarros << " carros en el parqueadero.";
    cout << "\nHay un total de " << totalMotos << " motos en el parqueadero.";
    cout << "\nEl valor total del parqueadero en este momento es: " << valorTotal << " pesos." << endl;

	
}

void mostrar(){
	
	int totalCarros = 0;
    int totalMotos = 0;
    
    carro *temporalCarro = cab;
    while(temporalCarro != NULL){
        totalCarros++;
       temporalCarro = temporalCarro->sig;
    }
    
    moto *temporalMoto = cab2;
    while(temporalMoto != NULL){
        totalMotos++;
        temporalMoto = temporalMoto->sig2;
    }
    
	cout<<"\nMostrando los carros que hay en el parquadero:\n";
	
	aux=cab;
	while(aux!=NULL){
	
	cout<<"\nPlaca de carro: "<<aux->placa;
	cout<<"\nID de carro: "<<aux->ID<<"\n";
	aux=aux->sig;
		
	}
	
	cout<<"\n\nMostrando las motos que hay en el parquadero:\n";
	
	aux2=cab2;
	while(aux2!=NULL){
	
	cout<<"\nPlaca de moto: "<<aux2->placa;
	cout<<"\nID de moto: "<<aux2->ID<<"\n";
	aux2=aux2->sig2;
		
	}
	
	cout<<"\nHay un total de "<<totalCarros<<" carros en el parquadero";
	cout<<"\nHay un total de "<<totalMotos<<" motos en el parquadero\n";

}

void retirar() {
    int id;
    int opcion;

    if (cab == NULL && cab2 == NULL) {
        cout << "\nNo hay vehículos en el parqueadero\n";
    } else {
        cout << "\n\tMENU\n\n";
        cout << "\t1. Carro";
        cout << "\t2. Moto\n";
        cout << "\nDigite la opcion que desea realizar:";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Ingrese el ID del carro a retirar del parqueadero: ";
            cin >> id;

            carro *tempC = cab;
            carro *prevC = NULL;

            while (tempC != NULL) {
                if (tempC->ID == id) {
                    if (prevC == NULL) {
                        cab = tempC->sig;
                    } else {
                        prevC->sig = tempC->sig;
                    }
                    delete tempC;

                    
                }
                prevC = tempC;
                tempC = tempC->sig;
            }
            cout << "\nEl carro con ID " << id << " no se encuentra en el parqueadero.\n";
        }

        if (opcion == 2) {
            cout << "Ingrese el ID de la moto a retirar del parqueadero: ";
            cin >> id;

            moto *tempM = cab2;
            moto *prevM = NULL;

            while (tempM != NULL) {
                if (tempM->ID == id) {
                    if (prevM == NULL) {
                        cab2 = tempM->sig2;
                    } else {
                        prevM->sig2 = tempM->sig2;
                    }
                    delete tempM;

                    
                }
                prevM = tempM;
                tempM = tempM->sig2;
            }
            cout << "\nLa moto con ID " << id << " no se encuentra en el parqueadero.\n";
        }
    }

    cout << "\n...Actualizando el valor del parqueadero...\n";
    
}




	
