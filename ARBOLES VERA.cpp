#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

struct arbol {
    int codigo;
    char nombre[50];
    char apellido[50];
    int year;
    int mes;
    int dia;
    arbol* izq;
    arbol* der;
};

arbol* raiz = NULL;
arbol* raizF = NULL;
arbol* aux;
arbol* aux2;
arbol* aux3;
arbol* aux4;
arbol* nodoC;
arbol* nodoF;

void organizarcodigo(arbol* &nodo, arbol* &raiz) {
    if (nodo->codigo < aux2->codigo) {
        if (aux2->izq != NULL) {
            aux2 = aux2->izq;
            organizarcodigo(nodo, raiz);
        } else {
            aux2->izq = nodo;
        }
    } else if (nodo->codigo >= aux2->codigo) {
        if (aux2->der != NULL) {
            aux2 = aux2->der;
            organizarcodigo(nodo, raiz);
        } else {
            aux2->der = nodo;
        }
    }
}

void organizarfecha(arbol* &nodo, arbol* &raizF) {
    if (nodo->dia != aux4->dia && nodo->mes != aux4->mes && nodo->year != aux4->year) {
        if (aux4->izq != NULL) {
            aux4 = aux4->izq;
            organizarfecha(nodo, raizF);
        } else {
            aux4->izq = nodo;
        }
    } else if (nodo->dia == aux4->dia && nodo->mes == aux4->mes && nodo->year == aux4->year) {
        if (aux4->der != NULL) {
            aux4 = aux4->der;
            organizarfecha(nodo, raizF);
        } else {
            aux4->der = nodo;
        }
    }
}

void registrar() {
    int codigoIngresado;
    string nombreIngresado;
    string apellidoIngresado;
    int yearIngresado = 0, mesIngresado = 0, diaIngresado = 0;

    cout << "\nDigite el codigo del estudiante: ";
    cin >> codigoIngresado;

    cout << "\nDigite el nombre del estudiante: ";
    cin.ignore();
    getline(cin, nombreIngresado);

    cout << "\nDigite el apellido del estudiante: ";
    getline(cin, apellidoIngresado);

    cout << "\nDigite la fecha de nacimiento del estudiante: \n";
    cout << "\nDigite el dia en el que nacio el estudiante: ";
    cin >> diaIngresado;

    cout << "\nDigite el mes en el que nacio el estudiante: ";
    cin >> mesIngresado;

    cout << "\nDigite el year en el que nacio el estudiante: ";
    cin >> yearIngresado;

    // Crear nodo para organizar por código
    nodoC = new arbol;
    nodoC->codigo = codigoIngresado;
    strcpy(nodoC->nombre, nombreIngresado.c_str());
    strcpy(nodoC->apellido, apellidoIngresado.c_str());
    nodoC->dia = diaIngresado;
    nodoC->mes = mesIngresado;
    nodoC->year = yearIngresado;
    nodoC->izq = NULL;
    nodoC->der = NULL;

    if (raiz == NULL) {
        raiz = nodoC;
    } else {
        aux2 = raiz;
        organizarcodigo(nodoC, raiz);
    }

    // Crear nodo para organizar por fecha
    nodoF = new arbol;
    nodoF->codigo = codigoIngresado;
    strcpy(nodoF->nombre, nombreIngresado.c_str());
    strcpy(nodoF->apellido, apellidoIngresado.c_str());
    nodoF->dia = diaIngresado;
    nodoF->mes = mesIngresado;
    nodoF->year = yearIngresado;
    nodoF->izq = NULL;
    nodoF->der = NULL;

    if (raizF == NULL) {
        raizF = nodoF;
    } else {
        aux4 = raizF;
        organizarfecha(nodoF, raizF);
    }
}

void preorden(arbol *aux3) {
    if (aux3 != NULL) {
        cout << "\nEl codigo del estudiante es: " << aux3->codigo << endl;
        cout << "El nombre del estudiante es: " << aux3->nombre << " " << aux3->apellido << endl;
        cout << "La fecha de nacimiento del estudiante es: " << aux3->dia << "/" << aux3->mes << "/" << aux3->year << endl;
        preorden(aux3->izq);
        preorden(aux3->der);
    }
}

void inorden(arbol *aux3) {
    if (aux3 != NULL) {
        inorden(aux3->izq);
        cout << "\nEl codigo del estudiante es: " << aux3->codigo << endl;
        cout << "El nombre del estudiante es: " << aux3->nombre << " " << aux3->apellido << endl;
        cout << "La fecha de nacimiento del estudiante es: " << aux3->dia << "/" << aux3->mes << "/" << aux3->year << endl;
        inorden(aux3->der);
    }
}

void postorden(arbol *aux3) {
    if (aux3 != NULL) {
        postorden(aux3->izq);
        postorden(aux3->der);
        cout << "\nEl codigo del estudiante es: " << aux3->codigo << endl;
        cout << "El nombre del estudiante es: " << aux3->nombre << " " << aux3->apellido << endl;
        cout << "La fecha de nacimiento del estudiante es: " << aux3->dia << "/" << aux3->mes << "/" << aux3->year << endl;
    }
}

arbol* buscarNodo(int codigo) {
    arbol* nodo = raiz;
    while (nodo != NULL && nodo->codigo != codigo) {
        if (codigo < nodo->codigo) {
            nodo = nodo->izq;
        } else {
            nodo = nodo->der;
        }
    }
    return nodo;
}

void buscar() {
    int codigoBuscado;
    cout << "\nDigite el codigo del estudiante que desea buscar: ";
    cin >> codigoBuscado;
    arbol* nodoEncontrado = buscarNodo(codigoBuscado);
    if (nodoEncontrado != NULL) {
        cout << "\nEstudiante encontrado:\n";
        cout << "Codigo: " << nodoEncontrado->codigo << endl;
        cout << "Nombre: " << nodoEncontrado->nombre << " " << nodoEncontrado->apellido << endl;
        cout << "Fecha de nacimiento: " << nodoEncontrado->dia << "/" << nodoEncontrado->mes << "/" << nodoEncontrado->year << endl;
    } else {
        cout << "\nEstudiante no encontrado.\n";
    }
}

arbol* encontrarMinimo(arbol* nodo) {
    while (nodo->izq != NULL) {
        nodo = nodo->izq;
    }
    return nodo;
}

void eliminar() {
   
}

arbol* eliminarNodo(arbol* raiz, int codigo) {
    if (raiz == NULL) {
        return raiz;
    }
    if (codigo < raiz->codigo) {
        raiz->izq = eliminarNodo(raiz->izq, codigo);
    } else if (codigo > raiz->codigo) {
        raiz->der = eliminarNodo(raiz->der, codigo);
    } else {
        if (raiz->izq == NULL) {
            arbol* temp = raiz->der;
            delete raiz;
            return temp;
        } else if (raiz->der == NULL) {
            arbol* temp = raiz->izq;
            delete raiz;
            return temp;
        }
        arbol* temp = encontrarMinimo(raiz->der);
        raiz->codigo = temp->codigo;
        raiz->der = eliminarNodo(raiz->der, temp->codigo);
    }
    return raiz;
}

int main() {
    int opc = 0;
    do {
        cout << "\n\tMENU\n";
        cout << "\n\t1) Registrar\n";
        cout << "\t2) Mostrar Preorden\n";
        cout << "\t3) Mostrar Inorden\n";
        cout << "\t4) Mostrar Postorden\n";
        cout << "\t5) Buscar\n";
        cout << "\t6) Organizar por fecha\n";
        cout << "\t7) Organizar por codigo\n";
        cout << "\t8) Eliminar\n";
        cout << "\t9) Salir\n";
        cout << "\nDigite la opcion que desea realizar: ";
        cin >> opc;
        switch (opc) {
            case 1:
                registrar();
                break;
            case 2:
                cout << "\n\t...IMPRIMIENDO LOS DATOS DEL ESTUDIANTE EN PREORDEN...\n";
                preorden(raiz);
                break;
            case 3:
                cout << "\n\t...IMPRIMIENDO LOS DATOS DEL ESTUDIANTE EN INORDEN...\n";
                inorden(raiz);
                break;
            case 4:
                cout << "\n\t...IMPRIMIENDO LOS DATOS DEL ESTUDIANTE EN POSTORDEN...\n";
                postorden(raiz);
                break;
            case 5:
                buscar();
                break;
            case 6:
                organizarcodigo(nodoC, raiz);
                break;
            case 7:
                organizarfecha(nodoF, raizF);
                break;
            case 8:
                eliminar();
                break;
            case 9:
                cout << "\nGracias por usar nuestro programa... Saliendo\n";
                cout << "...finalized...";
                break;
            default:
                cout << "\nLa opcion digitada no se encuentra disponible, por favor digite la opcion nuevamente: \n";
                break;
        }
    } while (opc != 9);
    getch();
    return 0;
}
