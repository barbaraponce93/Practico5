/*
a. Dada una fila A, Invertirla. Mostrar ambas filas. (usar fila auxiliar si lo necesita)
*/

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
	
	void vaciarFila(){
		p=0;
    	u=-1;
    	cant=0;
	}
	
	void mostrarArreglo(){
		for(int i=0;i<MAX;i++){
			cout<<fila[i]<<endl;
		}
	}	
};

void invertirFila(Fila& filaA){
	
	Fila filaB;
	
	int cantidad = filaA.getCantidad();
	
	cout<<"Fila A"<<endl;
	
	filaA.mostrarArreglo();
	
	for(int k=0;k<cantidad;k++){
		for(int i=0;i<cantidad-1;i++){
			int elem = filaA.verPrimero();
			filaA.Desenfilar();
			filaA.Enfilar(elem);					
		}
		filaB.Enfilar(filaA.verPrimero());	
	}
	
	filaA.vaciarFila();
	
	for(int i=0;i<cantidad;i++){
		filaA.Enfilar(filaB.verPrimero());
		filaB.Desenfilar();
	}
	
	cout<<"\nFila A invertida"<<endl;
	
	filaA.mostrarArreglo();
}

int main(){
	
	Fila filaA;
		
	for(int i=0;i<5;i++){	
		filaA.Enfilar(i+1);
	}
	
	invertirFila(filaA);
	
	return 0;
}
