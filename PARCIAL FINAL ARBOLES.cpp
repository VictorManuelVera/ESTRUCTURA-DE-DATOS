#include <iostream>
#include <malloc.h> // Para usar malloc y free
#include <conio.h>
#include <cstring>//manipulación de cadenas de caracteres

using namespace std;

struct Pasajero {
    char nombre[50];
    Pasajero* siguiente;
};

  Pasajero* aux, *aux2;

struct nodo {
    char identificador[15]; // Identificador único
    double Preciodelviaje;
    char destino[50];
    char MatriculaEmbarcacion[50];
    char NombreEmbarcacion[50];
    int dia, mes, year;
    int CapacidadEmbarcacion;
    nodo *izq;
    nodo *der;
    int altura;
    Pasajero* primerPasajero;
    Pasajero* ultimoPasajero;
    int numPasajeros;
};

nodo *raiz = NULL;

int obtenerAltura(nodo *n) {
    if (n == NULL) {
        return 0;
    }
    return n->altura;
}

int mayor(int a, int b) {
    return (a > b) ? a : b;
}

nodo* crearNodo(double precio, const char* destino, const char* matricula, const char* nombre, int dia, int mes, int year, int capacidad) {
    nodo* nuevoNodo = (struct nodo*) malloc(sizeof(struct nodo));
    nuevoNodo->Preciodelviaje = precio;
    strcpy(nuevoNodo->destino, destino);//sirve para copiar el contenido de la cadena destino en el campo destino del nodo nuevoNodo.
    strcpy(nuevoNodo->MatriculaEmbarcacion, matricula);
    strcpy(nuevoNodo->NombreEmbarcacion, nombre);
    nuevoNodo->dia = dia;
    nuevoNodo->mes = mes;
    nuevoNodo->year = year;
    nuevoNodo->CapacidadEmbarcacion = capacidad;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    nuevoNodo->altura = 1;
    nuevoNodo->primerPasajero = NULL;
    nuevoNodo->ultimoPasajero = NULL;
    nuevoNodo->numPasajeros = 0;
    
    /* "sprintf" Es una función de la biblioteca estándar de C que permite formatear y almacenar una cadena 
	de caracteres en un buffer. Es similar a printf, pero en lugar de imprimir en la consola, almacena el resultado en una variable.*/
	
    sprintf(nuevoNodo->identificador, "%.2s%04d%02d%02d", matricula, year, mes, dia);/* estuve indagando fuertemente una forma en la cual
    se pudieran asignar los valores: 2primeros caracteres de la matricula y la fecha del viaje(dia, mes, year) a la variable identificador unico 
    y descubri esta funcion que lo que hace es: 
    
    Una la cadena de formato que especifica cómo se deben formatear y combinar los diferentes valores.
	*/
	
	//posdata: comparti la funcion de sprintf con algunos compañeros cercacnos que aun no sabian como asignar los valores al indenticador unico. att: Manuel Vera
    return nuevoNodo;
}

nodo* rotarDerecha(nodo *y) {
    nodo *x = y->izq;
    nodo *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = mayor(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;
    x->altura = mayor(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;

    return x;
}

nodo* rotarIzquierda(nodo *x) {
    nodo *y = x->der;
    nodo *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = mayor(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;
    y->altura = mayor(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;

    return y;
}

int obtenerBalance(nodo *n) {
    if (n == NULL) {
        return 0;
    }
    return obtenerAltura(n->izq) - obtenerAltura(n->der);
}

nodo* insertar(nodo* node, double precio, const char* destino, const char* matricula, const char* nombre, int dia, int mes, int year, int capacidad) {
    if (node == NULL) {
        return crearNodo(precio, destino, matricula, nombre, dia, mes, year, capacidad);
    }

    char identificador[15];
    sprintf(identificador, "%.2s%04d%02d%02d", matricula, year, mes, dia);

    if (strcmp(identificador, node->identificador) < 0) {
        node->izq = insertar(node->izq, precio, destino, matricula, nombre, dia, mes, year, capacidad);
    } else if (strcmp(identificador, node->identificador) > 0) {
        node->der = insertar(node->der, precio, destino, matricula, nombre, dia, mes, year, capacidad);
    } else {
        return node; // Identificador duplicado, no se hace nada
    }

    node->altura = 1 + mayor(obtenerAltura(node->izq), obtenerAltura(node->der));

    int balance = obtenerBalance(node);

    if (balance > 1 && strcmp(identificador, node->izq->identificador) < 0) {
        return rotarDerecha(node);
    }

    if (balance < -1 && strcmp(identificador, node->der->identificador) > 0) {
        return rotarIzquierda(node);
    }

    if (balance > 1 && strcmp(identificador, node->izq->identificador) > 0) {
        node->izq = rotarIzquierda(node->izq);
        return rotarDerecha(node);
    }

    if (balance < -1 && strcmp(identificador, node->der->identificador) < 0) {
        node->der = rotarDerecha(node->der);
        return rotarIzquierda(node);
    }

    return node;
}

void preOrden(nodo *node) {
    if (node != NULL) {
        cout << node->identificador << " ";
        preOrden(node->izq);
        preOrden(node->der);
    }
}


void RegistrarViaje() {
    double PreciodelviajeIngresado;
    string destinoIngresado;
    string MatriculaEmbarcacionIngresado;
    string NombreEmbarcacionIngresado;
    int diaIngresado, mesIngresado, yearIngresado;
    int CapacidadEmbarcacionIngresado;

    cout << "\n\tBIENVENIDO AL APARTADO DE REGISTRO, POR FAVOR DIGITE LOS DATOS SOLICITADOS" << endl;

    cout << "\nDigite el precio del viaje: " << "$ ";
    cin >> PreciodelviajeIngresado;

    cout << "\nDigite el destino del viaje: ";
    cin.ignore();
    getline(cin, destinoIngresado);

    cout << "\nDigite la matricula de la embarcacion: ";
    getline(cin, MatriculaEmbarcacionIngresado);

    cout << "\nDigite el nombre de la embarcacion: ";
    getline(cin, NombreEmbarcacionIngresado);

    cout << "\n\n\tDigite la Fecha del Viaje:\n";

    cout << "\nDigite el dia: ";
    cin >> diaIngresado;

    cout << "\nDigite el mes: ";
    cin >> mesIngresado;

    cout << "\nDigite el year: ";
    cin >> yearIngresado;

    cout << "\n\nDigite la capacidad de la embarcacion: ";
    cin >> CapacidadEmbarcacionIngresado;

    raiz = insertar(raiz, PreciodelviajeIngresado, destinoIngresado.c_str(), MatriculaEmbarcacionIngresado.c_str(), NombreEmbarcacionIngresado.c_str(), diaIngresado, mesIngresado, yearIngresado, CapacidadEmbarcacionIngresado);

    cout << "\nViaje Registrado Con Exito.\n";
}


//NODO para buscar los viajes
nodo* buscar(nodo* busqueda, const char* identificador) {
    if (busqueda == NULL || strcmp(busqueda->identificador, identificador) == 0)
        return busqueda;

    if (strcmp(identificador, busqueda->identificador) < 0)
        return buscar(busqueda->izq, identificador);

    return buscar(busqueda->der, identificador);
}

//FUNCIÓN para bucar viajes a traves del identificador único
void BuscarViaje(){	
	
    char identificadorU[50];
    cout << "\nDigite el identificador unico del viaje que desea buscar: ";
    cin >> identificadorU;

    nodo* viaje = buscar(raiz, identificadorU);
    if (viaje != NULL) {
        cout << "\nViaje encontrado:\n";
        cout << "\nIdentificador: " << viaje->identificador << endl;
        cout << "Precio: " << viaje->Preciodelviaje << endl;
        cout << "Destino: " << viaje->destino << endl;
        cout << "Matricula: " << viaje->MatriculaEmbarcacion << endl;
        cout << "Nombre: " << viaje->NombreEmbarcacion << endl;
        cout << "Fecha: " << viaje->dia << "/" << viaje->mes << "/" << viaje->year << endl;
        cout << "Capacidad: " << viaje->CapacidadEmbarcacion << endl;
    } else {
        cout << "\nViaje no encontrado.\n";
    }	

}

void ListarViaje(nodo *ListarV) {
    if (ListarV != NULL) {
        ListarViaje(ListarV->izq);
        cout<<"\n\t...LISTANDO VIAJES..."<<endl;
        cout << "\nIdentificador Unico: " << ListarV->identificador << "\nPrecio del viaje: " << ListarV->Preciodelviaje << " \nDestino: " << ListarV->destino
             << "\nMatricula de la embarcacion: " << ListarV->MatriculaEmbarcacion << "\nNombre de la embarcacion: " << ListarV->NombreEmbarcacion
             << "\nFecha del viaje: " << ListarV->dia << "/" << ListarV->mes << "/" << ListarV->year << " Capacidad de la Embarcacion: " << ListarV->CapacidadEmbarcacion << "\n";
        ListarViaje(ListarV->der);
    }
}

void EliminarViaje(){
	
	
}

void registrarPasajero(nodo* RegistrarP, const char* identificador, const char* nombrePasajero) {
    nodo* viaje = buscar(RegistrarP, identificador);
    if (viaje != NULL) {
        if (viaje->numPasajeros < viaje->CapacidadEmbarcacion) {
            Pasajero* nuevoPasajero = (Pasajero*)malloc(sizeof(Pasajero));
            strcpy(nuevoPasajero->nombre, nombrePasajero);
            nuevoPasajero->siguiente = NULL;
            if (viaje->primerPasajero == NULL) {
                viaje->primerPasajero = nuevoPasajero;
                viaje->ultimoPasajero = nuevoPasajero;
            } else {
                viaje->ultimoPasajero->siguiente = nuevoPasajero;
                viaje->ultimoPasajero = nuevoPasajero;
            }
            viaje->numPasajeros++;
            cout << "\nPasajero registrado con éxito.\n";
        } else {
            cout << "\nNo hay capacidad disponible en este viaje.\n";
        }
    } else {
        cout << "\nViaje no encontrado.\n";
    }
}


//Mostrar los pasajeros en el orden en el que fueron registrados
void listarPasajero() {
    char identificadorU[50];
    cout << "\nDigite el identificador unico del viaje: ";
    cin >> identificadorU;
    
    nodo* viaje = buscar(raiz, identificadorU);
    if (viaje == NULL) {
        cout << "\nViaje no encontrado.\n";
        return;
    }

    if (viaje->primerPasajero == NULL) {
        cout << "\nNo hay pasajeros registrados para este viaje.\n";
        return;
    }

    cout << "\nLista de pasajeros del viaje " << viaje->identificador << ":\n";
    
    // Apuntador auxiliar para recorrer la lista de pasajeros
    Pasajero* aux = viaje->primerPasajero;
    
    // Usando un bucle for para recorrer la lista
    for (Pasajero* aux2 = aux; aux2 != NULL; aux2 = aux2->siguiente) {
        cout << "\nNombre del pasajero" << aux2->nombre << endl;
		cout << "Identificador Unico del viaje: " << viaje->identificador << endl;
        cout << "Precio del viaje: " << viaje->Preciodelviaje << endl;
        cout << "Destino del viaje: " << viaje->destino << endl;
        cout << "Matricula de la embarcacion: " << viaje->MatriculaEmbarcacion << endl;
        cout << "Nombre de la embarcacion: " << viaje->NombreEmbarcacion << endl;
        cout << "Fecha del viaje: " << viaje->dia << "/" << viaje->mes << "/" << viaje->year << endl;
        cout << "Capacidad del viaje: " << viaje->CapacidadEmbarcacion << endl;
    }
}


int main() {
    int opcion = 0;

    do {
        cout << "\n\tMENU\n";
        cout << "\n\t1) Registrar un nuevo viaje";
        cout << "\n\t2) Buscar un viaje por identificador";
        cout << "\n\t3) Listar todos los viajes";
        cout << "\n\t4) Eliminar un viaje por identificador";
        cout << "\n\t5) Registrar un pasajero en un viaje";
        cout << "\n\t6) Listar todos los pasajeros de un viaje";
        cout << "\n\t7) Salir" << endl;

        cout << "\nDigite la opcion que desea realizar: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                RegistrarViaje();
                break;

            case 2:
                BuscarViaje();
                break;

            case 3:
                ListarViaje(raiz);
                break;

            case 4:
                EliminarViaje();
                break;

            case 5:
            	
				char identificador[50];
                char nombrePasajero[50];

                cout << "\nDigite el identificador unico del viaje: ";
                cin >> identificador;
                cout << "\nDigite el nombre del pasajero: ";
                cin.ignore();
                cin.getline(nombrePasajero, 50);
                registrarPasajero(raiz, identificador, nombrePasajero);
                break;

            case 6:
                listarPasajero();
                break;

            case 7:
                cout << "\nGracias por usar nuestro programa... Saliendo\n";
                cout << "...finalized...";
                break;

            default:
                cout << "\nLa opcion que digitaste no se encuentra disponible, por favor digite la opcion nuevamente: \n";
                break;
        }

    } while (opcion != 7);

    getch();
    return 0;
}
