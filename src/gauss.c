#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * Zwraca 0 - eliminacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
	/* Liczba wierszy i kolumn macierzy */
	int rows = mat->r;
	int cols = mat->c;

	for (int k = 0; k < rows && k < cols; ++k) {
		/* Znalezienie wiersza z najwiekszym elementem w kolumnie k (pivoting) */
		int max_row = k;
		for (int i = k + 1; i < rows; ++i) {
			if (fabs(mat->data[i][k]) > fabs(mat->data[max_row][k])) {
				max_row = i;
			}
		}

		/* Zamiana wierszy (pivot) */
		if (max_row != k) {
			double *temp_row = mat->data[k];
			mat->data[k] = mat->data[max_row];
			mat->data[max_row] = temp_row;

			/* Zamiana odpowiednich wartosci w wektorze b */
			double temp_b = b->data[k][0];
			b->data[k][0] = b->data[max_row][0];
			b->data[max_row][0] = temp_b;
		}

		/* Sprawdzenie, czy element diagonalny jest rowny 0 */
		if (mat->data[k][k] == 0.0) {
			fprintf(stderr, "Macierz osobliwa: dzielenie przez zero w wierszu %d.\n", k);
			return 1;
		}

		/* Eliminacja wierszy ponizej wiersza k */
		for (int i = k + 1; i < rows; ++i) {
			double factor = mat->data[i][k] / mat->data[k][k];

			/* Aktualizacja macierzy A */
			for (int j = k; j < cols; ++j) {
				mat->data[i][j] -= factor * mat->data[k][j];
			}

			/* Aktualizacja wektora b */
			b->data[i][0] -= factor * b->data[k][0];
		}
	}

	return 0;
}
