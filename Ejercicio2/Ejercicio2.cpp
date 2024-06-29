#include <iostream>
#include <locale.h>
using namespace std;

const int N = 10; 

class Pila {
private:
    int tope;
    int elementos[N];

public:
    Pila() {
        tope = -1; 
    }

    void push(int elemento) {
        if (tope < N - 1) {
            tope++; 
            elementos[tope] = elemento; 
            cout << "Elemento " << elemento << " ha sido agregado a la posición " << tope << endl;
        } else {
            cout << "La pila está llena!" << endl;
        }
    }

    int verTope() {
        if (tope >= 0) {
            return elementos[tope];
        } else {
            cout << "La pila está vacía" << endl;
            return -1; 
        }
    }

    void pop() {
        if (tope >= 0) {
            cout << "Elemento " << elementos[tope] << " ha sido removido" << endl;
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

    int getTope() { 
        return tope;
    }

    void mostrarPila() {
        if (pilaVacia()) {
            cout << "La pila está vacía" << endl;
        } else {
            for (int i = tope; i >= 0; i--) {
                cout << "Elemento: " << elementos[i] << endl;
            }
        }
    }
};

void invierteConAux(Pila& pilaA, Pila& pilaB, Pila& pilaC) {
    while (!pilaA.pilaVacia()) {
        pilaC.push(pilaA.verTope()); // Mover de A a C
        pilaA.pop();
    }
    while (!pilaC.pilaVacia()) {
        pilaB.push(pilaC.verTope()); // Mover de C a B
        pilaC.pop();
    }
}

void invierteSinAux(Pila& pilaA, Pila& pilaB) {
    Pila temp;
    while (!pilaA.pilaVacia()) {
        temp.push(pilaA.verTope());
        pilaA.pop();
    }
    while (!temp.pilaVacia()) {
        pilaB.push(temp.verTope());
        temp.pop();
    }
}

void reemplazar(Pila& pilaA, int x, int y) {
    Pila temp;
    while (!pilaA.pilaVacia()) {
        int val = pilaA.verTope();
        pilaA.pop();
        if (val == x) val = y;
        temp.push(val);
    }
    while (!temp.pilaVacia()) {
        pilaA.push(temp.verTope());
        temp.pop();
    }
}

int main() {
    setlocale(LC_ALL,"Spanish");
    Pila pilaA, pilaB, pilaC;

    pilaA.push(1);
    pilaA.push(2);
    pilaA.push(3);

    cout << "Pila A: ";
    pilaA.mostrarPila();
    cout << endl;

    invierteConAux(pilaA, pilaB, pilaC);

    cout << "Pila B después de invertir pila A: ";
    pilaB.mostrarPila();
    cout << endl;

    pilaA.push(1);
    pilaA.push(2);
    pilaA.push(3);

    invierteSinAux(pilaA, pilaB);

    cout << "Pila B después de invertir pila A sin auxiliar: ";
    pilaB.mostrarPila();
    cout << endl;

    pilaA.push(1);
    pilaA.push(2);
    pilaA.push(3);

    reemplazar(pilaA, 2, 5);

    cout << "Pila A después de reemplazar 2 por 5: ";
    pilaA.mostrarPila();
    cout << endl;

    return 0;
}


