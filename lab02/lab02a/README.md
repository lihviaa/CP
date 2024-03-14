<h1>Lab02 - Programação matriz-vetor</h1>
<p>Iniciado em 06/03/2024. Concluído em 12/03/2024.</p>

<h2>Sobre a atividade desenvolvida no laboratório</h2>
<p>No Lab02, os integrantes construíram uma solução para multiplicação matriz-vetor utilizando threads e, adicionalmente, realizaram um <i>benchmarking</i> comparando as execuções serial e paralela do algoritmo desenvolvido.</p>
<p>Na execução do algoritmo, o usuário define o número de linhas e colunas de uma matriz com elementos aleatórios, os quais serão multiplicados pelos elementos de um vetor (com número de elementos correspondente ao número de colunas da matriz) também formado por números aleatórios e, por fim, terão seu resultado armazenado em um vetor de número de elementos correspondente ao número de linhas da matriz.</p>
<p>Para evitar uma imensurável e desconfortável poluição visual no terminal, a saída do código é dada, por padrão, em arquivos <code>.txt</code>.</p>
<p>Ainda assim, caso deseje visualizar no terminal as matrizes e vetores gerados, <strong>atente-se aos <code>argumentos</code></strong> na seção de <strong><i>Compilação e execução</i></strong></p>

<h2>Índice</h2>
<p>O diretório <code>lab02</code> está organizado da seguinte forma:</p>
<ul>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/README.md"><code>README.md</code></a>: Documento descritivo (você o está lendo agora! 🙂);</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02.c"><code>lab02.c</code></a>: Código-fonte gerado a partir atividade;</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/arraylib.h"><code>arraylib.h</code></a>: Arquivo <i>header</i> contendo operações envolvendo vetores e matrizes;</li>
 <li><a href="https://github.com/lihviaa/parallel-comp/tree/main/lab02/logs"><code>logs</code></a></li>
 <ul>
  <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/logs/log01.txt"><code>log01.txt</code></a></li>
  <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/logs/log02.txt"><code>log02.txt</code></a></li>
  <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/logs/log03.txt"><code>log03.txt</code></a></li>
  <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/logs/log04.txt"><code>log04.txt</code></a></li>
 </ul>
</ul>

<h2>Compilação e execução</h2>
<p>Para compilar o código-fonte desenvolvido, executou-se, <b>em um terminal <i>Linux</i> com compilador <code>gcc</code></b>, a seguinte linha de comando:</p>
<p><code>gcc lab02.c -o lab02.out -lpthread</code></p>
<p>Para executar o arquivo gerado a partir da compilação do código-fonte descrita acima, executa-se a seguinte linha de comando:</p>
<p><code>./lab02.out &ltlines&gt &ltcolumns&gt "-p" "-bm"</code></p>
<h3>Argumentos</h3>
<ul>
 <li><code>&ltlines&gt</code>: <strong>OBRIGATÓRIO</strong>. Define o <strong>número de linhas da matriz aleatória a ser gerada</strong>;</li>
 <li><code>&ltcolumns&gt</code>: <strong>OBRIGATÓRIO</strong>. Define o <strong>número de colunas da matriz aleatória a ser gerada</strong>;</li>
 <li><code>"-p"</code>: <strong>Opcional</strong>. Exibe no terminal os vetores e matrizes gerados. Por padrão, a saída sempre é gerada em arquivos <code>.txt</code>;</li>
 <li><code>"-bm"</code>: <strong>Opcional</strong>. Habilita <strong>comparação entre execuções paralela e serial do algoritmo.</strong></li>
</ul>
<h3>Exemplos de execução</h3>
<ul>
 <li><code>./lab02.out</code>: <strong>ERRO</strong>. Números de linhas e de colunas não informados;</li>
 <li><code>./lab02.out 10</code>: <strong>ERRO</strong>. Número de colunas não informado;</li>
 <li><code>./lab02.out 10 10</code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos, gerando um vetor de 10 elementos</strong>. A matriz e os vetores <strong>NÃO serão exibidos no terminal</strong>. <strong>NÃO será realizado <i>benchmarking</i></strong>;</li>
 <li><code>./lab02.out 10 10 -p</code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos, gerando um vetor de 10 elementos</strong>. A matriz e os vetores <strong>serão exibidos no terminal</strong>. <strong>NÃO será realizado <i>benchmarking</i></strong>;</li>
 <li><code>./lab02.out 10 10 -bm</code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos, gerando um vetor de 10 elementos</strong>. A matriz e os vetores <strong>NÃO serão exibidos no terminal</strong>. <strong>Será realizado <i>benchmarking</i></strong>;</li>
 <li><code>./lab02.out 10 10 -p -bm</code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos, gerando um vetor de 10 elementos</strong>. A matriz e os vetores <strong>serão exibidos no terminal</strong>. <strong>Será realizado <i>benchmarking</i></strong>;</li>
 <li><code>./lab02.out 10 10 -bm -p</code>: Executa <strong>multiplicação entre uma matriz de 10 linhas e 10 colunas e um vetor de 10 elementos, gerando um vetor de 10 elementos</strong>. A matriz e os vetores <strong>serão exibidos no terminal</strong>. <strong>Será realizado <i>benchmarking</i></strong>.</li>
</ul>
<p>Para informações mais detalhadas a respeito, leia as seções <b>Compilação</b> e <b>Execução</b> no <a href="https://github.com/lihviaa/parallel-comp/blob/main/README.md">documento descritivo do repositório</a>.</p>
<p>Caso necessário, encontre mais exemplos de execução no diretório de <a href="https://github.com/lihviaa/parallel-comp/tree/main/lab02/logs"><code>logs</code></a>.</p>

<h2>Comprovação de êxito da atividade</h2>
<p>Para comprovar que os resultados propostos pela atividade foram alcançados, segue uma captura de tela apresentando <b>compilação</b> e <b>execução</b> da solução desenvolvida:</p>
<img src="https://raw.githubusercontent.com/lihviaa/parallel-comp/main/assets/execucaolab02.png" alt="Compilação e execução da atividade proposta no laboratório." />
<p>Consulte também o diretório <a href="https://github.com/lihviaa/parallel-comp/tree/main/lab02/logs"><code>logs</code></a> para verificar as saídas obtidas nas execuções do código-fonte compilado.</p>

<h3><i>Benchmarking</i></h3>
<p>A comparação entre as execuções <strong>serial</strong> e <strong>paralela</strong> do algoritmo foi realizada a partir da função <code><strong>clock</strong></code>, presente no arquivo <i>header</i> <code><strong>time.h</strong></code>, o qual foi devidamente incluído no <a href="https://github.com/lihviaa/parallel-comp/blob/main/lab02/lab02.c"><strong>código-fonte</strong></a> do laboratório.</p>
