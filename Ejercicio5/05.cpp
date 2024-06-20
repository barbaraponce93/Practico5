/*
5. Se desea modelar las filas de un banco, de cada persona se sabe el DNI y la operación que desea realizar, 
según un menú de opciones las operaciones son depósitos(D), extracciones(E), varios (O). 
Declare tres Queues de cada tipo de operación correspondiente.
A. Inicialmente la gente forma 1 fila, cuando comienza la atención las personas se distribuyen según la operación, 
sacando un turno (botón “Simular turno”).
B. Modele estructura persona. Debe introducir por una pantalla un DNI, y elegir el tipo de operación, según sea, 
se encola la persona para ser atendida en la fila correspondiente.
C. Otra función “atender”, ira sacando gente de la fila elegida por orden de llegada.
D. Se deben averiguar cuál es el último número agregado a cierta cola. Ej. Ultimo DNI en Extracción
*/

#include <iostream>
using namespace std;

const int MAX=5;

struct Persona{
	int dni;
	char operacion;	
};

struct Fila {
private:
    string nombre;
    Persona fila[MAX]; // Array de Personas en lugar de enteros
    int p = 0;
    int u = -1;
    int cant = 0;

public:
    Fila(const string &n) : nombre(n) {}

    bool filaVacia() { // EMPTY
        return cant == 0;
    }
    bool filaLlena() { // FULL
        return cant == MAX;
    }
    void Enfilar(Persona elem) { // ENQUEUE
        if (!filaLlena()) {
            u = (u + 1) % MAX;
            fila[u] = elem;
            cant++;
        } else
            cout <<"No se puede enfilar" << endl;
    }
    void Desenfilar() { // DEQUEUE
        if (!filaVacia()) {
            p = (p + 1) % MAX;
            cant--;
        } else
            cout<<"No se puede eliminar"<<endl;
    }
    Persona verPrimero() { // FRONT
        return fila[p];
    }
    Persona verUltimo() { // BACK
        return fila[u];
    }
    int getCantidad() {
        return cant;
    }
    string getNombre(){
    	return nombre;
	}
    void vaciarFila() {
        p = 0;
        u = -1;
        cant = 0;
    }
};

void atenderFila(Fila &fila){
	if(!fila.filaVacia()){
        Persona primeraPersonaEnFila = fila.verPrimero();
        fila.Desenfilar();
        cout<<"\nSe atiende a la persona con DNI "<<primeraPersonaEnFila.dni<<" de la "<<fila.getNombre()<<".\n"<<endl;
	}else{
		cout<<"\nNo hay nadie en la "<<fila.getNombre()<<".\n"<<endl;
	}
	system("PAUSE");
}

void verUltimoDNI(Fila &fila){
	cout<<"\nEl ultimo DNI de la "<<fila.getNombre()<<" es "<<fila.verUltimo().dni<<".\n"<<endl;
}

int main() {
	
	Fila filaGeneral("Fila General"), filaD("Fila Depositos"), filaE("Fila Extracciones"), filaO("Fila Varios");
	Persona persona;
	
	for(int i=0;i<5;i++){
		filaGeneral.Enfilar(persona);
	}
	
	int opcion;
    while (true) {
    	cout<<"\nMenu de opciones\n"<<endl;
        cout<<"1. Simular turno"<<endl;
        cout<<"2. Atender Depositos"<<endl;
        cout<<"3. Atender Extracciones"<<endl;
        cout<<"4. Atender Varios"<<endl;
        cout<<"5. Ver ultimo DNI en cola"<<endl;
        cout<<"6. Salir\n"<<endl;
        cout<<"Elija una opcion: ";
        cin>>opcion;
		
		string nombreFila;
        bool enfilado;
        Persona primeraPersonaEnFilaGeneral;
		
        switch (opcion) {
            case 1:
            	if(filaGeneral.filaVacia()){
            		cout<<"\nNo hay nadie en la Fila General\n"<<endl;
            		system("PAUSE");
            		break;
				}
            	primeraPersonaEnFilaGeneral=filaGeneral.verPrimero();
            	enfilado=false;
            	cout<<"\nSe atiende a la primera persona de la fila general"<<endl;
                cout << "Ingrese DNI: ";
                cin >> primeraPersonaEnFilaGeneral.dni;
                cout << "Ingrese operacion (D para Depositos, E para Extracciones, O para Otros): ";
                cin >> primeraPersonaEnFilaGeneral.operacion;
                
                switch (primeraPersonaEnFilaGeneral.operacion){
                	case 'D':
                		filaD.Enfilar(primeraPersonaEnFilaGeneral);
                		nombreFila = filaD.getNombre();
                		enfilado=true;		
                		break;
                	case 'E':
						filaE.Enfilar(primeraPersonaEnFilaGeneral);
						nombreFila = filaE.getNombre();
                		enfilado=true;
						break;
					case 'O':
						filaO.Enfilar(primeraPersonaEnFilaGeneral);
						nombreFila = filaO.getNombre();
                		enfilado=true;
						break;
					default:
						cout<<"\nOpcion no valida.\n"<<endl;
						system("PAUSE");		
				}
				
				if(enfilado){
					filaGeneral.Desenfilar();
					cout<<"\nLa persona con DNI "<<primeraPersonaEnFilaGeneral.dni<<" fue agregada a la "<<nombreFila<<".\n"<<endl;
					system("PAUSE");
				}
                break;
            case 2:
                atenderFila(filaD);
                break;
            case 3:
                atenderFila(filaE);
                break;
            case 4:
                atenderFila(filaO);
                break;
            case 5:
            	char operacion;
                cout<<"Ingrese operacion para ver el ultimo DNI (D para Depositos, E para Extracciones, O para Otros): ";
                cin>>operacion;
                switch (operacion){
                	case 'D':
                		verUltimoDNI(filaD);	
                		break;
                	case 'E':
						verUltimoDNI(filaE);
						break;
					case 'O':
						verUltimoDNI(filaO);
						break;
					default:
						cout<<"\nOpcion no valida.\n"<<endl;
						system("PAUSE");		
				}
                break;
            case 6:
                return 0;
            default:
                cout<<"\nOpcion no valida.\n"<<endl;
                system("PAUSE");
        }
    }
    return 0;
}
