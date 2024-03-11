#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *result;
int *array;
int **matrix;

void populate(int* arg_array, int num_of_elements) {
    for(int i = 0; i < num_of_elements; i++) {
        arg_array[i] = rand() % 100;
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

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Please, type number of lines and columns of matrix.\n");
        return 1;
    }

    srand(time(NULL));

    int lines = atoi(argv[1]);
    int columns = atoi(argv[2]);

    array = malloc(columns * sizeof(int));
    populate(array, columns);
    
    matrix = malloc(lines * sizeof(int*));
    for(int line = 0; line < lines; line++) {
        matrix[line] = malloc(columns * sizeof(int));
        populate(matrix[line], columns);
    }

    print_matrix(matrix, lines, columns);
    printf("\n");
    print_array(array, columns);
    printf("\n");

    return 0;
}

