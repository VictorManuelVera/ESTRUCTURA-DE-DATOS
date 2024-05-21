#include <iostream>
#include <conio.h>
#include <cstring>
#include <malloc.h> // Para malloc y free
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
    int altura;
    nodo* izq;
    nodo* der;
    Pasajero* primerPasajero;
    Pasajero* ultimoPasajero;
    int numPasajeros;
};

nodo* raiz = NULL;

int altura(nodo* N) {
    if (N == NULL)
        return 0;
    return N->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

nodo* nuevoNodo(double precio, const char* destino, const char* matricula, const char* nombre, int dia, int mes, int year, int capacidad) {
    nodo* node = (nodo*)malloc(sizeof(nodo));
    node->Preciodelviaje = precio;
    strcpy(node->destino, destino);
    strcpy(node->MatriculaEmbarcacion, matricula);
    strcpy(node->NombreEmbarcacion, nombre);
    node->dia = dia;
    node->mes = mes;
    node->year = year;
    node->CapacidadEmbarcacion = capacidad;
    node->izq = NULL;
    node->der = NULL;
    node->altura = 1;
    node->primerPasajero = NULL;
    node->ultimoPasajero = NULL;
    node->numPasajeros = 0;
    sprintf(node->identificador, "%.2s%04d%02d%02d", matricula, year, mes, dia);
    return node;
}

nodo* rotacionDerecha(nodo* y) {
    nodo* x = y->izq;
    nodo* T2 = x->der;
    x->der = y;
    y->izq = T2;
    y->altura = max(altura(y->izq), altura(y->der)) + 1;
    x->altura = max(altura(x->izq), altura(x->der)) + 1;
    return x;
}

nodo* rotacionIzquierda(nodo* x) {
    nodo* y = x->der;
    nodo* T2 = y->izq;
    y->izq = x;
    x->der = T2;
    x->altura = max(altura(x->izq), altura(x->der)) + 1;
    y->altura = max(altura(y->izq), altura(y->der)) + 1;
    return y;
}

int getBalance(nodo* N) {
    if (N == NULL)
        return 0;
    return altura(N->izq) - altura(N->der);
}

nodo* insertar(nodo* node, double precio, const char* destino, const char* matricula, const char* nombre, int dia, int mes, int year, int capacidad) {
    if (node == NULL)
        return nuevoNodo(precio, destino, matricula, nombre, dia, mes, year, capacidad);

    char identificador[15];
    sprintf(identificador, "%.2s%04d%02d%02d", matricula, year, mes, dia);

    if (strcmp(identificador, node->identificador) < 0)
        node->izq = insertar(node->izq, precio, destino, matricula, nombre, dia, mes, year, capacidad);
    else if (strcmp(identificador, node->identificador) > 0)
        node->der = insertar(node->der, precio, destino, matricula, nombre, dia, mes, year, capacidad);
    else
        return node;

    node->altura = 1 + max(altura(node->izq), altura(node->der));

    int balance = getBalance(node);

    if (balance > 1 && strcmp(identificador, node->izq->identificador) < 0)
        return rotacionDerecha(node);

    if (balance < -1 && strcmp(identificador, node->der->identificador) > 0)
        return rotacionIzquierda(node);

    if (balance > 1 && strcmp(identificador, node->izq->identificador) > 0) {
        node->izq = rotacionIzquierda(node->izq);
        return rotacionDerecha(node);
    }

    if (balance < -1 && strcmp(identificador, node->der->identificador) < 0) {
        node->der = rotacionDerecha(node->der);
        return rotacionIzquierda(node);
    }

    return node;
}

nodo* buscar(nodo* root, const char* identificador) {
    if (root == NULL || strcmp(root->identificador, identificador) == 0)
        return root;

    if (strcmp(identificador, root->identificador) < 0)
        return buscar(root->izq, identificador);

    return buscar(root->der, identificador);
}

void preOrden(nodo* root) {
    if (root != NULL) {
        cout << root->identificador << " ";
        preOrden(root->izq);
        preOrden(root->der);
    }
}

nodo* minValueNode(nodo* node) {
    nodo* current = node;

    while (current->izq != NULL)
        current = current->izq;

    return current;
}

nodo* eliminar(nodo* root, const char* identificador) {
    if (root == NULL)
        return root;

    if (strcmp(identificador, root->identificador) < 0)
        root->izq = eliminar(root->izq, identificador);
    else if (strcmp(identificador, root->identificador) > 0)
        root->der = eliminar(root->der, identificador);
    else {
        if ((root->izq == NULL) || (root->der == NULL)) {
            nodo* temp = root->izq ? root->izq : root->der;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            nodo* temp = minValueNode(root->der);
            strcpy(root->identificador, temp->identificador);
            root->Preciodelviaje = temp->Preciodelviaje;
            strcpy(root->destino, temp->destino);
            strcpy(root->MatriculaEmbarcacion, temp->MatriculaEmbarcacion);
            strcpy(root->NombreEmbarcacion, temp->NombreEmbarcacion);
            root->dia = temp->dia;
            root->mes = temp->mes;
            root->year = temp->year;
            root->CapacidadEmbarcacion = temp->CapacidadEmbarcacion;
            root->numPasajeros = temp->numPasajeros;
            root->primerPasajero = temp->primerPasajero;
            root->ultimoPasajero = temp->ultimoPasajero;

            root->der = eliminar(root->der, temp->identificador);
        }
    }

    if (root == NULL)
        return root;

    root->altura = max(altura(root->izq), altura(root->der)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->izq) >= 0)
        return rotacionDerecha(root);

    if (balance > 1 && getBalance(root->izq) < 0) {
        root->izq = rotacionIzquierda(root->izq);
        return rotacionDerecha(root);
    }

    if (balance < -1 && getBalance(root->der) <= 0)
        return rotacionIzquierda(root);

    if (balance < -1 && getBalance(root->der) > 0) {
        root->der = rotacionDerecha(root->der);
        return rotacionIzquierda(root);
    }

    return root;
}

void registrarPasajero(nodo* root, const char* identificador, const char* nombrePasajero) {
    nodo* viaje = buscar(root, identificador);
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

void listarPasajeros(nodo* root, const char* identificador) {
    nodo* viaje = buscar(root, identificador);
    if (viaje != NULL) {
        cout << "\nPasajeros del viaje " << identificador << ":\n";
        Pasajero* actual = viaje->primerPasajero;
        while (actual != NULL) {
            cout << actual->nombre << endl;
            actual = actual->siguiente;
        }
    } else {
        cout << "\nViaje no encontrado.\n";
    }
}

void listarViajes(nodo* root) {
    if (root != NULL) {
        listarViajes(root->izq);
        cout << "Identificador: " << root->identificador << ", Precio: " << root->Preciodelviaje << ", Destino: " << root->destino
             << ", Matricula: " << root->MatriculaEmbarcacion << ", Nombre: " << root->NombreEmbarcacion
             << ", Fecha: " << root->dia << "/" << root->mes << "/" << root->year << ", Capacidad: " << root->CapacidadEmbarcacion << "\n";
        listarViajes(root->der);
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

    cout << "\nViaje registrado con éxito.\n";
}

void BuscarViaje() {
    char identificadorU[15];
    cout << "\nDigite el identificador unico del viaje que desea buscar: ";
    cin >> identificadorU;

    nodo* viaje = buscar(raiz, identificadorU);
    if (viaje != NULL) {
        cout << "\nViaje encontrado:\n";
        cout << "Identificador: " << viaje->identificador << endl;
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

void ListarViaje() {
    listarViajes(raiz);
}

void EliminarViaje() {
    char identificadorU[15];
    cout << "\nDigite el identificador unico del viaje que desea eliminar: ";
    cin >> identificadorU;
    raiz = eliminar(raiz, identificadorU);
    cout << "\nViaje eliminado con éxito.\n";
}

void registrarPasajero() {
    char identificadorU[15];
    char nombrePasajero[50];
    cout << "\nDigite el identificador unico del viaje: ";
    cin >> identificadorU;
    cout << "\nDigite el nombre del pasajero: ";
    cin.ignore();
    cin.getline(nombrePasajero, 50);
    registrarPasajero(raiz, identificadorU, nombrePasajero);
}

void listarPasajero() {
    char identificadorU[15];
    cout << "\nDigite el identificador unico del viaje: ";
    cin >> identificadorU;
    listarPasajeros(raiz, identificadorU);
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

