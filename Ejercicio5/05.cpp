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

const int MAX=5; // Maximo tamaño de la fila

struct Persona{
	int dni;
	char operacion;	
};

struct Fila {
private:
    string nombre;
    Persona fila[MAX]; // Array de PersonaS
    int p = 0;
    int u = -1;
    int cant = 0;

public:
    Fila(const string &n) : nombre(n) {}

    bool filaVacia() {
        return cant == 0;
    }
    bool filaLlena() {
        return cant == MAX;
    }
    void Enfilar(Persona elem) { // Agrega una persona a la fila
        if (!filaLlena()) {
            u = (u + 1) % MAX; // Actualiza el indice de la ultima persona en la fila
            fila[u] = elem;
            cant++;
        } else
            cout <<"No se puede enfilar" << endl;
    }
    void Desenfilar() { // Remueve una persona de la fila
        if (!filaVacia()) {
            p = (p + 1) % MAX; // Actualiza el indice de la primer persona en la fila
            cant--;
            if (filaVacia()) { // Reinicia los indices si la fila queda vacia
                p = 0;
                u = -1;
            }
        } else
            cout<<"No se puede eliminar"<<endl;
    }
    Persona verPrimero() { 
        return fila[p];
    }
    Persona verUltimo() { 
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

void enfilarPersona(Fila &filaGeneral, Fila &fila, Persona &persona){ // Funcion para enfilar una persona en una fila
	if(!fila.filaLlena()){
		fila.Enfilar(persona);
		cout<<"\nLa persona con DNI "<<persona.dni<<" fue agregada a la "<<fila.getNombre()<<".\n"<<endl;
		filaGeneral.Desenfilar();
	}else{
		cout<<"\nLa fila "<<fila.getNombre()<<" esta llena.\n"<<endl;
	}
	system("PAUSE");
}


void atenderFila(Fila &fila){ // Funcion para atender a una persona en una fila
	if(!fila.filaVacia()){
        cout<<"\nSe atiende a la persona con DNI "<<fila.verPrimero().dni<<" de la "<<fila.getNombre()<<".\n"<<endl;
        fila.Desenfilar();
	}else{
		cout<<"\nNo hay nadie en la "<<fila.getNombre()<<".\n"<<endl;
	}
	system("PAUSE");
}

void verUltimoDNI(Fila &fila) { // Funcion para ver el ultimo DNI en una fila
    if (!fila.filaVacia()) {
        cout << "\nEl ultimo DNI de la " << fila.getNombre() << " es " << fila.verUltimo().dni << ".\n" << endl;
    } else {
        cout << "\nLa " << fila.getNombre() << " esta vacia.\n" << endl;
    }
    system("PAUSE");
}

int main() {
	
	Fila filaGeneral("Fila General"), filaD("Fila Depositos"), filaE("Fila Extracciones"), filaO("Fila Varios");
	Persona persona;
	
	for(int i=0;i<5;i++){ // Inicializa la fila general con personas
		filaGeneral.Enfilar(persona);
	}
	
	int opcion;
    while (true) {
    	cout<<"\nMenu de opciones\n"<<endl;
        cout<<"1. Simular turno"<<endl;
        cout<<"2. Atender Depositos"<<endl;
        cout<<"3. Atender Extracciones"<<endl;
        cout<<"4. Atender Varios"<<endl;
        cout<<"5. Ver ultimo DNI en la fila"<<endl;
        cout<<"6. Salir\n"<<endl;
        cout<<"Elija una opcion: ";
        cin>>opcion;
		
        switch (opcion) {
            case 1:
            	if(filaGeneral.filaVacia()){
            		cout<<"\nNo hay nadie en la Fila General\n"<<endl;
            		system("PAUSE");
            		break;
				}
            	persona=filaGeneral.verPrimero();
            	cout<<"\nSe atiende a la primera persona de la fila general"<<endl;
                cout << "Ingrese DNI: ";
                cin >> persona.dni;
                cout << "Ingrese operacion (D para Depositos, E para Extracciones, O para Varios): ";
                cin >> persona.operacion;
                persona.operacion = toupper(persona.operacion);
                
                switch (persona.operacion){ // Enfila la persona en la fila que corresponda segun la letra
                	case 'D':
						enfilarPersona(filaGeneral,filaD,persona);
						break;
                	case 'E':
						enfilarPersona(filaGeneral,filaE,persona);
						break;
					case 'O':
						enfilarPersona(filaGeneral,filaO,persona);
						break;
					default:
						cout<<"\nOpcion no valida.\n"<<endl;
						system("PAUSE");				
				}
                break;
            case 2:
                atenderFila(filaD); // Se atiende segun la fila que se elija
                break;
            case 3:
                atenderFila(filaE);
                break;
            case 4:
                atenderFila(filaO);
                break;
            case 5:
            	char operacion;
                cout<<"Ingrese operacion para ver el ultimo DNI (D para Depositos, E para Extracciones, O para Varios): ";
                cin>>operacion;
                operacion = toupper(operacion);
                
                switch (operacion){ // Muestra el ultimo DNI en la fila que corresponda
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
