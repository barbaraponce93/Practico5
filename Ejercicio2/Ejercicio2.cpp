#include <iostream>
#include <locale>

using namespace std;

struct Pila {
    int *elementos;
    int capacidad;
    int tope;

    Pila(int tam) {
        capacidad = tam;
        elementos = new int[capacidad];
        tope = -1;
    }

    ~Pila() {
        delete[] elementos;
    }

    bool estaVacia() {
        return tope == -1;
    }

    bool estaLlena() {
        return tope == capacidad - 1;
    }

    void push(int elemento) {
        if (!estaLlena()) {
            elementos[++tope] = elemento;
        } else {
            cout << "Error: Pila llena, no se puede insertar." << endl;
        }
    }

    void pop() {
        if (!estaVacia()) {
            --tope;
        } else {
            cout << "Error: Pila vacía, no se puede eliminar." << endl;
        }
    }

    int top() {
        if (!estaVacia()) {
            return elementos[tope];
        } else {
            cout << "Error: Pila vacía, no hay elemento en la cima." << endl;
            return -1; 
        }
    }
};

void invierteConAux(Pila& pilaA, Pila& pilaB, Pila& pilaC) {
    while (!pilaA.estaVacia()) {
        pilaC.push(pilaA.top()); // Mover de A a C
        pilaA.pop();
    }
    while (!pilaC.estaVacia()) {
        pilaB.push(pilaC.top()); // Mover de C a B
        pilaC.pop();
    }
}

void invierteSinAux(Pila& pilaA, Pila& pilaB) {
    Pila temp(pilaA.capacidad);
    while (!pilaA.estaVacia()) {
        temp.push(pilaA.top());
        pilaA.pop();
    }
    while (!temp.estaVacia()) {
        pilaB.push(temp.top());
        temp.pop();
    }
}

void reemplazar(Pila& pilaA, int x, int y) {
    Pila temp(pilaA.capacidad);
    while (!pilaA.estaVacia()) {
        int val = pilaA.top();
        pilaA.pop();
        if (val == x) val = y;
        temp.push(val);
    }
    while (!temp.estaVacia()) {
        pilaA.push(temp.top());
        temp.pop();
    }
}

int main() {
    Pila pilaA(5), pilaB(5), pilaC(5);

    pilaA.push(1);
    pilaA.push(2);
    pilaA.push(3);

    cout << "Pila A: ";
    while (!pilaA.estaVacia()) {
        cout << pilaA.top() << " ";
        pilaA.pop();
    }
    cout << endl;

    pilaA.push(1);
    pilaA.push(2);
    pilaA.push(3);

    invierteConAux(pilaA, pilaB, pilaC);

    cout << "Pila B después de invertir pila A: ";
    while (!pilaB.estaVacia()) {
        cout << pilaB.top() << " ";
        pilaB.pop();
    }
    cout << endl;

    pilaA.push(1);
    pilaA.push(2);
    pilaA.push(3);

    invierteSinAux(pilaA, pilaB);

    cout << "Pila B después de invertir pila A sin auxiliar: ";
    while (!pilaB.estaVacia()) {
        cout << pilaB.top() << " ";
        pilaB.pop();
    }
    cout << endl;

    pilaA.push(1);
    pilaA.push(2);
    pilaA.push(3);

    reemplazar(pilaA, 2, 5);

    cout << "Pila A después de reemplazar 2 por 5: ";
    while (!pilaA.estaVacia()) {
        cout << pilaA.top() << " ";
        pilaA.pop();
    }
    cout << endl;

    return 0;
}


