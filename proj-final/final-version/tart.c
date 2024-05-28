#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <mpfr.h>
#include <gmp.h>



// Função para calcular os fatoriais até n
void fatorial(int n, mpfr_t* vet, int nBits) {
    // Inicializa o vetor com o fatorial de 0! e 1!
    mpfr_init2(vet[0], nBits);
    mpfr_set_d(vet[0], 1.0, MPFR_RNDU);
    mpfr_init2(vet[1], nBits);
    mpfr_set_d(vet[1], 1.0, MPFR_RNDU);

    // Calcula os fatoriais subsequentes
    for (long int i = 2; i < n; ++i) {
        mpfr_init2(vet[i], nBits);
        mpfr_mul_si(vet[i], vet[i-1], i, MPFR_RNDU);

    }
}


// Função para somar os termos da série utilizando OpenMP

void soma(int n, mpfr_t* vet, int nBits, mpfr_t* globalPointer) {
    int thread_id = omp_get_thread_num();
    int n_threads = omp_get_num_threads();
    int chunk_size = n / n_threads;
    int start = chunk_size * thread_id;
    int end = (thread_id == n_threads - 1) ? n - 1 : start + chunk_size - 1;

    mpfr_t local_sum, reciprocal, one;

    // Inicializa variáveis locais

    mpfr_init2(local_sum, nBits);
    mpfr_set_d(local_sum, 0.0, MPFR_RNDU);

    mpfr_init2(reciprocal, nBits);
    mpfr_init2(one, nBits);
    mpfr_set_d(one, 1.0, MPFR_RNDU);

    // Calcula a soma parcial da série para cada thread
    for (int i = start; i <= end; i++) {
        mpfr_div(reciprocal, one, vet[i], MPFR_RNDU);
        mpfr_add(local_sum, local_sum, reciprocal, MPFR_RNDU);
    }



    // Seção crítica para atualizar a soma global
    #pragma omp critical
    {
        mpfr_add(*globalPointer, *globalPointer, local_sum, MPFR_RNDU);
    }

    // Limpa as variáveis locais
    mpfr_clear(local_sum);
    mpfr_clear(reciprocal);
    mpfr_clear(one);
}



int main(int argc, char* argv[]) {

    if (argc != 4) {
        printf("\nArgumentos Inválidos. Insira: <número_de_threads> <iterações> <precisão(bits)>\n");
        return 1;

    }



    int nThreads = strtol(argv[1], NULL, 10);
    int n = strtol(argv[2], NULL, 10);
    int nBits = strtol(argv[3], NULL, 10);



    mpfr_t global;
    mpfr_init2(global, nBits);
    mpfr_set_d(global, 0.0, MPFR_RNDU);



    mpfr_t* vet = (mpfr_t*) malloc(n * sizeof(mpfr_t));
    fatorial(n, vet, nBits);

    // Cria as threads e chama a função soma
    #pragma omp parallel num_threads(nThreads)
    {
        soma(n, vet, nBits, &global);
    }



    // Exibe o resultado final
    printf("Resultado da aproximação de Euler: ");
    mpfr_out_str(stdout, 10, 0, global, MPFR_RNDU);
    printf("\n");



    // Limpa a memória alocada

    mpfr_clear(global);
    for (int i = 0; i < n; i++) {
        mpfr_clear(vet[i]);

    }
    free(vet);
    return 0;
}
