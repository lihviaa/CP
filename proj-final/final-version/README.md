# Aproximação de Euler com OpenMP e MPFR

Este projeto calcula a aproximação do número de Euler usando a série de Taylor e paralelização com OpenMP. O código utiliza a biblioteca MPFR para realizar cálculos de alta precisão.

## Conteúdo

O código está dividido em várias partes principais:

1. **Cálculo dos Fatoriais**: Uma função para calcular os fatoriais até um determinado limite.
2. **Soma dos Termos da Série**: Uma função que usa OpenMP para calcular a soma dos termos da série de Taylor em paralelo.
3. **Função Principal**: A função `main` que configura as variáveis, inicializa as threads e exibe o resultado final.

## Como Funciona

### Cálculo dos Fatoriais

A função `calcular_fatorial` inicializa um vetor para armazenar os fatoriais de 0 a n. Os fatoriais são calculados iterativamente e armazenados no vetor para uso posterior na soma dos termos da série.

### Soma dos Termos da Série

A função `calcular_soma` é executada por várias threads em paralelo. Cada thread calcula uma parte da soma dos termos da série de Taylor usando o OpenMP. A soma parcial de cada thread é então combinada em uma seção crítica para obter o resultado final.

### Função Principal

1. **Leitura dos Argumentos**: A função `main` lê o número de threads, o número de iterações e a precisão em bits a partir dos argumentos da linha de comando.
2. **Inicialização**: Inicializa as variáveis necessárias, incluindo o vetor de fatoriais e a soma global.
3. **Cálculo Paralelo**: Cria as threads e chama a função `calcular_soma`.
4. **Exibição do Resultado**: Exibe o resultado da aproximação de Euler.
5. **Limpeza da Memória**: Limpa a memória alocada para evitar vazamentos.

## Cálculo

O cálculo é baseado na série de Taylor para a exponencial:

![image](https://github.com/lihviaa/parallel-comp/assets/139653746/2cbf277e-9dea-48cf-aff6-ef66ea382edc)

Cada termo da série é calculado como o inverso do fatorial e somado usando a precisão especificada.

## Compilação

Para compilar o código, você precisa ter o GCC e as bibliotecas MPFR e GMP instaladas. Use o seguinte comando:

`sudo apt-get install libmpfr-dev`

compilar:

```bash
gcc -o proj-final  proj-final.c -lmpfr -lgmp -fopenmp
```
## Execução
Para executar o programa, use o comando abaixo. Substitua <numero_de_threads> < iteracoes > e <precisao_bits> pelos valores desejados:

./proj-final <numero_de_threads> < iteracoes > <precisao_bits>
![Screenshot from 2024-05-28 16-12-54](https://github.com/lihviaa/parallel-comp/assets/139653746/a3aa9ab6-9317-4ff9-ac7e-053ff5417030)


## Resultados
O programa foi capaz de calcular em 3 minutos e 27 segundos com precisão 421.444 dígitos de Euler. (O número se encontra em `resultado`)
