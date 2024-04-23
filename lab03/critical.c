#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "traprule.h"

int main(int argc, char* argv[]) {
	if(argc != 5) { // Validating input 
		fprintf(stderr, "Invalid. Please, execute program as following:\n");
		fprintf(stderr, "<program> <left> <right> <n traps> <n threads>\n");
		return 1;
	}
	
	double global_summ = 0.0; // Summation of all areas

	// Getting arguments from command line
	double left = strtod(argv[1], NULL);
	double right = strtod(argv[2], NULL);
	int n_traps = strtol(argv[3], NULL, 10);
	int n_threads = strtol(argv[4], NULL, 10);

	// Making it all parallel by using OpenMP
	#pragma omp parallel num_threads(n_threads)
	{
		double current_summ = 0.0; // Stores areas calculated by each thread
		current_summ += trap_summ(left, right, n_traps);
		
		#pragma omp critical
		// Adding critical zone in order to respect correctness
		global_summ += current_summ; // Sums it altogether
	}

	// Result showed in scientific notation
	printf("\nValor estimado: %.14e\n", global_summ);

	return 0;
}
