#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "func-lib.h"

int main(int argc, char* argv[]) {
	if(argc != 2) {
		fprintf(stderr, "Invalid input. Run program as it follows:\n");
		fprintf(stderr, "<program name> <number of terms>\n");
		return 1;
	}

	int num_terms = atoi(argv[1]);

	double euler = 0;
	euler_approx(&euler, num_terms);

	printf("Euler\'s number value approximation: %f\n", euler);

	return 0;
}
