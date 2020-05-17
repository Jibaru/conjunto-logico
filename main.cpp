#include <iostream>
#include <conio.h>
#include "Conjunto.h"

// Notas: Compilar con g++ main.cpp -o main
// Usar versión c++ 11 o superior

using namespace std;

int main(){
		
	Conjunto<string> seccionA = {"Ignacio", "Jose", "Pedro", "Lua", "Ana"};
	Conjunto<string> seccionB = {"Pedro", "Lua", "Jaime", "Kathy"};
	
	Conjunto<string> universo = {"Ignacio", "Jose", "Pedro", "Lua", "Ana", "Jaime", "Kathy", "Erick"};

	Conjunto<string> interseccion = seccionA.intersectar(seccionB);
	Conjunto<string> unido = seccionA.unir(seccionB);
	
	Conjunto<string> seccionAmenosSeccionB = seccionA.diferencia(seccionB);
	Conjunto<string> seccionBmenosSeccionA = seccionB.diferencia(seccionA);
	
	Conjunto<string> difSimetrica = seccionA.diferenciaSimetrica(seccionB);
	
	Conjunto<string> complementoA = seccionA.complemento(universo);
	Conjunto<string> complementoB = seccionB.complemento(universo);
	
	cout << "Universo:  " << universo << endl; 
	cout << "Seccion A: " << seccionA << endl;	
	cout << "Seccion B: " << seccionB << endl;
	
	cout << endl << "==================================================" << endl;

	cout << "Andres pertenece a seccionA: " << seccionA.pertenece("Andres") << endl;
	cout << "Jose pertenece a seccionA: " << seccionA.pertenece("Jose") << endl;

	cout << "SeccionB esta incluido en SeccionA: " << seccionA.incluye(seccionB) << endl;

	cout << endl << "==================================================" << endl;
	
	cout << "Interseccion: " << interseccion << endl;
	cout << "Union:     " << unido << endl;
	cout << "A menos B: " << seccionAmenosSeccionB << endl;
	cout << "B menos A: " << seccionBmenosSeccionA << endl;
	cout << "Dif. Sim.: " << difSimetrica << endl;
	cout << "Complem.A: " << complementoA << endl;
	cout << "Complem.B: " << complementoB << endl;
	
	getch();
	
	return 0;
}

