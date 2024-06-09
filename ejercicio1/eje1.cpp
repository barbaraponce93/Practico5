/*1. En el menú principal, se cuenta con las siguientes pilas: Tubo1, Tubo2, Tubo3.
a. cargaTubo, que permita introducir datos en el cada uno de los tubos
b. pasarPelota, pasa todos los elementos de Tubo1 a Tubo2
c. hayColor, que recibe un color “rojo” y determina si está en la Tubo1, todos los
elementos deben quedar nuevamente en Tubo1
d. colorear, que tome pelotitas en Tubo1 y las coloca en Tubo2 solo rojas, y en Tubo3 las demás.*/
#include <iostream>
#include<locale.h>
using namespace std;
const int N=4;


	struct Pelota{
		string color;
		
	};
	struct Tubo{
		  private: 
	    int tope= -1;// igual a un valor invalido...cual?
	   Pelota  pelotitas[N]; // modelar la pila con un arreglo
		public:
	
	 Pelota verTope(){
			 return pelotitas[tope]; 
			  
		}	
	void push(Pelota elemento){
			if(tope<N - 1){
				tope++;// 1- subir el tope
				pelotitas[tope]=elemento;// 2- push del elemento en el lugar libre
			
			//	cout << "Push del elemento " << elemento << " en la posicion " << tope << endl;
			}else{
				cout<<"La pila esta llenissima!"<<endl;	
			}
		}
	    
		void pop(){
			if(!pilaVacia()){
			//	  cout<<"Elemento removido: "<<pelotitas[tope]<<endl;
				tope--;	// bajamos el tope (apunta al ultimo accesible)	
				 
			}
			else{
				cout<<"La pila se encuentra vacia"<<endl;
			}
		
		}
		
		bool pilaVacia(){	
			bool estado=false;  // no vacia
			if(tope==-1){ // el tope es invalido?
			estado=true;    
		}		
			return estado;	// devolver que esta vacia
		}
		bool pilaLlena(){	
			bool estado=false; // no llena
			if( tope==N   ){
			 estado=true;  // el tope llego al tamaño?
			}	
			return estado;	// devolver que esta llena
		
	//	int getTope(){ } // devolveria el tope de la pila 
	};
	
	
	
	void mensajeEstadoPila(){
		if(pilaVacia()){
			cout<<"La pila esta vacía"<<endl;
		}else{
			string color = verTope().color;
			cout<<"El último elemento de la pila es "<< color <<endl;
		}
	}
			
			

};
	
	
int	main(){
	Tubo Tubo1, Tubo2, Tubo3;
	
	
	return 0;
}
