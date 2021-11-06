//============================================================================
// Name        : QuickSort.cpp
// Author      : Marlie Ramirez, Marcos Lanuza y Luis Orozco
// Description : Algoritmo de ordenamiento - QuickSort
//============================================================================

#include <iostream>
#define TAM 10
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

void imprimirArr(int arr[]){
	for (size_t i = 0; i < TAM; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int main() {
	int desordenado[TAM] = {5, 10, 0, 9, 4, 1, 20, 13, 7, 6};

	cout << "Arreglo desordenado: ";
	imprimirArr(desordenado);

	return 0;
}
