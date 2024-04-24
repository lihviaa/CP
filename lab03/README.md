<h1>Lab03 - OpenMP</h1>
<p>Iniciado em 18/04/2024. Concluído em 23/04/2024.</p>

<h2>Sobre a atividade desenvolvida no laboratório</h2>
<p>No Lab03, os integrantes construíram uma solução paralela utilizando OpenMP para calcular o valor aproximado da área da curva que representa a função f(x) = sen(x).</p>

<p>Desenvolvemos dois códigos:</p>
<ul>
  <li><code>critical.c</code>: Uma implementação paralela do método do trapézio para estimar a área de uma função entre dois limites. Ele recebe os limites esquerdo e direito da área, o número de trapézios a usar na aproximação e o número de threads a serem usadas. Cada thread calcula uma parte da soma das áreas dos trapézios e, em seguida, uma região crítica é usada para garantir que a soma global seja calculada corretamente.</li>
  <li><code>no-critical.c</code>: Semelhante ao <code>critical.c</code>, mas não inclui região crítica. Cada thread calcula a soma das áreas dos trapézios individualmente e, em seguida, esses resultados são somados diretamente à variável global_summ. Isso pode levar a resultados incorretos devido a condições de corrida, onde várias threads tentam atualizar a mesma variável simultaneamente, sem sincronização adequada.</li>
</ul>

<h2>Índice</h2>
<p>O diretório <code>lab03</code> está organizado da seguinte forma:</p>
<ul>
  <li><a href=""><code>README.md</code></a>: Documento descritivo (você o está lendo agora! 🙂);</li>
  <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab03/critical.c"><code>critical.c</code></a>: Código-fonte gerado a partir da atividade <code>com área crítica</code>;</li>
  <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab03/no-critical.c"><code>no-critical.c</code></a>: Código-fonte gerado a partir da atividade <code>sem área crítica</code>;</li>
  <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab03/sinf.h"><code>sinf.h</code></a>: Cabeçalho utilizada para calcular a base do trapézio;</li>
  <li><a href="https://github.com/lihviaa/parallel-comp/blob/main/lab03/traprule.h"><code>traprule.h</code></a>: Cabeçalho utilizado para calcular o somatório das áreas dos trapézios;</li>
</ul>

<p><strong>IMPORTANTE</strong>: A máquina utilizada apresenta <strong>8 núcleos</strong>. Você pode conferir essa informação nos arquivos <code>proc_specs.txt</code> e <code>num_cores.txt</code>, presentes no diretório <code>core-analysis</code> no <a href="https://github.com/lihviaa/parallel-comp/tree/main/lab02/lab02b/core-analysis">lab02b.</p>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab03-pics/cpuinfo.png" alt="Número de núcleos do processador"/>

<h2>Compilação e execução</h2>
<h3>Compilação</h3>
<p>Os programas foram compilados da seguinte forma:</p>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab03-pics/compilacao.png" alt="Compilação dos códigos desenvolvidos."/>
<p>Obs.: Não se esqueça de informar o argumento <code>-fopenmp</code> e <code>-lm</code> ao compilar os arquivos <code>critical.c</code> e <code>no-critical.c</code>.</p>

<h3>Execução</h3>
<h4>Argumentos</h4>
<p>Para executar o programa os seguintes argumentos devem ser informados:</p>
<ul>
  <li><code>&ltlimite esquerdo&gt</code>: Limite à esquerda do intervalo sobre o qual você está calculando a área usando a regra do trapézio;</li>
  <li><code>&ltlimite direito&gt</code>: Limite à direita do intervalo sobre o qual você está calculando a área usando a regra do trapézio;</li>
  <li><code>&ltn_traps&gt</code>: O número de trapézios que você deseja usar para calcular a área.</li>
  <li><code>&ltn_threads&gt</code> O número de threads que você deseja usar para paralelizar o cálculo.</li>
</ul>

<hr> 
<p><strong>IMPORTANTE</strong>: Para as execuções foi utilizado o valor de 2<sup>30</sup> como número de trapézios:</p>

<h4>Serial sem área crítica</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab03-pics/exec-serial.png" alt="Execução serial sem área crítica."/>

<h4>Serial com área crítica</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab03-pics/exec-serial-critical.png" alt="Execução serial com área crítica."/>

<h4>Execução paralela sem área crítica</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab03-pics/exec-paralela.png" alt="Execução paralela sem área crítica."/>

<h4>Execução paralela com área crítica</h4>
<img src="https://github.com/lihviaa/parallel-comp/blob/main/assets/lab03-pics/exec-paralela-critical.png" alt="Execução paralela com área crítica."/>

<h2>Questões</h2>
<h3>1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução</h3>

<h4>Gráfico Tempo(ms) x Núcleos de Execução Serial (Não-Crítico)</h4>
<img src="" width=600 align="center" alt="Serial: Tempo x núcleos"/>

<h4>Gráfico de Tempo(ms) x Núcleos de Execução Paralela (Não-Crítico)</h4>
<img src="" width=600 align="center" alt="Paralela: Tempo x núcleos"/>

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
           <td><strong>Tempo de Execução Serial (Não-Crítico)</strong></td>
           <td>15,326s</td>
           <td>15,334s</td>
           <td>15,356s</td>
           <td>15,358s</td>
           <td>15,350s</td>
  </tr>
  <tr>
           <td><strong>Tempo de Execução Paralela (Não-Crítico)</strong></td>
           <td>15,350s</td>
           <td>7,845s</td>
           <td>4,259s</td>
           <td>3,986s</td>
           <td>3,612s</td>
  </tr>
</table>

<p>Com base nos resultados apresentados, fica claro que o tempo de execução paralela diminui significativamente à medida que o número de processadores aumenta. Isso mostra a eficiência do paralelismo para solucionar este problema.</p>
<hr>

<h3> 2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.</h3>

<h4>Speedup entre execuções Serial-Paralela (Não Crítico)</h4>
<img src="" width=600 align="center" alt="Serial-Paralela-não-crítica: Speedup"/>

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
           <td><strong>Speedup Serial-Paralelo (Não-Crítico)</strong></td>
           <td>0,998</td>
           <td>1,955</td>
           <td>3,606</td>
           <td>3,853</td>
           <td>4,250</td>
     </tr>
</table>

<p>Os resultados indicam um aumento no speedup à medida que o número de processadores aumenta. </p>

<hr>
<h3>3. Introduza na sua solução a diretiva critical. O que muda? Para provar seu ponto, refaça a solução com essa abordagem, calcule os novos valores e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.</h3>

  
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
           <td><strong>Tempo de Execução Serial (Não-Crítico)</strong></td>
           <td>15,326s</td>
           <td>15,334s</td>
           <td>15,356s</td>
           <td>15,358s</td>
           <td>15,350s</td>
  </tr>
  <tr>
           <td><strong>Tempo de Execução Paralela (Não-Crítico)</strong></td>
           <td>15,350s</td>
           <td>7,845s</td>
           <td>4,259s</td>
           <td>3,986s</td>
           <td>3,612s</td>
  </tr>
  <tr>
           <td><strong>Speedup Serial-Paralelo (Não-Crítico)</strong></td>
           <td>0,998</td>
           <td>1,955</td>
           <td>3,606</td>
           <td>3,853</td>
           <td>4,250</td>
  </tr>
</table>

<h4>Gráfico Tempo(ms) x Núcleos de Execução Serial (Crítico)</h4>
<img src="" width=600 align="center" alt="Serial: Tempo x núcleos"/>

<h4>Gráfico de Tempo(ms) x Núcleos de Execução Paralela (Crítico)</h4>
<img src="" width=600 align="center" alt="Paralela: Tempo x núcleos"/>

<h4>Speedup entre execuções Serial-Paralela (Crítico)</h4>
<img src="" width=600 align="center" alt="Serial-Paralela crítica: Speedup"/>

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
           <td><strong>Tempo de Execução Serial (Crítico)</strong></td>
           <td>15,393s</td>
           <td>15,334s</td>
           <td>15,350s</td>
           <td>15,340s</td>
           <td>15,341s</td>
  </tr>
  <tr>
           <td><strong>Tempo de Execução Paralela (Crítico)</strong></td>
           <td>15,344s</td>
           <td>7,809s</td>
           <td>4,257s</td>
           <td>4,026s</td>
           <td>3,587s</td>
     </tr>
  <tr>
           <td><strong>Speedup Serial-Paralelo (Crítico)</strong></td>
           <td>1,003</td>
           <td>1,964</td>
           <td>3,606</td>
           <td>3,810</td>
           <td>4,277</td>
     </tr>
</table>

<p>Ao introduzir a <code>diretiva critical</code> na solução, há uma mudança nos tempos de execução e, consequentemente, nos valores de speedup. A <code>diretiva critical</code> garante que apenas uma thread execute a seção crítica do código por vez, evitando condições de corrida.</p>

