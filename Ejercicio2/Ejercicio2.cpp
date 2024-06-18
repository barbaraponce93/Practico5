#include <iostream>
#include <stack>

using namespace std;

void invierteConAux(stack<int>& pilaA, stack<int>& pilaB, stack<int>& pilaC) {
    while (!pilaA.empty()) {
        pilaC.push(pilaA.top()); // Mover de A a C
        pilaA.pop();
    }
    while (!pilaC.empty()) {
        pilaB.push(pilaC.top()); // Mover de C a B
        pilaC.pop();
    }
}

void invierteSinAux(stack<int>& pilaA, stack<int>& pilaB) {
    stack<int> temp;
    while (!pilaA.empty()) {
        temp.push(pilaA.top());
        pilaA.pop();
    }
    while (!temp.empty()) {
        pilaB.push(temp.top());
        temp.pop();
    }
}

void reemplazar(stack<int>& pilaA, int x, int y) {
    stack<int> temp;
    while (!pilaA.empty()) {
        int val = pilaA.top();
        pilaA.pop();
        if (val == x) val = y; // Reemplaza x por y
        temp.push(val);
    }
    while (!temp.empty()) {
        pilaA.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> pilaA, pilaB, pilaC;

    pilaA.push(1);
    pilaA.push(2);
    pilaA.push(3);

    cout << "Pila A: ";
    while (!pilaA.empty()) {
        cout << pilaA.top() << " ";
        pilaA.pop();
    }
    cout << endl;

    invierteConAux(pilaA, pilaB, pilaC);
    
    cout << "Pila B después de invertir pila A: ";
    while (!pilaB.empty()) {
        cout << pilaB.top() << " ";
        pilaB.pop();
    }
    cout << endl;

    pilaA.push(1);
    pilaA.push(2);
    pilaA.push(3);

    invierteSinAux(pilaA, pilaB);
    
    cout << "Pila B después de invertir pila A sin auxiliar: ";
    while (!pilaB.empty()) {
        cout << pilaB.top() << " ";
        pilaB.pop();
    }
    cout << endl;

    pilaA.push(1);
    pilaA.push(2);
    pilaA.push(3);

    reemplazar(pilaA, 2, 5);

    cout << "Pila A después de reemplazar 2 por 5: ";
    while (!pilaA.empty()) {
        cout << pilaA.top() << " ";
        pilaA.pop();
    }
    cout << endl;

    return 0;
}


