/*
e. Dada una fila C que contiene elementos repetidos consecutivos. 
Formar otra con los elementos de la fila dada eliminando los repetidos.
*/

#include <iostream>
using namespace std;

const int MAX=5;

struct Fila{
  private:
  	string nombre; 
	int fila[MAX];  // struct de enteros
    int p=0;
    int u=-1;
    int cant=0;
    
  public:
  	
  	Fila(const string &n):nombre(n){}
  	
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
			cout<<"\n"<<nombre<<": Se enfila el elemento "<<elem<<" en la posicion "<<u<<endl;
		}else 
			cout<<"\n"<<nombre<<": No se puede enfilar"<<endl;
	}
	void Desenfilar(){   //DEQUEUE
		if (!filaVacia()){
	     	p=(p+1)%MAX;
		    cant--;
		    cout<<"\n"<<nombre<<": Elemento desenfilado"<<endl;
		}else	
			cout<<"\n"<<nombre<<": No se puede eliminar";
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
	
	bool buscarElemento(int &elem){
		bool elementoEncontrado=false;
		if(!filaVacia()){
			cout<<"\n----- Se desenfila los elementos de la "<<nombre<<" para buscar el elemento "<<elem<<"---"<<endl;
			for(int i=0;i<cant;i++){
				int primero=verPrimero();
				if (primero==elem){
				elementoEncontrado=true;
				cout<<"\n----- Se encontro el elemento "<<elem<<" en la posicion "<<i<<" de la "<<nombre<<"---"<<endl;
				}
				Desenfilar();
				Enfilar(primero);
			}
		}else{
			cout<<"\n---- La fila "<<nombre<<" esta vacia"<<endl;
		}
		return elementoEncontrado;
	}
	void mostrarArreglo(){
		for(int i=0;i<MAX;i++){
			cout<<fila[i]<<endl;
		}
	}
};


int main(){
	
	Fila filaC("Fila C"), filaD("Fila D");
		
	cout<<"---- Se carga elementos a la Fila C---"<<endl;	
	filaC.Enfilar(54);
	filaC.Enfilar(23);
	filaC.Enfilar(42);
	filaC.Enfilar(23);
	filaC.Enfilar(96);
	
	for(int i=0;i<5;i++){
		int primero=filaC.verPrimero();
		if(!filaD.buscarElemento(primero)){
			cout<<"\n---- El elemento "<<primero<<" no esta en la Fila D---"<<endl;
			filaD.Enfilar(primero);
			filaC.Desenfilar();
		}else{
			cout<<"\n---- El elemento "<<primero<<" ya se encuentra en la Fila D---"<<endl;
			filaC.Desenfilar();
		}		
	}
	
	
	return 0;
}
