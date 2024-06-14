/*1. En el menú principal, se cuenta con las siguientes pilas: Tubo1, Tubo2, Tubo3.
a. cargaTubo, que permita introducir datos en el cada uno de los tubos
b. pasarPelota, pasa todos los elementos de Tubo1 a Tubo2
c. hayColor, que recibe un color “rojo” y determina si está en la Tubo1, todos los
elementos deben quedar nuevamente en Tubo1
d. colorear, que tome pelotitas en Tubo1 y las coloca en Tubo2 solo rojas, y en Tubo3 las demás.*/
#include <iostream>
#include<locale.h>
#include <string> 
#include <cctype>
#include <algorithm>

using namespace std;

const int N=4;//CANTIDAD DE PELOTITAS



	struct Tubo{
		  private: 
	    int tope= -1;
	   string tubito[N]; // modelar la pila con un arreglo
		public:
	
	 string verTope(){
			 return tubito[tope]; 
			  
		}	
	void push(  string elemento){
			if(tope<N - 1){
				tope++;
				tubito[tope]=elemento;
			
				cout<< " \n Push del elemento " << elemento << " en la posicion " << tope << endl;
			}else{
				cout<<"La pila esta llenissima!"<<endl;	
			}
		}
	    
		void pop(){
			if(!pilaVacia()){
				  cout<<" \n Elemento removido: "<<tubito[tope]<<endl;
				tope--;	
				 
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
		
		} 
	
		void mostrarPila(){
			if(tope>-1){
				cout<<"\t[ ";
				for(int i=0;i<=tope;i++){
					cout<<tubito[i]<<" , ";
				}	
				cout<<" último elemento agregado]"<<endl;
			}else{
				cout<<" \t Nada que mostrar,la pila esta vacia"<<endl;
			}
		}

};
	string toUpperCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
//transform:aplica transformaciones a un rango de elementos. ej: convertir letras
// minúsculas a mayúsculas usando una expresión lambda.   
// funcion toupper de la biblio <cctype> convierte solo una letra, para aplicarla deberia
// usar un for para que convierta toda la cadena
    return result;
    
}
	
	void cargaTubo(Tubo& tubo,  string color) {
		  color = toUpperCase(color);
    
  		  tubo.push(color);
    // cargaTubo, que permita introducir datos en el cada uno de los tubos, es decir un push
		}
	
	
	void pasarPelota(Tubo& tuboInicio,Tubo& tuboDestino ){
  		while (!tuboInicio.pilaVacia() && !tuboDestino.pilaLlena()){
		 string elemento = tuboInicio.verTope();
		 tuboInicio.pop();
   		 tuboDestino.push(elemento);
	//pasarPelota, pasa TODOS los elementos de Tubo1 a Tubo2		
		}
	}

	bool hayColor(Tubo& tubo, string color) {
		   color = toUpperCase(color);
	   bool colorEncontrado = false;
    Tubo aux;
    int contador = 0;

 	   while (!tubo.pilaVacia()) {
      	  string elemento = tubo.verTope();
      	  tubo.pop();
      	  aux.push(elemento);
						//voy moviendo los elementos del tubo para comparar sus colores y contar la cantidad por tubo
      	  if (elemento == color) {
            colorEncontrado = true;
            contador++;
        }
   			 }

   		 while (!aux.pilaVacia()) {//devuelvo todo al tubo original
       	 string elemento = aux.verTope();
     	 aux.pop();
      	  tubo.push(elemento);
   		 }

    //c. hayColor,si esta el color buscado retorna true
    //agregue un contador para saber cuantas pelotitas del mismo color habian en el tubo
    
    
      if (colorEncontrado) {
        cout << " \n El color " << color << " está presente en Tubo." << " Se encuentra " << contador << " veces" <<endl;
             
    } else {
        cout << "\n El color " << color << " NO está presente en Tubo." << endl;
    }
    return colorEncontrado;
}

//d. colorear, que tome pelotitas en Tubo1 y las coloca en Tubo2 solo rojas, y en Tubo3 las demás.	

	void colorear(Tubo& tuboInicial, string color, Tubo& tuboDestino,Tubo& tuboUltimo ){
	 	color = toUpperCase(color);
		while (! tuboInicial.pilaVacia()) {
			  	string elemento= tuboInicial.verTope();
			  		tuboInicial.pop();
			  	if(elemento==color){
      	  	
      				tuboDestino.push(elemento);
				}else{
					tuboUltimo.push(elemento);
				}
		}
	}
			


	
	
	
int	main(){
	setlocale(LC_ALL,"Spanish");
	Tubo Tubo1, Tubo2, Tubo3;
	
	cargaTubo(Tubo1, "verde");
    cargaTubo(Tubo1, "rojo");
  	cargaTubo(Tubo1, "azul");
 	cargaTubo(Tubo1, "rojo");
 	
 	
    cout << " \n Contenido de Tubo1: ";
    Tubo1.mostrarPila();

   // cout << "\nPasando elementos de Tubo1 a Tubo2..." << endl;
   // pasarPelota(Tubo1, Tubo2);

  //  cout << "Contenido de Tubo2: ";
  //  Tubo2.mostrarPila();
    
//	cout << " \n Verificando colores en el tubo" << endl;
  // hayColor(Tubo1, "rojo");
  

 //   cout << "\n Contenido de Tubo después de buscar color: ";
 //   Tubo1.mostrarPila();
 
 
 cout<<"\nAplico función colorear"<<endl;
 colorear(Tubo1,"Rojo",Tubo2,Tubo3);
 
 
 cout << "\n Contenido de los tres Tubos después de mover un  color: "<<endl;
 cout<<"Tubo 1";
  Tubo1.mostrarPila();
 cout<<"Tubo 2";
 Tubo2.mostrarPila();
 cout<<"Tubo 3";
 Tubo3.mostrarPila();    
    
	return 0;
}
