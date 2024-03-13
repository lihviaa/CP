#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "arraylib.h"

int *array;
int *result;
int **matrix;
int lines, columns;
int *srl_result_array;

void srl_mat_array(int *srl_array);
void *par_mat_array(void* thread);

int main(int argc, char *argv[]) {
    long thrd_n;
    int bm_flag = 0;
    int prnt_flag = 0; 
    srand(time(NULL));
    char* clpr_f = "-p";
    char* clbm_f = "-bm";
    double prll_tic, prll_toc, srl_tic, srl_toc;
    FILE *prll_result, *prll_array, *prll_matrix, *srl_result_p;

    if(argc < 3 || argc > 5) {
        fprintf(stderr, "Please, check README before running file.\n");
        return 1;
    }

    lines = atoi(argv[1]);
    columns = atoi(argv[2]);

    if(argc > 3) {
        if(!strcmp(clbm_f, argv[3])) bm_flag = 1;
        if(!strcmp(clpr_f, argv[3])) prnt_flag = 1;

        if(argc > 4) {
            if(!strcmp(clbm_f, argv[4])) bm_flag = 1;
            if(!strcmp(clpr_f, argv[4])) prnt_flag = 1;
        }
    }

    array = rnd_array_alloc(columns, 100);
    matrix = rnd_matrix_alloc(lines, columns, 100);
    result = (int*) malloc(lines * sizeof(int));

    pthread_t *threads = malloc(lines * sizeof(pthread_t));

    prll_tic = (double) clock()/CLOCKS_PER_SEC;

    for(thrd_n = 0; thrd_n < lines; thrd_n++) {
        pthread_create(&threads[thrd_n], NULL, par_mat_array, (void*) thrd_n);
    }

    for(thrd_n = 0; thrd_n < lines; thrd_n++) {
        pthread_join(threads[thrd_n], NULL);
    }

    prll_toc = (double) clock()/CLOCKS_PER_SEC;

    printf("\nParallel execution finished.\n");

    if(prnt_flag) {
        printf("\nRandom array generated:\n");
        print_array(array, columns);
        printf("\n\nRandom matrix generated:\n");
        print_matrix(matrix, lines, columns);
        printf("\nResulting array:\n");
        print_array(result, lines);
        printf("\n\n");
    }

    prll_result = fopen("result.txt", "w");
    prll_array = fopen("array.txt", "w");
    prll_matrix = fopen("matrix.txt", "w");

    write_matrix_file(prll_matrix, matrix, lines, columns);
    printf("Matrix written to matrix.txt\n");
    write_array_file(prll_array, array, columns);
    printf("Array written to array.txt\n");
    write_array_file(prll_result, result, lines);
    printf("Result written to result.txt\n");

    if(bm_flag) {
        srl_result_p = fopen("srl_result.txt", "w");
        srl_result_array = (int*) malloc(lines * sizeof(int));
	printf("\n");
        srl_tic = (double) clock()/CLOCKS_PER_SEC;
        srl_mat_array(srl_result_array);
        srl_toc = (double) clock()/CLOCKS_PER_SEC;
        write_array_file(srl_result_p, srl_result_array, lines);
        printf("\nSerial execution result written to srl_result.txt\n");
        printf("\n---------------- BENCHMARK ----------------");
        printf("\nSerial execution time: ~%.9fs", srl_toc - srl_tic);
    }

    printf("\nParallel execution time: ~%.9fs\n", prll_toc - prll_tic);

    for(int m = 0; m < lines; m++) free(matrix[m]);
    free(matrix);
    free(array);
    free(result);
    free(threads);
    fclose(prll_array);
    fclose(prll_result);
    fclose(prll_matrix);
    if(bm_flag) fclose(srl_result_p);

    return 0;
}

void *par_mat_array(void* thread) {
    long thread_id = pthread_self();
    long thrd = (long) thread;
    result[thrd] = 0;

    for(int i = 0; i < columns; i++) {
        result[thrd] += matrix[thrd][i] * array[i];
    }

    printf("Parallel: Result[%ld] calculated by Thread %ld\n", thrd, thread_id);
    return NULL;
}

void srl_mat_array(int* srl_result) {
    for(int i = 0; i < lines; i++) {
        srl_result[i] = 0;
        for(int j = 0; j < columns; j++) {
            srl_result[i] += matrix[i][j] * array[j];
        }

	printf("Serial: Result[%d] calculated\n", i);
    }
}
