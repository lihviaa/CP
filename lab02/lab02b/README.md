<h1>Lab02b - Análise de Desempenho Paralelo na Multiplicação de Matriz-Vetor </h1>
<p>Iniciado em 13/03/2024. Concluído em xx/03/2024.</p>

<h2>Sobre a atividade desenvolvida no laboratório</h2>
<p>No Lab02a, os integrantes construíram uma solução para multiplicação matriz-vetor utilizando threads e, adicionalmente, realizaram um <i>benchmarking</i> comparando as execuções serial e paralela do algoritmo desenvolvido para diferentes números de núcleos (1, 2, 4, 6 e 8).</p>

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

<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/execu%C3%A7%C3%A3olab02b_par.jpeg" alt="Execução Paralela" />
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/execu%C3%A7%C3%A3olab02b_srl1.jpeg" alt="Execução Serial 1" />
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/execu%C3%A7%C3%A3olab02b_srl2.jpeg" alt="Execução Serial 2" />

<p>Para compilar o código-fonte desenvolvido, executou-se, <b>em um terminal <i>Linux</i> com compilador <code>gcc</code></b>, a seguinte linha de comando:</p>

<p><code>gcc [Arquivo].c -o [Arquivo].out -lpthread</code></p>

<p>Para executar o arquivo gerado a partir da compilação do código-fonte descrita acima, executa-se a seguinte linha de comando:</p>
<p><code>time taskset -c [Núcleos] ./[Arquivo].out &ltlines&gt &ltcolumns&gt "-p" </code></p>

<p>Substitua <code>[Arquivo]</code> pelo nome do arquivo executável gerado. Por exemplo, <code>lab02b_par.out</code> para execução paralela ou <code>lab02_srl.out</code> para execução serial.</p>

<ul>
    <li><code>time</code>: Mede o tempo de execução do programa.</li>
    <li><code>taskset -c [Núcleos]</code>: Especifica os núcleos de CPU a serem utilizados na execução do programa. Substitua <code>[Núcleos]</code> pelos núcleos desejados.</li>
</ul>

<h3>Argumentos</h3>
<ul>
 <li><code>&ltlines&gt</code>: <strong>OBRIGATÓRIO</strong>. Define o <strong>número de linhas da matriz aleatória a ser gerada</strong>;</li>
 <li><code>&ltcolumns&gt</code>: <strong>OBRIGATÓRIO</strong>. Define o <strong>número de colunas da matriz aleatória a ser gerada</strong>;</li>
 <li><code>"-p"</code>: <strong>Opcional</strong>. Exibe no terminal os vetores e matrizes gerados. Por padrão, a saída sempre é gerada em arquivos <code>.txt</code>;</li>
</ul>


<h3>Exemplos de execução</h3>
<ul>
 <li><code>time taskset -c 0 ./lab02b_(par/srl).out 10 10</code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos em somente um núcleo, gerando um vetor de 10 elementos</strong>. O tempo de execução para um núcleo <strong>será exibido no terminal</strong>.</li>

 <li><code>time taskset -c 0, 1, 2, 3, 4, 5, 6, 7 ./lab02b_(par/srl).out 10 10</code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos em oito núcleos, gerando um vetor de 10 elementos</strong>. O tempo de execução para oito núcleos <strong>será exibido no terminal</strong>.</li>

 <li><code>time taskset -c 0, 1, 2, 3, 4, 5, 6, 7 ./lab02b_(par/srl).out 10 10 "-p" </code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos em oito núcleos, gerando um vetor de 10 elementos</strong>. O tempo de execução <strong>será exibido no terminal</strong> junto com a matriz e os vetores.</li>
</ul>
<p>Para informações mais detalhadas a respeito, leia as seções <b>Compilação</b> e <b>Execução</b> no <a href="https://github.com/lihviaa/parallel-comp/blob/main/README.md">documento descritivo do repositório</a>.</p>
<p>Caso necessário, encontre mais exemplos de execução no diretório de <a href="https://github.com/lihviaa/parallel-comp/tree/main/lab02/lab02a/logs"><code>logs</code></a>.</p>


<h2>Questões</h2>

<ins><h3>1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução</h3></ins>

<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_grafico2.png" alt="Núcleos x Tempo" />
<table align= "center">
     <tr>
          <td><strong>Processadores</td>
          <td><strong>1</td>
          <td><strong>2</td>
          <td><strong>4</td>
          <td><strong>6</td>
          <td><strong>8</td>
     </tr>
     <tr>
           <td><strong>Tempo de Execução Serial</td>
           <td>0,010s</td>
           <td>0,011s</td>
           <td>0,011s</td>
           <td>0,011s</td>
           <td>0,010s</td>
     </tr>
     <tr>
           <td><strong>Tempo de Execução Paralela</strong></td>
           <td>0,025s</td>
           <td>0.022s</td>
           <td>0.016s</td>
           <td>0.015s</td>
           <td>0.016s</td>
     </tr>
</table>


<ins><h3>2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.</h3></ins>

<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_grafico1.png" alt="Speedup x Núcleos" />

<table align= "center">
  <tr>
          <td><strong>Processadores</td>
          <td><strong>1</td>
          <td><strong>2</td>
          <td><strong>4</td>
          <td><strong>6</td>
          <td><strong>8</td>
     </tr>
  <tr>
           <td><strong>Speedup</strong></td>
           <td>0,4</td>
           <td>0,5</td>
           <td>0,6875</td>
           <td>0,733...</td>
           <td>0,625</td>
     </tr>
</table>
           
<ins><h3>3. Como você acha que poderia melhorar o seu algoritmo para obter maior benefício com o paralelismo? Para provar seu ponto, refaça a solução com essa abordagem e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.</h3></ins>



<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_0_1Cores_1Threads.jpeg" alt="0_1Cores_1Threads" />
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_5_1Cores_1Threads.jpeg" alt="5_1Cores_1Threads" />
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_01_2Cores_2Threads.jpeg" alt="01_2Cores_2Threads" />
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_4567_4Cores_2Threads.jpeg" alt="4567_4Cores_2Threads" />
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_4567_4Cores_4Threads.jpeg" alt="4567_4Cores_4Threads" />
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_01234567_8Cores_8Threads.jpeg" alt="01234567_8Cores_8Threads" />
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_01234567_8Cores_4Threads.jpeg" alt="01234567_8Cores_4Threads" />


