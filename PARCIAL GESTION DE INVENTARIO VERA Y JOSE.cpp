/*
Parcial Jornada Dia
Volver a: Parcial
Sistema de Gestión de Inventarios
Desarrolla un programa que implemente un arreglo tipo FIFO (First In, First Out) para gestionar el inventario y las ventas de productos de un almacén.

Cada producto en el inventario debe registrarse con la siguiente información:

ID del producto: un número entero único para cada producto.
Nombre del producto: una cadena de caracteres.
Cantidad: un número entero que representa la cantidad de unidades disponibles del producto.
Precio por unidad: un valor decimal que representa el costo de cada unidad del producto.
El programa debe ser capaz de realizar las siguientes operaciones:

Registrar Producto: Agregar un nuevo producto al final de la cola del inventario. (+10 Puntos)
Mostrar Inventario: Listar todos los productos en el inventario, mostrando su ID, nombre, cantidad y precio por unidad. (+10 Puntos)
Buscar Producto por ID: Buscar y mostrar la información de un producto utilizando su ID. (+10 Puntos)
Eliminar Producto: Eliminar un producto del inventario basado en su ID. Esta operación debe remover el primer producto que coincida con el ID proporcionado. (+20 Puntos)
Calcular el Valor Total del Inventario: Sumar el valor total de todos los productos en el inventario (Cantidad * Precio por unidad) y mostrar el resultado. (+10 Puntos)
Calcular el Promedio de Precios: Determinar el precio promedio por unidad de todos los productos en el inventario. (+10 Puntos)
Vender Productos: Permitir la venta de productos mediante el siguiente proceso:

Solicitar al usuario el ID del producto a vender.
Buscar el producto por su ID y mostrar su información.
Preguntar al usuario la cantidad de unidades que desea comprar. 
Verificar si hay existencias suficientes del producto. Si no hay suficientes, informar al usuario y cancelar la venta.(+10 Puntos)
Si hay existencias suficientes, descontar la cantidad vendida del inventario y calcular el total a pagar (Cantidad * Precio por unidad). (+10 Puntos)
Mostrar al usuario el total a pagar por los productos vendidos. (+10 Puntos)
*/


#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <malloc.h>
using namespace std;

struct GestionInventario{

int ID;
int buscar;
//Guardar cadenas: getline(cin,nombre_cadena);
char nombre[50];
int cantidad;
double precioUni;
int *apuntador;
struct GestionInventario *sig;

}Estructura;

struct GestionInventario *cab, *aux, *aux2;

void RegistrarProducto();
void MostrarInventario(); 
void BuscarProducto();
int EliminarProducto();
int CalcularValorInventario();
void CalcularPromedioPrecios();
int Vender();



int main(){

int opcion=0;

do{
	
	cout<<"\n\tMENU:";
	
		cout<<"\n\t1. Registrar producto\n";
		cout<<"\t2. Mostrar inventario\n";
		cout<<"\t3. Buscar producto por ID\n";
		cout<<"\t4. Eliminar producto\n";
		cout<<"\t5. Calcular el Valor Total del Inventario\n";
		cout<<"\t6. Calcular el Promedio de Precios\n";	
		cout<<"\t7. Vender Productos\n";	
		cout<<"\t8. Salir\n";
		cout<<"\nBienvenido(a), por favor digite la opcion que desea realizar: ";
		cin>>opcion;
		
		switch(opcion){
			
			case 1:
				RegistrarProducto();
				break;
				
			case 2:
				MostrarInventario();
				break;
				
			case 3:
				BuscarProducto();
				break;
				
			case 4:
				EliminarProducto();
				break;
				
			case 5:
				CalcularValorInventario();
				break;
				
			case 6:
				CalcularPromedioPrecios();
				break;
				
			case 7:
				Vender();
				break;
			
			case 8:
			cout<<"\nGracias por usar nuestro programa... Saliendo\n";	
			cout<<"...finalized...";
				break;
				
		default:
			cout<<"\nLa opcion digitada no se encuentra disponible, por favor digitela nuevamente:\n";
				break;		
		}
	
}while(opcion!=8);


getch();
return 0;


} 

//Registrar Producto: Agregar un nuevo producto al final de la cola del inventario. (+10 Puntos)

void RegistrarProducto(){
	
	
if (cab == NULL)
    {
        cab = (struct GestionInventario *)malloc(sizeof(struct GestionInventario));

        cout << "\ningrese el ID del producto: ";
        cin >> cab->ID;

        cout << "ingrese el nombre del producto: ";
        cin>>cab->nombre;
        
        cout << "Ingrese la cantidad de unidades disponibles del producto: ";
        cin >> cab->cantidad;
        
        cout << "Ingrese el precio por unidad del producto: "<<"$";
        cin >> cab-> precioUni;
        cab->sig = NULL;

        if (cab == NULL)
        {
            cab = aux;
            
            aux = NULL;

            free(aux);
        }
        
    }
    else
    {
        aux = (struct GestionInventario *)malloc(sizeof(struct GestionInventario));
        

        cout << "\ningrese el ID del producto: ";
        cin >> aux->ID;

        cout << "ingrese el nombre del producto: ";
        cin>>aux->nombre;
        
        cout << "Ingrese la cantidad de unidades disponibles del producto: "<<"$";
        cin >> aux->cantidad;
        
        cout << "Ingrese el precio por unidad del producto: ";
        cin >> aux-> precioUni;
        
        aux->sig = NULL;
        aux2 = cab;

        while (aux2->sig != NULL)
        {
            aux2 = aux2->sig;
        }

        
        aux2->sig = aux;
        aux = NULL;
        aux2 = aux;

        free(aux);
        free(aux2);
		
	}	

	
	
	}
	
	/*
	Mostrar Inventario: Listar todos los productos en el inventario, mostrando su ID, 
	nombre, cantidad y precio por unidad. (+10 Puntos)
	*/
	
	void MostrarInventario(){
		
	for(aux=cab; aux!=NULL; aux=aux->sig){
		
	cout<<"\nID del Producto: "<<aux->ID<<endl<<"Nombre del producto: "<<aux->nombre<<endl<<"Numero de unidades del producto: "<<aux->cantidad<<endl<< "Precio por unidad: "<<"$"<<aux->precioUni<<endl;
	
	}
	
}

//Buscar Producto por ID: Buscar y mostrar la información de un producto utilizando su ID. (+10 Puntos)


void BuscarProducto(){
	
	int buscar=0;

	cout<<"Digite el ID del producto que desea buscar: ";
    cin>>buscar;
    
	
	aux=cab;

	for (aux = cab; aux != NULL; aux=aux->sig){

		if(aux->ID==buscar){
            
       	cout<<"\nID del Producto: "<<aux->ID<<endl<<"Nombre del producto: "<<aux->nombre<<endl<<"Numero de unidades del producto: "<<aux->cantidad<<endl<< "Precio por unidad: "<<"$"<<aux->precioUni<<endl;

		    } 
		
	}

    cout<<" ERROR, El ID del producto no ha sido encontrado\n";
    
}
	




/*
Eliminar Producto: Eliminar un producto del inventario basado en su ID. Esta operación debe remover el primer 
producto que coincida con el ID proporcionado. (+20 Puntos)
*/

int EliminarProducto() {
    int eliminar;
    cout << "\nIngrese el ID del producto que desea eliminar: ";
    cin >> eliminar;

    
    if (cab != NULL && cab->ID == eliminar) {
        aux = cab;
        cab = cab->sig;
        free(aux);
        cout << "\nEl producto ha sido eliminado correctamente\n";
        return 0;
    }

   
    aux2 = cab;
    while (aux2->sig != NULL) {
        if (aux2->sig->ID == eliminar) {
            aux = aux2->sig;
            aux2->sig = aux->sig;
            free(aux);
            cout << "\nEl producto ha sido eliminado correctamente\n";
            return 0;
        }
        aux2 = aux2->sig;
    }

    cout << "\nEl ID ingresado no concuerda con ninguno de los disponibles en nuestro inventario\n";
    return 0;
}

/*
Calcular el Valor Total del Inventario: Sumar el valor total de todos los productos en el inventario
 (Cantidad * Precio por unidad) y mostrar el resultado. (+10 Puntos)
*/

int CalcularValorInventario(){
	
	
	double PrecioTotal=0;
	double Total=0;
	
	cout<<"\nEl valor total de los producto del inventario es:\n";
	
		for(aux=cab; aux!=NULL; aux=aux->sig){
			
		PrecioTotal=aux->cantidad * aux->precioUni;
		Total+=PrecioTotal;
		
	cout<<"\nID del Producto: "<<aux->ID<<endl<<"Nombre del producto: "<<aux->nombre<<endl<<"Precio total del producto: "<<"$"<<PrecioTotal<<endl;
	
	}
	cout<<"\nEl valor total del inventario es: "<<"$"<<Total<<endl;
	return 0;
}

/*
Calcular el Promedio de Precios: Determinar el precio promedio por unidad de 
todos los productos en el inventario. (+10 Puntos)
*/

/*
El enunciado "Calcular el Promedio de Precios: Determinar el precio promedio por unidad de
todos los productos en el inventario" se refiere a la tarea de encontrar el precio promedio
que se paga por unidad de todos los productos disponibles en un inventario. 

Para calcular el precio promedio, primero necesitas sumar todos 
los precios individuales de los productos en el inventario y luego dividir esa suma por la cantidad
 total de productos. Esto te dará el precio promedio por unidad.
*/

void CalcularPromedioPrecios(){
	
	double PrecioTotal=0;
	double Total=0;

	//I de inicio, F de Final
	double IsumaPrecios=0;
	double ICantidadTotalProductos=0;
	double FsumaPrecios=0;
	double FCantidadTotalProductos=0;
	double promedio=0;
	
	if(cab==NULL){
		
		cout<<"\nNo se encuentra ningun producto en el inventario\n";
	} 
	
	
	for (aux = cab; aux != NULL; aux=aux->sig){
		
	PrecioTotal=aux->cantidad * aux->precioUni;
	Total+=PrecioTotal;
	
	IsumaPrecios= aux->precioUni;
	ICantidadTotalProductos= aux->cantidad;
	
	FsumaPrecios+=IsumaPrecios;
	FCantidadTotalProductos+=ICantidadTotalProductos;
	
	promedio=(Total)/FCantidadTotalProductos;
	
	
    
	} 
	cout<<"\nLa Cantidad total de productos en el inventario es: "<<FCantidadTotalProductos<<"\n";
    cout<<"El precio promedio por unidad es: "<<"$"<<promedio<<"\n";
}

/*
Vender Productos: Permitir la venta de productos mediante el siguiente proceso:

Solicitar al usuario el ID del producto a vender.
Buscar el producto por su ID y mostrar su información.
Preguntar al usuario la cantidad de unidades que desea comprar. 
Verificar si hay existencias suficientes del producto. Si no hay suficientes, informar al usuario y cancelar la venta.(+10 Puntos)
Si hay existencias suficientes, descontar la cantidad vendida del inventario y calcular el total a pagar (Cantidad * Precio por unidad). (+10 Puntos)
Mostrar al usuario el total a pagar por los productos vendidos. (+10 Puntos)
*/

int Vender(){

  int CantidadVenta=0;
    int ID_Vender=0;
    cout<<"\nIngrese el ID del producto que desea vender: ";
    cin>>ID_Vender;
    
            

    for (aux = cab; aux != NULL; aux = aux->sig){

        if (ID_Vender == aux->ID){
            cout<<"\nEl producto digitado ha sido encontrado exitosamente...\n";
            cout<<"\n..Mostrando el producto digitado...\n\n";
			cout<<"\nID del Producto: "<<aux->ID<<endl<<"Nombre del producto: "<<aux->nombre<<endl<<"Numero de unidades del producto: "<<aux->cantidad<<endl<< "Precio por unidad: "<<"$"<<aux->precioUni<<endl;
            cout<<"\nIngrese el total de unidades del producto que desea comprar: ";
		    cin >> CantidadVenta;

            if (CantidadVenta <= aux->cantidad){
                aux->cantidad = aux->cantidad - CantidadVenta;

                cout<<"\n\tCOMPRA EXITOSA\n";
                cout<<"\n\tImprimiendo actualizacion del producto:\n";
                cout<<"\nID del Producto: "<<aux->ID<<endl<<"Nombre del producto: "<<aux->nombre<<endl<<"Numero de unidades del producto: "<<aux->cantidad<<endl<< "Precio por unidad: "<<"$"<<aux->precioUni<<endl;

                

                double RENTABILIDAD = 0;

                RENTABILIDAD = CantidadVenta * aux->precioUni;

                cout<<"La ganancia obtenida por la venta es:" <<"$"<< RENTABILIDAD << endl;
            }
            
            
            
        }
        if (CantidadVenta > aux->cantidad && aux->cantidad!=NULL){
                cout<<"\nERROR. El producto no cuenta con la cantidad de unidades ingresadas..." << endl;
                cout<<"...Cancenlando Venta...\n";
                cout<<"\tVENTA CANCELADA\n";
                
            }
        if (aux->cantidad==NULL){
                cout<<"\nERROR. El producto no cuenta con la cantidad de unidades ingresadas..." << endl;
                cout<<"...Cancenlando Venta...\n";
                cout<<"\tVENTA CANCELADA\n";
                
            }
    }

return 0;
}

