int factof(int nterm) {
    if(nterm == 0) { return 1; }
    return nterm * factof(nterm - 1);
}

void serial_euler_approx(double* euler_num, int nterms) {
    double numerator = 1;

    for(int i = 0; i < nterms; i++) {
        *euler_num += numerator/factof(i);
    }
}