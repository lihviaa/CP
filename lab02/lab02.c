#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "arraylib.h"

int *array;
int *result;
int **matrix;
int lines, columns;

void *par_mat_array(void* thread);

int main(int argc, char *argv[]) {
    long thread_num;
    srand(time(NULL));
    FILE *presult, *parray, *pmatrix;

    if(argc != 3) {
        fprintf(stderr, "Please, type number of lines and columns of matrix.\n");
        return 1;
    }

    lines = atoi(argv[1]);
    columns = atoi(argv[2]);

    presult = fopen("result.txt", "w");
    parray = fopen("array.txt", "w");
    pmatrix = fopen("matrix.txt", "w");

    array = rnd_array_alloc(columns, 10);
    matrix = rnd_matrix_alloc(lines, columns, 10);
    result = malloc(lines * sizeof(int));

    pthread_t *threads = malloc(lines * sizeof(pthread_t));

    for(thread_num = 0; thread_num < lines; thread_num++) {
        pthread_create(&threads[thread_num], NULL, par_mat_array, (void*) thread_num);
    }

    for(thread_num = 0; thread_num < lines; thread_num++) {
        pthread_join(threads[thread_num], NULL);
    }

    write_matrix_file(pmatrix, matrix, lines, columns);
    printf("Matrix written to matrix.txt\n");
    write_array_file(parray, array, columns);
    printf("Array written to array.txt\n");
    write_array_file(presult, result, lines);
    printf("Result written to result.txt\n");

    for(int m = 0; m < lines; m++) free(matrix[m]);
    free(matrix);
    free(array);
    free(result);
    free(threads);
    fclose(presult);
    fclose(parray);
    fclose(pmatrix);

    return 0;
}

void *par_mat_array(void* thread) {
    long thread_id = pthread_self();
    long thrd = (long) thread;
    result[thrd] = 0;

    for(int i = 0; i < columns; i++) {
        result[thrd] += matrix[thrd][i] * array[i];
    }

    printf("Elemento de índice %ld calculado pela Thread %ld\n", thrd, thread_id);
    return NULL;
}

