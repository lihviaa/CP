#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *array;
int *result;
int **matrix;
int lines, columns;

void *mult_mat_array(void* thread);
void populate(int* arg_array, int num_elements);
void print_array(int* arg_array, int num_elements);
void print_matrix(int** arg_matrix, int num_lines, int num_columns);

int main(int argc, char *argv[]) {
    long thread_count;
    if(argc != 3) {
        fprintf(stderr, "Please, type number of lines and columns of matrix.\n");
        return 1;
    }

    srand(time(NULL));

    lines = atoi(argv[1]);
    columns = atoi(argv[2]);

    array = malloc(columns * sizeof(int));
    populate(array, columns);
    
    matrix = malloc(lines * sizeof(int*));
    for(int line = 0; line < lines; line++) {
        matrix[line] = malloc(columns * sizeof(int));
        populate(matrix[line], columns);
    }

    result = malloc(lines * sizeof(int));
    pthread_t *threads = malloc(lines * sizeof(pthread_t));

    for(thread_count = 0; thread_count < lines; thread_count++) {
        pthread_create(&threads[thread_count], NULL, mult_mat_array, (void*) thread_count);
    }

    for(thread_count = 0; thread_count < lines; thread_count++) {
        pthread_join(threads[thread_count], NULL);
    }

    print_matrix(matrix, lines, columns);
    printf("\n");
    print_array(array, columns);
    printf("\n");

    print_array(result, lines);
    printf("\n");

    for(int arrays = 0; arrays < lines; arrays++) {
        free(matrix[arrays]);
    }
    free(matrix);
    free(array);
    free(result);
    free(threads);

    return 0;
}

void *mult_mat_array(void* thread) {
    long thrd = (long) thread;
    result[thrd] = 0;

    for(int i = 0; i < columns; i++) {
        result[thrd] += matrix[thrd][i] * array[i];
    }
}

void populate(int* arg_array, int num_elements) {
    for(int i = 0; i < num_elements; i++) {
        arg_array[i] = rand() % 10;
    }
}

void print_array(int* arg_array, int num_elements) {
    printf("{ ");
    for(int i = 0; i < num_elements; i++) {
        printf("%02d", arg_array[i]);

        if(i != num_elements - 1) {
            printf(", ");
        }
    }
    
    printf(" }");
}

void print_matrix(int** arg_matrix, int num_lines, int num_columns) {
    printf("{ ");
    for(int j = 0; j < num_lines; j++) {
        print_array(arg_matrix[j], num_columns);
        
        if(j != num_lines - 1) {
            printf(",\n  ");
        } 
    }

    printf(" }\n");
}

