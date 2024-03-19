#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylib.h"

void srl_mat_array(int **matrix, int *array, int *srl_result, int lines, int columns);

int main(int argc, char *argv[]) {
    if(argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: <program> <lines> <columns> [-p]\n");
        return 1;
    }

    int lines = atoi(argv[1]);
    int columns = atoi(argv[2]);
    int prnt_flag = (argc == 4 && strcmp("-p", argv[3]) == 0) ? 1 : 0;

    int *array = rnd_array_alloc(columns, 100);
    int **matrix = rnd_matrix_alloc(lines, columns, 100);
    int *srl_result_array = (int*) malloc(lines * sizeof(int));

    srl_mat_array(matrix, array, srl_result_array, lines, columns);

    if(prnt_flag) {

        printf("\nArray generated:\n");
        print_array(array, columns);

        printf("\n\nMatrix generated:\n");
        print_matrix(matrix, lines, columns);

        printf("\nResulting array:\n");
        print_array(srl_result_array, lines);
        printf("\n\n");
    }

    FILE *array_file = fopen("array.txt", "w");
    FILE *matrix_file = fopen("matrix.txt", "w");
    FILE *srl_result_file = fopen("srl_result.txt", "w");

    write_matrix_file(matrix_file, matrix, lines, columns);
    printf("Matrix written to matrix.txt\n");

    write_array_file(array_file, array, columns);
    printf("Array written to array.txt\n");

    write_array_file(srl_result_file, srl_result_array, lines);
    printf("Result written to srl_result.txt\n");

    for(int i = 0; i < lines; i++) free(matrix[i]);
    free(matrix);
    free(array);
    free(srl_result_array);
    fclose(array_file);
    fclose(matrix_file);
    fclose(srl_result_file);

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

