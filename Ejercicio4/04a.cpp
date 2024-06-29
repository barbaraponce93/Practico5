/*
a. Dada una fila A, Invertirla. Mostrar ambas filas. (usar fila auxiliar si lo necesita)
*/
#include<locale.h>
#include <iostream>
using namespace std;

const int MAX=5;
struct Fila{
  private: 
	int fila[MAX];  // struct de enteros
    int p=0;
    int u=-1;
    int cant=0;
    
  public:
	bool filaVacia (){  //EMPTY
		return cant==0;
	}
	bool filaLlena (){   //FULL
		return cant==MAX;
	}
	void Enfilar(int elem){  //ENQUEUE
		if (!filaLlena()){
		  u = (u+1)%MAX;
		  fila[u]=elem;
		  cant++;
		}else 
			cout<<"No se puede enfilar"<<endl;
	}
	void Desenfilar(){   //DEQUEUE
		if (!filaVacia()){
	     	p=(p+1)%MAX;
		    cant--;
		}else	
			cout<<"No se puede eliminar";
	}
	int verPrimero (){   // FRONT
		return fila[p];
	}
	int verUltimo (){    // BACK
		return fila[u];
	}  
	int getCantidad(){ 
	    return cant;
	}
};

void mostrarFila(Fila fila){
	int i=1;
	while(!fila.filaVacia()){
		cout<<i<<"° -> "<<fila.verPrimero()<<endl;
		fila.Desenfilar();
		i++;
	}
}

void vaciarFila(Fila &fila){
	while(!fila.filaVacia()){
		fila.Desenfilar();
	}
	
}

void invertirFila(Fila& filaA){
	
	Fila filaB; // Fila auxiliar para almacenar los elementos en orden invertido
	
	int cantidad = filaA.getCantidad();
	
	cout<<"Fila A"<<endl;
	
	mostrarFila(filaA);
	
	for(int k=0;k<cantidad;k++){  // Invierte los elementos de la filaA en la filaB
		for(int i=0;i<cantidad-1;i++){
			int elem = filaA.verPrimero();
			filaA.Desenfilar(); // Desenfila el primer elemento de la fila A
			filaA.Enfilar(elem); // Enfila el elemento defenfilado, al final de la fila A
			
			 // Este proceso desplaza el primer elemento al final de la fila A,
        	// lo que permite que el siguiente elemento en la fila A se convierta 
			// en el nuevo primer elemento, rotando asi todos los elementos menos el ultimo.			
		}
		filaB.Enfilar(filaA.verPrimero());
		// Despues de rotar los elementos, el ultimo elemento de la fila rotada es el que
    	// queda como primer elemento, el cual sera enfilado en la fila B
	}
	
	vaciarFila(filaA);
	
	for(int i=0;i<cantidad;i++){  // Transfiere los elementos invertidos de fila B a fila A
		filaA.Enfilar(filaB.verPrimero());
		filaB.Desenfilar();
	}
	
	cout<<"\nFila A invertida"<<endl;
	
	mostrarFila(filaA);
}

int main(){
	
	setlocale(LC_ALL,"Spanish");
	
	Fila filaA;
		
	for(int i=0;i<5;i++){	
		filaA.Enfilar(i+1);
	}
	
	invertirFila(filaA);
	
	return 0;
}
