#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Zwraca 0 - eliminacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
	int rows = mat->r; /* Liczba wierszy macierzy */
	int cols = mat->c; /* Liczba kolumn macierzy */

	for (int k = 0; k < rows && k < cols; ++k) {
		/* Sprawdzenie, czy element diagonalny jest rowny 0 */
		if (mat->data[k][k] == 0.0) {
			fprintf(stderr, "Macierz osobliwa lub brak mozliwosci eliminacji w wierszu %d.\n", k);
			return 1; /* Macierz osobliwa */
		}

		/* Eliminacja wierszy ponizej wiersza k */
		for (int i = k + 1; i < rows; ++i) {
			double factor = mat->data[i][k] / mat->data[k][k];

			/* Aktualizacja macierzy A */
			for (int j = k; j < cols; ++j) {
				mat->data[i][j] -= factor * mat->data[k][j];
			}

			/* Aktualizacja wektora b, jesli liczba kolumn w b to 1 */
			if (b->c == 1) {
				b->data[i][0] -= factor * b->data[k][0];
			}
		}
	}

	/* Sprawdzenie ostatnich elementow diagonalnych */
	for (int k = 0; k < rows && k < cols; ++k) {
		if (mat->data[k][k] == 0.0) {
			fprintf(stderr, "Macierz osobliwa: dzielenie przez zero w wierszu %d.\n", k);
			return 1; /* Macierz osobliwa */
		}
	}

	return 0; /* Eliminacja zakonczonaa sukcesem */
}
