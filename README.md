<h1>Parallel Computing</h1>
<p>Repositório destinado ao armazenamento das atividades desenvolvidas na disciplina de Computação Paralela, componente curricular do 5° semestre do curso de Ciência da Computação da Universidade Presbiteriana Mackenzie.</p>

<h2>Integrantes</h2>
<ul>
  <li>Guilherme de Abreu Schulz </li>
  <li>Livia Alabarse dos Santos</li>
  <li>Pedro Henrique Araujo Farias</li>
</ul>

<h2>Organização</h2>
<p>O repositório está organizado da seguinte maneira:</p>
<blockquote>
  <ul>
    <li><code>assets</code>: Diretório de imagens para README</li>
    <li><code>labxx</code></li>
    <ul>
      <li><code>labxx.c</code></li>
      <li><code>...</code></li>
      <li><code>log.txt</code></li>
      <li><code>README.md</code></li>
    </ul>
    <li><code>labxy</code></li>
    <ul>
      <li><code>labxy.c</code></li>
      <li><code>...</code></li>
      <li><code>log.txt</code></li>
      <li><code>README.md</code></li>
    </ul>
    <li><code>...</code></li>
    <li><code>README.md</code></li>
  </ul>
</blockquote>

<h2>Compilação</h2>
<p>A linguagem de programação C foi a escolhida pelos integrantes para o desenvolvimento das atividades. Sendo assim, torna-se necessária a utilização do compilador <b><code>gcc</code></b> para compilar o código-fonte gerado nas atividades.</p>
<p>Em uma distribuição <i>Linux Red Hat</i>, é possível instalar o compilador da linguagem C a partir do seguinte comando: <code>sudo dnf install gcc</code>.</p>
<p>Para compilar o arquivo de código-fonte <code>file.c</code>, é utilizado o comando <code>gcc file.c</code>. Este comando deve gerar, por padrão, um arquivo <code>a.out</code>.</p>
<p>Ao longo dos laboratórios, todavia, será utilizado o comando <code>gcc file.c -o file.out</code>, onde <code>-o file.out</code> é utilizado para definir o arquivo de saída como <code>file.out</code>, de modo a apresentar uma melhor organização no diretório.</p>

<h2>Execução</h2>
<p>Para executar um arquivo <code>.out</code> em um terminal <i>Linux</i>, acesse o diretório onde está localizado o arquivo a partir do comando <code>cd diretorio</code> e, em seguida, execute a seguinte linha de comando: <code>./arquivo.out</code>.</p>
<p>Por exemplo, para executar o arquivo <code>teste.out</code>, localizado no diretório <code>testedir</code>, acesse o diretório a partir de <code>cd testedir</code> e, em seguida, execute <code>teste.out</code>.</p>

<h2>Comprovação de êxito da atividade</h2>
<p>De modo a comprovar que os resultados propostos pela atividade foram alcançados, são gerados arquivos <code>log.txt</code> em cada um dos laboratórios, os quais apresentam a saída gerada pela execução dos arquivos <code>.out</code> gerados pelos arquivos de código-fonte <code>.c</code>.</p>
<p>Além disso, nos arquivos README são apresentadas capturas de tela demonstrando <b>compilação</b>, <b>execução</b>, <b>geração dos arquivos <code>log.txt</code></b> e <b>saída</b> obtida a partir da execução do código compilado.</p>

<h3>Observações</h3>
<ul>
  <li>Arquivos <code>.out</code> não serão adicionados ao repositório, uma vez que estes podem ser obtidos a partir da compilação do código-fonte. O objetivo do repositório é armazenar soluções em código-fonte às atividades propostas, não apresentar <i>releases</i> ou produtos executáveis das mesmas.</li>
</ul>
