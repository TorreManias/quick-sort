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
#include <stdio.h>

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
	// TODO: Esta funci�n deber�a regresar el �ndice del elemento pivot en su lugar correcto
	int pivote = arr[r];

	// �ndices para recorrer el arreglo
	int i = l - 1;
	for (int j = l; j <= (r - 1); j++) {
		if (arr[j] < pivote) {
			// Intercambiar los n�meros
			i++;
			intercambiar(&arr[i], &arr[j]);
		}
	}
	intercambiar(&arr[i + 1], &arr[r]);
	return i + 1;
}

void qSort(int arr[], int l, int r) {
	// Funci�n recursiva del QuickSort
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

	clock_t inicio, fin, total;

	setlocale(LC_ALL, "spanish");

	switch(argc){
		case 2: {

			//if (isdigit(atoi(argv[1]))) {
				int TAM = atoi(argv[1]);
				cout << "Tama�o del arreglo: " << TAM << endl;

				
				int numeros[TAM] = {0};
				generarNumerosAleatorios(numeros, TAM);

				imprimirArr(numeros, TAM);

				inicio = clock();
				qSort(numeros, 0, TAM - 1);
				fin = clock();
				imprimirArr(numeros, TAM);
				total = (double)((fin - inicio) / CLOCKS_PER_SEC);
				printf("\nTiempo total de ordenamiento de %d n�meros: %f\n", TAM, total);

			/*} else {
				cout << "Argumento inv�lido" << endl;
			} */

		}

			break;

		default:
			cout << endl << "N�mero inv�lido de argumentos. Intente de nuevo con el siguiente formato:" << endl;
			cout << "\t" << "a.exe [cantidad_aleatorios_generar]" << endl;
			break;
	}

	system("pause");
	return 0;
}
