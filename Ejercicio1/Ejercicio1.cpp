#include <iostream>
#include <string>

using namespace std;

const int maximo = 100;

struck Stack{
string bolitas[maximo]
int top;
Stack(){
	top = -1;
}
bool bolasVacias(){
	return top == -1;
}
bool bolasLlenas(){
	return top == maximo - 1;
}
void push(const string& bolitas){
	if(!bolasLlenas()){
		bolitas[++top] = bolitas;
	}else{
		cout << "Re lleno de bolitas" << endl
	}
}
string getTop(){
	if(!bolasVacias()){
		return bolitas[top];
	}else{
		return"";
	}
}};

void cargarTubo(Stack& tubo1, Stack& tubo2){
	while(!tubo1.bolasVacias()) {
		tubo2.push(tubo1.getTop());
		tubo1.pop();
	}
}

bool hayColor(Stack& tubo1, const string& color){
	
}
int main(int argc, char** argv) {
	return 0;
}
