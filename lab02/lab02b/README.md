<h1>Lab02b - Análise de Desempenho Paralelo na Multiplicação de Matriz-Vetor </h1>
<p>Iniciado em 13/03/2024. Concluído em xx/03/2024.</p>

<h2>Sobre a atividade desenvolvida no laboratório</h2>
<p>No Lab02a, os integrantes construíram uma solução para multiplicação matriz-vetor utilizando threads e, adicionalmente, realizaram um <i>benchmarking</i> comparando as execuções serial e paralela do algoritmo desenvolvido.</p>

<p>Na execução do algoritmo, o usuário define o número de linhas e colunas de uma matriz com elementos aleatórios, os quais serão multiplicados pelos elementos de um vetor (com número de elementos correspondente ao número de colunas da matriz) também formado por números aleatórios e, por fim, terão seu resultado armazenado em um vetor de número de elementos correspondente ao número de linhas da matriz.</p>
<p>Para evitar uma imensurável e desconfortável poluição visual no terminal, a saída do código é dada, por padrão, em arquivos <code>.txt</code>.</p>
<p>Ainda assim, caso deseje visualizar no terminal as matrizes e vetores gerados, <strong>atente-se aos <code>argumentos</code></strong> na seção de <strong><i>Compilação e execução</i></strong></p>

<h2>Índice</h2>
<p>O diretório <code>lab02a</code> está organizado da seguinte forma:</p>
<ul>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02b/README.md"><code>README.md</code></a>: Documento descritivo (você o está lendo agora! 🙂);</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02b/lab02b_srl.c"><code>lab02b_srl.c</code></a>: Código-fonte gerado a partir atividade para multiplicação <code>serial</code>;</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02b/lab02b_par.c"><code>lab02b_par.c</code></a>: Código-fonte gerado a partir atividade para multiplicação <code>paralela</code>;</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02a/arraylib.h"><code>arraylib.h</code></a>: Arquivo <i>header</i> contendo operações envolvendo vetores e matrizes;</li>
</ul>


<h2>Compilação e execução</h2>

<h3>Argumentos</h3>

<h3>Exemplos de execução</h3>

<h2>Questões</h2>

<ins><h3>1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução</h3></ins>

<ins><h3>2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.</h3></ins>

<ins><h3>3. Como você acha que poderia melhorar o seu algoritmo para obter maior benefício com o paralelismo? Para provar seu ponto, refaça a solução com essa abordagem e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.</h3></ins>
