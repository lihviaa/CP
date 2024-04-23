#include <math.h>
#include "sinf.h"

// Every thread calculates the area of its trapezoids. Then, sum it all up.
double trap_summ(double left, double right, int n_traps) {
	int thread_n = omp_get_thread_num(); // Thread ID.
	int n_threads = omp_get_num_threads(); // Total of threads.

	double trap_height = (right - left)/n_traps; // Height (x axis) of trap.
	double current_traps = n_traps/n_threads; // Number of traps per thread.

	// Gets left and right boundaries of trapezoids
	double current_left = left + thread_n * current_traps * trap_height;
	double current_right = current_left + current_traps * trap_height;

	// Essentially (B + b)/2
	double trap_basis = (y_axis(current_left) + y_axis(current_right))/2.0;

	// Add all basis together
	for(int i = 1; i <= current_traps - 1; i++) {
		double x = current_left + i * trap_height;
		trap_basis += y_axis(x);
	}

	// Essentially the area of a trapezoid
	return trap_basis * trap_height;
}
