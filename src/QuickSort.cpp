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
#define ulli unsigned long long int

using namespace std;

void imprimirArr(ulli arr[], int TAM){
	for (int i = 0; i < TAM; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void intercambiar(ulli *a, ulli *b) {
	ulli temp = *a;
	*a = *b;
	*b = temp;
}

int particionar(ulli arr[], int l, int r) {
	ulli pivote = arr[r];

	int i = l - 1;
	for (int j = l; j <= (r - 1); j++) {
		if (arr[j] < pivote) {
			i++;
			intercambiar(&arr[i], &arr[j]);
		}
	}
	intercambiar(&arr[i + 1], &arr[r]);
	return i + 1;
}

void qSort(ulli arr[], int l, int r) {
	if (l < r) {
		int indexPivote = particionar(arr, l, r);

		// Ordenar a la izquierda del pivote
		qSort(arr, l, indexPivote - 1);
		// Ordenar a la derecha del pivote
		qSort(arr, indexPivote + 1, r);
	}
}

void generarNumerosAleatorios(ulli *arr, int TAM) {
	srand(time(NULL));
	// Cargar el arreglo con numeros aleatorios
	for(int i = 0; i < TAM; i++) {
		arr[i] = 1 + rand() % TAM;
	}
}

int main(int argc, char *argv[]) {

	float inicio, fin, total;

	setlocale(LC_ALL, "spanish");

	switch(argc){
		case 2: {
				int TAM = atoi(argv[1]);
				cout << "Size del arreglo: " << TAM << endl;

				
				ulli* numeros = new ulli[TAM];
				generarNumerosAleatorios(numeros, TAM);

				//imprimirArr(numeros, TAM);

				inicio = clock();
				qSort(numeros, 0, TAM - 1);
				fin = clock();

				free(numeros);

				//imprimirArr(numeros, TAM);

				total = (double)(fin - inicio) / CLOCKS_PER_SEC;

				printf("\nTiempo total de ordenamiento de %d números: %f\n", TAM, total);
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