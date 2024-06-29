/*
b. Utilizando las operaciones de pila y de Fila, COPIE el contenido de una pila P, a una Fila C, de tal manera 
que el primer elemento de la Fila será el elemento “F” que se encuentra en el fondo de la pila, el segundo de 
la Fila el que está apilado sobre “F”, y así siguiendo. De esta forma el elemento del tope de la pila quedará en el último lugar de la Fila. 
(Para resolver este ejercicio, use pila auxiliar)
*/

#include <iostream>
using namespace std;

const int MAX=6; // colcar un tamaño de Fila

const int N=6; // colcar un tamaño de pila

//PILA
struct Pila{
    //privado          // interfaz private: encapsulamiento
	   private: 
	   	int tope=-1; // igual a un valor invalido...cual?
	    // modelar la pila con un arreglo
	    char arreglo[N];
	//publico  // interfaz publica
		public:
			bool pilaVacia(){	
			// no vacia
			// el tope es invalido?
			// devolver que esta vacia
			return tope==-1;
		}
		bool pilaLlena(){	
			// no llena
			// el tope llego al tamaño?
			// devolver que esta llena
			return tope==N;
		}	
		void push(char elemento){
			if(!pilaLlena()){
				// 1- subir el tope
				tope++;
				// 2- push del elemento en el lugar libre
				arreglo[tope]=elemento;
				cout<<"\nPila: Push del elemento "<<elemento<<" en la posicion "<<tope<<endl;
			}else{
				cout<<"La pila esta llenissima!"<<endl;	
			}
		}
	    int verTope(){
			   //peek o mirar. devoler ese elemento
			   return arreglo[tope];
		}
		void pop(){
			// bajamos el tope (apunta al ultimo accesible)
			if(!pilaVacia()){
			tope--;
			cout<<"\nPila: Elemento removido"<<endl;	
			}else{
				cout<<"La pila esta vacia, no se puede eliminar"<<endl;
			}	  
		}
			
		int getTope(){// devolveria el tope de la pila 
			return tope;
		}
		
		void mostrarArreglo(){
			for(int i=0;i<N;i++){
			cout<<arreglo[i]<<endl;
			}
		} 
};

//FILA
struct Fila{
  private: 
	char fila[MAX];  // struct de enteros
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
	void Enfilar(char elem){  //ENQUEUE
		if (!filaLlena()){
		  u = (u+1)%MAX;
		  fila[u]=elem;
		  cant++;
		  cout<<"\nFila: Se enfila el elemento "<<elem<<" en la posicion "<<u<<endl;
		}else 
			cout<<"No se puede enfilar"<<endl;
	}
	void Desenfilar(){   //DEQUEUE
		if (!filaVacia()){
	     	p=(p+1)%MAX;
		    cant--;
		    cout<<"\nFila: Elemento desenfilado"<<endl;
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


int main(){
	
	Pila pilaP;
	Fila filaC;
	
	cout<<"---Se agrega elementos a la pilaP---"<<endl;	
	pilaP.push('F');
	pilaP.push('E');
	pilaP.push('D');
	pilaP.push('C');
	pilaP.push('B');
	pilaP.push('A');
	
	cout<<"\n----Se pasa los elementos de la pilaP a la filaC----"<<endl;	
	for(int i=0;i<6;i++){
		filaC.Enfilar(pilaP.verTope());
		pilaP.pop();
	}
	
	cout<<"\n----Se devuelve los elementos de la filaC a la pilaP----"<<endl;	
	for(int i=0;i<6;i++){
		pilaP.push(filaC.verPrimero());
		filaC.Desenfilar();
	}
	
	cout<<"\n----Se vuelve a pasar los elementos de la pilaP a la filaC----"<<endl;
	for(int i=0;i<6;i++){
		filaC.Enfilar(pilaP.verTope());
		pilaP.pop();
	}
	
	return 0;
}

