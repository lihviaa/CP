#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <mpfr.h>
#include <gmp.h>

// Função para calcular os fatoriais até n
void calcular_fatorial(int limite, mpfr_t* vetor_fatorial, int precisao_bits) {
    // Inicializa o vetor com o fatorial de 0! e 1!
    mpfr_init2(vetor_fatorial[0], precisao_bits);
    mpfr_set_d(vetor_fatorial[0], 1.0, MPFR_RNDU);
    mpfr_init2(vetor_fatorial[1], precisao_bits);
    mpfr_set_d(vetor_fatorial[1], 1.0, MPFR_RNDU);

    // Calcula os fatoriais subsequentes
    for (long int i = 2; i < limite; ++i) {
        mpfr_init2(vetor_fatorial[i], precisao_bits);
        mpfr_mul_si(vetor_fatorial[i], vetor_fatorial[i-1], i, MPFR_RNDU);
    }
}

// Função para somar os termos da série utilizando OpenMP
void calcular_soma(int limite, mpfr_t* vetor_fatorial, int precisao_bits, mpfr_t* resultado_global) {
    int id_thread = omp_get_thread_num();
    int num_threads = omp_get_num_threads();
    int tamanho_chunk = limite / num_threads;
    int inicio = tamanho_chunk * id_thread;
    int fim = (id_thread == num_threads - 1) ? limite - 1 : inicio + tamanho_chunk - 1;

    mpfr_t soma_local, reciproco, um;

    // Inicializa variáveis locais
    mpfr_init2(soma_local, precisao_bits);
    mpfr_set_d(soma_local, 0.0, MPFR_RNDU);

    mpfr_init2(reciproco, precisao_bits);
    mpfr_init2(um, precisao_bits);
    mpfr_set_d(um, 1.0, MPFR_RNDU);

    // Calcula a soma parcial da série para cada thread
    for (int i = inicio; i <= fim; i++) {
        mpfr_div(reciproco, um, vetor_fatorial[i], MPFR_RNDU);
        mpfr_add(soma_local, soma_local, reciproco, MPFR_RNDU);
    }

    // Seção crítica para atualizar a soma global
    #pragma omp critical
    {
        mpfr_add(*resultado_global, *resultado_global, soma_local, MPFR_RNDU);
    }

    // Limpa as variáveis locais
    mpfr_clear(soma_local);
    mpfr_clear(reciproco);
    mpfr_clear(um);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("\nArgumentos Inválidos. Insira: <numero_de_threads> <iteracoes> <precisao_bits>\n");
        return 1;
    }

    int num_threads = strtol(argv[1], NULL, 10);
    int iteracoes = strtol(argv[2], NULL, 10);
    int precisao_bits = strtol(argv[3], NULL, 10);

    mpfr_t resultado_global;
    mpfr_init2(resultado_global, precisao_bits);
    mpfr_set_d(resultado_global, 0.0, MPFR_RNDU);

    mpfr_t* vetor_fatorial = (mpfr_t*) malloc(iteracoes * sizeof(mpfr_t));
    calcular_fatorial(iteracoes, vetor_fatorial, precisao_bits);

    // Cria as threads e chama a função calcular_soma
    #pragma omp parallel num_threads(num_threads)
    {
        calcular_soma(iteracoes, vetor_fatorial, precisao_bits, &resultado_global);
    }

    // Exibe o resultado final
    printf("Resultado da aproximacao de Euler: ");
    mpfr_out_str(stdout, 10, 0, resultado_global, MPFR_RNDU);
    printf("\n");

    // Limpa a memória alocada
    mpfr_clear(resultado_global);
    for (int i = 0; i < iteracoes; i++) {
        mpfr_clear(vetor_fatorial[i]);
    }
    free(vetor_fatorial);

    return 0;
}
