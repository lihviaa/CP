#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylib.h"

void srl_mat_array(int **matrix, int *array, int *srl_result, int lines, int columns);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Usage: <program> <lines> <columns>\n");
        return 1;
    }

    int lines = atoi(argv[1]);
    int columns = atoi(argv[2]);

    int *array = rnd_array_alloc(columns, 100);
    int **matrix = rnd_matrix_alloc(lines, columns, 100);
    int *srl_result_array = (int*) malloc(lines * sizeof(int));

    srl_mat_array(matrix, array, srl_result_array, lines, columns);

    printf("Serial execution done\n");

    for(int i = 0; i < lines; i++) free(matrix[i]);
    free(matrix);
    free(array);
    free(srl_result_array);

    return 0;
}

void srl_mat_array(int **matrix, int *array, int *srl_result, int lines, int columns) {
    for(int i = 0; i < lines; i++) {
        srl_result[i] = 0;
        for(int j = 0; j < columns; j++) {
            srl_result[i] += matrix[i][j] * array[j];
        }
    }
}

