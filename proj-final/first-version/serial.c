#include <stdlib.h>
#include <stdio.h>
#include "flib.h"

#define NUM_ARGUMENTS 2

int main(int argc, char* argv[]) {
    if(argc != NUM_ARGUMENTS) {
        fprintf(stderr, "Invalid input. Please, check README.\n");
        return 1;
    }

    double euler_n = 0;
    int num_terms = atoi(argv[NUM_ARGUMENTS - 1]);

    serial_euler_approx(&euler_n, num_terms);

    printf("Euler\'s number approximation: %.15Lf\n", euler_n);

    return 0;
}