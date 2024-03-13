#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int elements);
int *rnd_array_alloc(int elements, int range);
void rnd_populate(int *array, int elements, int range);
void print_matrix(int** matrix, int lines, int columns);
int **rnd_matrix_alloc(int lines, int columns, int range);
void write_array_file(FILE *fpointer, int *array, int elements);
void write_matrix_file(FILE *fpointer, int **matrix, int lines, int columns);

void rnd_populate(int *array, int elements, int range) {
    for(int i = 0; i < elements; i++) {
        array[i] = rand() % range;
    }
}

int *rnd_array_alloc(int elements, int range) {
    int *array = (int*) malloc(elements * sizeof(int));
    rnd_populate(array, elements, range);
    
    return array;
}

int **rnd_matrix_alloc(int lines, int columns, int range) {
    int **matrix = (int**) malloc(lines * sizeof(int*));
    for(int i = 0; i < lines; i++) {
        matrix[i] = (int*) malloc(columns * sizeof(int));
        rnd_populate(matrix[i], columns, range);
    }
    
    return matrix;
}

void write_array_file(FILE *fpointer, int *array, int elements) {
    fprintf(fpointer, "{ ");
    for(int i = 0; i < elements; i++) {
        fprintf(fpointer, "%02d", array[i]);

        if(i != elements - 1) {
            fprintf(fpointer, ", ");
        }
    }
    
    fprintf(fpointer, " }");
}

void write_matrix_file(FILE *fpointer, int **matrix, int lines, int columns) {
    fprintf(fpointer, "{ ");
    for(int j = 0; j < lines; j++) {
        write_array_file(fpointer, matrix[j], columns);
        
        if(j != lines - 1) {
            fprintf(fpointer, ",\n  ");
        } 
    }

    fprintf(fpointer, " }\n");
}

void print_array(int *array, int elements) {
    printf("{ ");
    for(int i = 0; i < elements; i++) {
        printf("%02d", array[i]);

        if(i != elements - 1) {
            printf(", ");
        }
    }
    
    printf(" }");
}

void print_matrix(int **matrix, int lines, int columns) {
    printf("{ ");
    for(int j = 0; j < lines; j++) {
        print_array(matrix[j], columns);
        
        if(j != lines - 1) {
            printf(",\n  ");
        } 
    }

    printf(" }\n");
}
