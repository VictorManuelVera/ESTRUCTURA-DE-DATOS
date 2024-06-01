#include <iostream>
#include <malloc.h> // Para usar malloc y free
#include <conio.h>
#include <cstring>

using namespace std;

struct Pasajero {
    char nombre[50];
    Pasajero* siguiente;
};

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
    strcpy(nuevoNodo->destino, destino);
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
    sprintf(nuevoNodo->identificador, "%.2s%04d%02d%02d", matricula, year, mes, dia);
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
