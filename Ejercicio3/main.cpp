#include <iostream>
#include <string>
using namespace std;
const int N=10; // colcar un tamaño de pila

//3. Suponga que administra un estacionamiento en forma de callejón(pila), cuenta con Cochera1,
//Cochera2 para 10 autos cada una, ambas solamente tienen una puerta de entrada/salida, y
//que el valor hora es $100- Se diseña una estructura auto con los datos: placa, propietario, y
//hora de entrada.
//A- Si desea estacionar un auto en Cochera1 o Cochera2, el sistema solicita sus datos, y agrega.
//B- Habrá un procedimiento para mostrar las cocheras por orden de salida de los vehículos. 

// Definimos la estructura auto
struct Auto {
    string placa;
    string propietario;
    int horaEntrada;
};

struct Pila {
private:
    int tope;
    Auto autos[N];

public:
    Pila() {
        tope = -1; // Inicializamos el tope a -1 = la pila está vacía
    }

    void push(Auto autoNuevo) {
        if (tope < N - 1) {
            tope++; // 1- subir el tope
            autos[tope] = autoNuevo; // 2- push del elemento en el lugar libre
            cout << "Auto con placa " << autoNuevo.placa << " ha sido agregado a la posición " << tope << endl;
        } else {
            cout << "La pila está llenísima!" << endl;
        }
    }

    Auto verTope() {
        // devolve ese elemento
        if (tope >= 0) {
            return autos[tope];
        } else {
            cout << "La pila no tiene nada" << endl;
            return Auto(); // devuelve un objeto Auto vacío
        }
    }

    void pop() {
        // bajamos el tope en otras palabraas apunta al último accesible
        if (tope >= 0) {
            cout << "Auto con placa " << autos[tope].placa << " ha sido removido" << endl;
            tope--;
        } else {
            cout << "La pila está vacía" << endl;
        }
    }

    bool pilaVacia() {
        return tope == -1;
    }

    bool pilaLlena() {
        return tope == N - 1;
    }

    int getTope() { // devolve el tope de la pila
        return tope;
    }

    void mostrarCochera() {
        if (pilaVacia()) {
            cout << "La cochera está vacía" << endl;
        } else {
            for (int i = tope; i >= 0; i--) {
                cout << "Placa: " << autos[i].placa << ", Propietario: " << autos[i].propietario << ", Hora de entrada: " << autos[i].horaEntrada << endl;
            }
        }
    }
};

int main() {
    Pila cochera1, cochera2;
    Auto auto1 = {"aaa", "Lucas Perez", 9};
    Auto auto2 = {"bbb", "Jose", 10};
    Auto auto3 = {"ccc", "Mauro", 11};
	
//	cochera1.mostrarCochera();
	
    cochera1.push(auto1);
	cochera1.push(auto3);
    cochera2.push(auto2);

    cout << "Estado de Cochera1:" << endl;
    cochera1.mostrarCochera();

    cochera1.pop();
    cout << "Estado de Cochera1 después de un pop:" << endl;
    cochera1.mostrarCochera();

    return 0;
}


