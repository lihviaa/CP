int factorial(int num) {
	if(num == 0) { return 1; }
	return num * factorial(num - 1);
}

void euler_approx(double* euler_num, int n_terms) {
	double numerator = 1;

	for(int i = 0; i < n_terms; i++) {
		*euler_num += numerator/(factorial(i));
	}
}
