//============================================================================
// Name        : QuickSort.cpp
// Author      : Marlie Ramirez, Marcos Lanuza y Luis Orozco
// Description : Algoritmo de ordenamiento - QuickSort
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void qSort(int[], int l, int r) {
	// Funci�n recursiva del QuickSort
	if (l >= r)
		return;
	//TODO: implementar la recursividad de la funci�n
}

void particionar() {
	// TODO: Esta funci�n deber�a regresar el �ndice del elemento pivot en su lugar correcto
}

void imprimirArr(int arr[], int TAM){
	for (int i = 0; i < TAM; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int TAM = atoi(argv[1]);
	cout << TAM << endl;

	// Generar el aregllo con numeros aleatorios
	int numeros[TAM] = {0};
	for(int i = 0; i < TAM; i++) {
		numeros[i] = 1 + rand() % TAM;
	}

	cout << "Arreglo desordenado: ";
	imprimirArr(numeros, TAM);

	return 0;
}
