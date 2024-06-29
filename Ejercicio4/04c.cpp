/*
Ahora queremos buscar si el número entero X determinar está en la Fila A. 
La Fila A deberá quedar en su estado original al finalizar el algoritmo.
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
		  cout<<"\nFila: Se enfila el elemento "<<elem<<" en la posicion "<<u<<endl;
		}else 
			cout<<"\nFila: No se puede enfilar"<<endl;
	}
	void Desenfilar(){   //DEQUEUE
		if (!filaVacia()){
	     	p=(p+1)%MAX;
		    cant--;
		    cout<<"\nFila: Elemento desenfilado"<<endl;
		}else	
			cout<<"\nFila: No se puede eliminar";
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

int main(){
	
	Fila filaA;
	int x;
	bool numeroEncontrado=false;
	
	cout<<"---- Se enfila elementos a la fila A---"<<endl;	
	for(int i=0;i<5;i++){	
		filaA.Enfilar(i+1);
	}
	
	cout<<"\n----- Ingrese el numero entero X: ";
	cin>>x;

	cout<<"\n----- Se desenfila los elementos de la fila A para buscar el numero X---"<<endl;	
	for(int i=0;i<5;i++){
		int primero=filaA.verPrimero();	
		if (primero==x){
			numeroEncontrado=true;
			cout<<"\n----- Se encontro el numero X en la posicion "<<i<<" de la fila A"<<endl;
		}
		filaA.Desenfilar();
		filaA.Enfilar(primero);
	}
	
	if (!numeroEncontrado){
		cout<<"\n----- No se encontro el numero X en la fila A"<<endl;
	}
	
	return 0;
}





