#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

/* Funkcja wykonuje podstawianie wsteczne */
/* Zakłada, że macierz "mat" jest górnotrójkątna */
/* Rozwiązuje układ równań Ax = b */
int backsubst(Matrix *x, Matrix *a, Matrix *b) {
    int rows = a->r; // Liczba wierszy macierzy


    // Algorytm podstawiania wstecznego
    for (int i = rows - 1; i >= 0; --i) {
        double sum = 0.0;

        for (int j = i + 1; j < a->c; ++j) {
            sum += a->data[i][j] * x->data[j][0];
        }

        if (a->data[i][i] == 0.0) {
            fprintf(stderr, "Macierz osobliwa - dzielenie przez zero.\n");
            return 1;
        }

        x->data[i][0] = (b->data[i][0] - sum) / a->data[i][i];
    }

    return 0; // Sukces
}

