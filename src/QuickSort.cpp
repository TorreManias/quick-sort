//============================================================================
// Name        : QuickSort.cpp
// Author      : Marlie Ramirez, Marcos Lanuza y Luis Orozco
// Description : Algoritmo de ordenamiento - QuickSort
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

using namespace std;

void imprimirArr(int arr[], int TAM){
	for (int i = 0; i < TAM; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void intercambiar(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int particionar(int arr[], int l, int r) {
	// TODO: Esta funciï¿½n deberï¿½a regresar el ï¿½ndice del elemento pivot en su lugar correcto
	int pivote = arr[r];

	// Índices para recorrer el arreglo
	int i = l - 1;
	for (int j = l; j <= (r - 1); j++) {
		if (arr[j] < pivote) {
			// Intercambiar los números
			i++;
			intercambiar(&arr[i], &arr[j]);
		}
	}
	intercambiar(&arr[i + 1], &arr[r]);
	return i + 1;
}

void qSort(int arr[], int l, int r) {
	// Funciï¿½n recursiva del QuickSort
	if (l < r) {
		int indexPivote = particionar(arr, l, r);

		// Ordenar a la izquierda del pivote
		qSort(arr, l, indexPivote - 1);
		// Ordenar a la derecha del pivote
		qSort(arr, indexPivote + 1, r);
	}
}

void generarNumerosAleatorios(int *arr, int TAM) {
	// Cargar el arreglo con numeros aleatorios
	for(int i = 0; i < TAM; i++) {
		arr[i] = 1 + rand() % TAM;
	}
}

int main(int argc, char *argv[]) {

	setlocale(LC_ALL, "spanish");

	switch(argc){
		case 2: {

			//if (isdigit(atoi(argv[1]))) {
				int TAM = atoi(argv[1]);
				cout << "Tamaño del arreglo: " << TAM << endl;

				int numeros[TAM] = {0};
				generarNumerosAleatorios(numeros, TAM);

				cout << "Arreglo desordenado: ";
				imprimirArr(numeros, TAM);

				cout << "Arreglo ordenado" << endl;
				qSort(numeros, 0, TAM - 1);
				imprimirArr(numeros, TAM);
			/*} else {
				cout << "Argumento inválido" << endl;
			} */

		}

			break;

		default:
			cout << endl << "Número inválido de argumentos. Intente de nuevo con el siguiente formato:" << endl;
			cout << "\t" << "a.exe [cantidad_aleatorios_generar]" << endl;
			break;
	}
	system("pause");
	return 0;
}
