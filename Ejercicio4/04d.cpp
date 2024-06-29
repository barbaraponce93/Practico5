/*
d. Además de la Fila A cree la fila B, vacíe la fila A y cargue A y B con elementos ordenados, realice un algoritmo que inserte 
los elementos de la fila A y B en otra fila C de manera tal que queden ordenados.
*/

#include <iostream>
using namespace std;

const int MAX=10;

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
	
	void mostrarArreglo(){
		for(int i=0;i<MAX;i++){
			cout<<fila[i]<<endl;
		}
	}	
};

int main(){
	
	Fila filaA("Fila A"), filaB("Fila B"), filaC("Fila C");
		
	cout<<"---- Se carga elementos a la Fila A---"<<endl;	
	for(int i=0;i<5;i++){	
		filaA.Enfilar(i+1);
	}
	
	cout<<"\n---- Se carga elementos a la Fila B---"<<endl;	
	for(int i=0;i<5;i++){	
		filaB.Enfilar(i+6);
	}
	
	cout<<"\n---- Se pasa los elementos de la Fila A a la Fila C---"<<endl;	
	for(int i=0;i<5;i++){	
		filaC.Enfilar(filaA.verPrimero());
		filaA.Desenfilar();
	}
	
	cout<<"\n---- Se pasa los elementos de la Fila B a la Fila C---"<<endl;	
	for(int i=0;i<5;i++){	
		filaC.Enfilar(filaB.verPrimero());
		filaB.Desenfilar();
	}
	
	return 0;
}

