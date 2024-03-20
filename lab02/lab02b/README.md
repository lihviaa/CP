<h1>Lab02b - Análise de Desempenho Paralelo na Multiplicação de Matriz-Vetor </h1>
<p>Iniciado em 13/03/2024. Concluído em 20/03/2024.</p>

<h2>Sobre a atividade desenvolvida no laboratório</h2>
<p>No Lab02a, os integrantes construíram uma solução para multiplicação matriz-vetor utilizando threads e, adicionalmente, realizaram um <i>benchmarking</i> comparando as execuções serial e paralela do algoritmo desenvolvido para diferentes números de núcleos (1, 2, 4, 6 e 8).</p>

<p>Na execução do algoritmo, o usuário define o número de linhas e colunas de uma matriz com elementos aleatórios, os quais serão multiplicados pelos elementos de um vetor (com número de elementos correspondente ao número de colunas da matriz) também formado por números aleatórios e, por fim, terão seu resultado armazenado em um vetor de número de elementos correspondente ao número de linhas da matriz.</p>
<p>Diferentemente do laboratório anterior, onde o foco era validar uma implementação de multiplicação matriz-vetor utilizando <i>pthreads</i>, este laboratório está voltado à análise de desempenho das versões desenvolvidas. Sendo assim, optou-se por remover a saída de vetores e matrizes em arquivos .txt, de modo a <strong>priorizar a performance do programa desenvolvido</strong>.</p>

<h2>Índice</h2>
<p>O diretório <code>lab02a</code> está organizado da seguinte forma:</p>
<ul>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02b/README.md"><code>README.md</code></a>: Documento descritivo (você o está lendo agora! 🙂);</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02b/lab02b_srl.c"><code>lab02b_srl.c</code></a>: Código-fonte gerado a partir atividade para multiplicação <code>serial</code>;</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02b/lab02b_par.c"><code>lab02b_par.c</code></a>: Código-fonte gerado a partir atividade para multiplicação <code>paralela</code>;</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02b/lab02b_otm.c"><code>lab02b_par.c</code></a>: Código-fonte gerado a partir atividade para multiplicação <code>paralela<strong>otimizada</strong></code>;</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02a/arraylib.h"><code>arraylib.h</code></a>: Arquivo <i>header</i> contendo operações envolvendo vetores e matrizes;</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/tree/main/lab02/lab02b/core-analysis"><code>core analysis</code></a>: Diretório voltado à análise dos núcleos utilizados durante a execução de um programa a partir dos comandos <code>htop</code> e <code>taskset</code>;</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/tree/main/lab02/lab02b/par_execs"><code>par_execs</code></a>: Diretório de <i>logs</i> de execuções da versão paralela;</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/tree/main/lab02/lab02b/otm_execs"><code>otm_execs</code></a>: Diretório de <i>logs</i> de execuções da versão paralela <strong>otimizada</strong>.</li>
</ul>

<p><strong>IMPORTANTE</strong>: A máquina utilizada apresenta <strong>8 núcleos</strong>. Você pode conferir essa informação nos arquivos <code>proc_specs.txt</code> e <code>num_cores.txt</code>, presentes no diretório <code>core-analysis</code>.</p>

<h2>Compilação e execução</h2>

<h3>Compilação</h3>
<p>Os programas foram compilados da seguinte forma:</p>
<img src="https://raw.githubusercontent.com/lihviaa/parallel-comp/main/assets/lab02b_comp.png" alt="Compilação dos códigos desenvolvidos."/>
<p>Obs.: Não se esqueça de informar o argumento <code>-lpthread</code> ao compilar os arquivos <code>lab02b_par.c</code> e <code>lab02b_otm.c</code>.</p>

<h3>Execução</h3>
<h4>Serial</h4>
<img src="https://raw.githubusercontent.com/lihviaa/parallel-comp/main/assets/lab02b_srl-exec.png" alt="Execução serial."/>
<h4>Paralela</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_par-exec.png" alt="Execução paralela."/>
<h4>Paralela otimizada</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab02b_otm-exec.png" alt="Execução paralela otimizada."/>
<p>Para executar os programas <code>lab02b_srl.c</code> e <code>lab02b_par.c</code>, é necessário informar o <strong>número de linhas e de colunas da matriz</strong> como os <strong>dois primeiros argumentos</strong> após o nome do programa na linha de comando:</p>
<p align="center"><code>./nomedoprograma &ltlinhas&gt &ltcolunas&gt</code></p>
<p>Para executar o programa <code>lab02b_otm.c</code>, além dos argumentos de linhas e colunas, deve-se informar o número de <i>threads</i> que serão criadas para a execução do programa:</p>
<p align="center"><code>./nomedoprograma &ltlinhas&gt &ltcolunas&gt &ltnumero_threads&gt</code></p>
<h4>Comandos adicionais utilizados:</h4>
<ul>
    <li><code>time</code>: Mede o tempo de execução do programa.</li>
    <li><code>taskset -c [Núcleos]</code>: Especifica os núcleos de CPU a serem utilizados na execução do programa. Substitua <code>[Núcleos]</code> pelos núcleos desejados.</li>
</ul>

<h3>Argumentos</h3>
<ul>
 <li><code>&ltlines&gt</code>: <strong>OBRIGATÓRIO</strong>. Define o <strong>número de linhas da matriz aleatória a ser gerada</strong>;</li>
 <li><code>&ltcolumns&gt</code>: <strong>OBRIGATÓRIO</strong>. Define o <strong>número de colunas da matriz aleatória a ser gerada</strong>;</li>
 <li><code>&ltnumero_threads&gt</code>: <strong>SOMENTE PARA <code>lab02b_otm.c</code></strong>. Define o número de threads a serem executadas.</li>
</ul>


<h3>Exemplos de execução</h3>
<ul>
 <li><code>time taskset -c 0 ./lab02b_(par/srl).out 10 10</code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos em somente um núcleo, gerando um vetor de 10 elementos</strong>. O tempo de execução para um núcleo <strong>será exibido no terminal</strong>.</li>

 <li><code>time taskset -c 0, 1, 2, 3, 4, 5, 6, 7 ./lab02b_(par/srl).out 10 10</code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos em oito núcleos, gerando um vetor de 10 elementos</strong>. O tempo de execução para oito núcleos <strong>será exibido no terminal</strong>.</li>

 <li><code>time taskset -c 0, 1, 2, 3, 4, 5, 6, 7 ./lab02b_(par/srl).out 10 10</code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos em oito núcleos, gerando um vetor de 10 elementos</strong>. O tempo de execução <strong>será exibido no terminal</strong>.</li>
</ul>
<p>Para informações mais detalhadas a respeito, leia as seções <b>Compilação</b> e <b>Execução</b> no <a href="https://github.com/lihviaa/parallel-comp/blob/main/README.md">documento descritivo do repositório</a>.</p>


<h2>Questões</h2>

<p><strong>IMPORTANTE</strong>: Para responder às questões, será utilizada como padrão uma matriz quadrada de 4800 linhas e 4800 colunas.</p>

<ins><h3>1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução</h3></ins>

<h4>Gráfico Tempo(ms) x Núcleos de Execução Serial</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/graph-serial-exec.png" width=600 align="center" alt="Serial: Tempo x núcleos"/>

<h4>Gráfico de Tempo(ms) x Núcleos de Execução Paralela</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/graph-parallel-exec.png" width=600 align="center" alt="Paralela: Tempo x núcleos"/>

<table align= "center">
     <tr>
          <td><strong>Núcleos</strong></td>
          <td><strong>1</strong></td>
          <td><strong>2</strong></td>
          <td><strong>4</strong></td>
          <td><strong>6</strong></td>
          <td><strong>8</strong></td>
     </tr>
     <tr>
           <td><strong>Tempo de Execução Serial</strong></td>
           <td>0,456s</td>
           <td>0,450s</td>
           <td>0,451s</td>
           <td>0,447s</td>
           <td>0,447s</td>
     </tr>
     <tr>
           <td><strong>Tempo de Execução Paralela</strong></td>
           <td>0,585s</td>
           <td>0.531s</td>
           <td>0.503s</td>
           <td>0.503s</td>
           <td>0.501s</td>
     </tr>
     <tr>
           <td><strong>Tempo de Execução Paralela Otimizada</strong></td>
           <td>0,462s</td>
           <td>0.432s</td>
           <td>0.415s</td>
           <td>0.419s</td>
           <td>0.413s</td>
     </tr>
</table>


<ins><h3>2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.</h3></ins>

<h4>Speedup entre execuções Serial</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/graph-serial-speedup.png" width=600 align="center" alt="Serial: Speedup" />

<h4>Speedup entre execuções Paralela</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/graph-parallel-speedup.png" width=600 align="center" alt="Paralela: Speedup"/>

<table align="center">
    <tr>
          <td><strong>Processadores</strong></td>
          <td><strong>1</strong></td>
          <td><strong>2</strong></td>
          <td><strong>4</strong></td>
          <td><strong>6</strong></td>
          <td><strong>8</strong></td>
    </tr>
    <tr>
           <td><strong>Speedup Serial</strong></td>
           <td>1</td>
           <td>1,01</td>
           <td>0,99</td>
           <td>1,01</td>
           <td>1</td>
     </tr>
     <tr>
           <td><strong>Speedup Paralelo</strong></td>
           <td>1</td>
           <td>1,10</td>
           <td>1,06</td>
           <td>1</td>
           <td>1</td>
     </tr>
</table>

<p>Comparando as execuções entre diferentes núcleos das execuções Serial e Paralela, nota-se uma tendência de <strong>estabilidade</strong> com raras elevações da taxa de <i>speedup</i> acima de 1. Isso demonstra que o aumento de núcleos não é tão responsivo nessas execuções, uma vez que uma delas é <strong>serial</strong> (utilizando apenas um núcleo) e a outra faz um <strong>mau manejamento de paralelismo com <i>threads</i></strong>.</p>

<h4>Speedup entre execuções Serial-Paralela</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/graph-speedup-srl-par.png" width=600 align="center" alt="Serial-Paralela: Speedup"/>
<table align="center">
    <tr>
          <td><strong>Processadores</strong></td>
          <td><strong>1</strong></td>
          <td><strong>2</strong></td>
          <td><strong>4</strong></td>
          <td><strong>6</strong></td>
          <td><strong>8</strong></td>
    </tr>
    <tr>
           <td><strong>Speedup Serial-Paralelo</strong></td>
           <td>0,77</td>
           <td>0,85</td>
           <td>0,9</td>
           <td>0,89</td>
           <td>0,89</td>
     </tr>
</table>

<p>Analisando a comparação entre as execuções serial e paralela de mesmo número de núcleos, percebe-se que a implementação paralela não-otimizada performa com taxa de <strong>speedup sempre abaixo de 1</strong>, demonstrando que, embora sejam utilizadas <i>threads</i>, sua má aplicação não é capaz de performar melhor do que uma abordagem serial.</p>
           
<ins><h3>3. Como você acha que poderia melhorar o seu algoritmo para obter maior benefício com o paralelismo? Para provar seu ponto, refaça a solução com essa abordagem e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.</h3></ins>

<p>A abordagem paralela original cria <strong>uma thread para cada elemento do vetor resultante</strong>. Sendo o vetor resultante composto por <strong>4800 elementos</strong>, serão criadas 4800 threads. Entretanto, sendo uma máquina <strong>limitada a 8 núcleos</strong>, grande parte dessas <i>threads</i> perderão o aspecto de paralelismo e serão executadas, portanto, de modo <strong>serial</strong>.</p>

<p>Para resolver este conflito, propôs-se a seguinte abordagem: <strong>o número de threads é definido nas linhas de comando, sendo limitado ao número de núcleos utilizados para executar o programa</strong>, e <strong>a um determinado seguimento de tamanho dinâmico do vetor resultante será atribuída uma <i>thread</i>, que se responsabilizará por calcular os elementos deste seguimento.</strong></p>

<p>Por exemplo, em uma multiplicação de uma matriz de 8 linhas e 8 colunas, resultará um vetor de 8 elementos. Caso executemos o programa com 4 núcleos, teremos 4 <i>threads</i>, resultando em 8/4 = 2 linhas da matriz a serem multiplicadas por cada <i>thread</i>. Assim, embora as <i>threads</i> executem algumas operações de modo serial, a execução das <i>threads</i> entre si será <strong>totalmente paralela</strong>.</p>

<h4>Gráfico de Tempo(ms) x Núcleos de Execução Paralela OTIMIZADA</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/graph-optimized-exec.png" width=600 align="center" alt="Paralela Otimizada: Tempo x núcleos"/>

<table align= "center">
     <tr>
          <td><strong>Núcleos</strong></td>
          <td><strong>1</strong></td>
          <td><strong>2</strong></td>
          <td><strong>4</strong></td>
          <td><strong>6</strong></td>
          <td><strong>8</strong></td>
     </tr>
     <tr>
           <td><strong>Tempo de Execução Paralela OTIMIZADA</strong></td>
           <td>0,462s</td>
           <td>0,432s</td>
           <td>0,415s</td>
           <td>0,419s</td>
           <td>0,413s</td>
     </tr>
</table>

<p>Observa-se facilmente que os tempos de execução da versão otimizada são mais satisfatórios do que os da versão que desperdiça o paralelismo das <i>threads</i>.</p>

<h4>Speedup entre execuções Paralela Otimizada</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/graph-optimized-speedup.png" width=600 align="center" alt="Paralela Otimizada: Speedup"/>

<table align= "center">
     <tr>
          <td><strong>Núcleos</strong></td>
          <td><strong>1</strong></td>
          <td><strong>2</strong></td>
          <td><strong>4</strong></td>
          <td><strong>6</strong></td>
          <td><strong>8</strong></td>
     </tr>
     <tr>
           <td><strong>Speedup Paralela OTIMIZADA</strong></td>
           <td>1</td>
           <td>1,07</td>
           <td>1,04</td>
           <td>0,99</td>
           <td>1,01</td>
     </tr>
</table>

<h4>Speedup entre execuções Serial-Otimizada</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/graph-speedup-srl-otm.png" width=600 align="center" alt="Serial-Otimizada: Speedup"/>

<table align= "center">
     <tr>
          <td><strong>Núcleos</strong></td>
          <td><strong>1</strong></td>
          <td><strong>2</strong></td>
          <td><strong>4</strong></td>
          <td><strong>6</strong></td>
          <td><strong>8</strong></td>
     </tr>
     <tr>
           <td><strong>Speedup Serial-OTIMIZADA</strong></td>
           <td>0,99</td>
           <td>1,04</td>
           <td>1,09</td>
           <td>1,07</td>
           <td>1,08</td>
     </tr>
</table>

<p>Percebe-se que <strong>tanto quando comparado com execuções otimizadas de diferentes quantidades de núcleos empregados quanto quando comparado com a execução serial</strong>, o <strong><i>speedup</i> da versão otimizada se apresenta em taxas bem mais satisfatórias</strong>, geralmente estando <strong>acima da taxa de 1 de <i>speedup</i></strong>.</p>

<p>Sendo assim, <strong>atesta-se a melhor performance e melhor aproveitamento do paralelismo de <i>threads</i> nessa abordagem otimizada da execução paralela.</strong></p>
