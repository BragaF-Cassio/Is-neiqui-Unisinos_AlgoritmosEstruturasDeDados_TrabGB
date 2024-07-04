# Unisinos_AlgoritmosEstruturasDeDados_TrabGB
Trabalho do Grau B de Algoritmos Estruturas De Dados da Unisinos 2024/1

Prof: Rossana Baptista Queiroz
Aluno: Cássio Ferreira Braga

## Informações:
Algumas peças do computador utilizado:
- Processador Intel Core i3 9100f
- 32 GB de memória RAM DDR4
- Placa de vídeo GTX 1660 Super

Os testes foram conduzidos conforme documento fornecido pela prof. no Moodle.

Tempos em nanossegundos.

O tempo da tabela é o resultado da média dos valores ignorando os mesmos fora do desvio padrão.

## Array em Ordem (em nanossegundos)
|Tamanho	|Bubble Sort	|Insertion Sort	|Selection Sort	|Heap Sort	|Shell Sort	|Merge Sort	|Quick Sort   |
|-----------|---------------|---------------|---------------|-----------|-----------|-----------|-------------|
|128		|0				|0				|0				|0			|0			|0			|0            |
|256		|0				|0				|0				|0			|0			|0			|0            |
|512		|0				|0				|0				|0			|0			|0			|0            |
|1024		|0				|0				|997000			|0			|0			|0			|0            |
|2048		|0				|0				|3989666		|0			|0			|0			|0            |
|4096		|0				|0				|18447000		|997666		|0			|1000875	|498700       |
|8192		|0				|0				|69477222		|1993857	|0			|1994166	|997428       |
|16384		|0				|0				|274772166		|3985500	|997000		|2988125	|1991222      |
|32768		|0				|0				|1059505166		|8134333	|997500		|6986285	|4985250      |
|65536		|0				|0				|4238165750		|17952000	|2991777	|13966125	|9977000      |



## Array invertido (em nanossegundos)
|Tamanho	|Bubble Sort	|Insertion Sort	|Selection Sort	|Heap Sort	|Shell Sort	|Merge Sort	|Quick Sort   |
|-----------|---------------|---------------|---------------|-----------|-----------|-----------|-------------|
|128		|0				|0				|0				|0			|0			|0			|0            |
|256		|0				|0				|0				|0			|0			|0			|0            |
|512		|993428			|0				|0				|0			|0			|0			|0            |
|1024		|5319333		|999222			|1000111		|0			|0			|0			|0            |
|2048		|21940333		|3994428		|3989285		|0			|0			|0			|0            |
|4096		|86265500		|17946666		|16458800		|997875		|0			|997250		|498600       |
|8192		|340420166		|69484666		|64389714		|1994666	|0			|1995000	|1000875      |
|16384		|1346975571		|273390125		|253175142		|3994166	|997000		|2992000	|2625000      |
|32768		|5375078000		|1090088444		|1006738857		|7975000	|1997777	|6981375	|5985833      |
|65536		|21508476555	|4347154222		|4025853750		|16384857	|3980428	|13962500	|10978428     |



## Array embaralhado sem repetições (em nanossegundos)
|Tamanho	|Bubble Sort	|Insertion Sort	|Selection Sort	|Heap Sort	|Shell Sort	|Merge Sort	|Quick Sort   |
|-----------|---------------|---------------|---------------|-----------|-----------|-----------|-------------|
|128		|0				|0				|0				|0			|0			|0			|0            |
|256		|0				|0				|0				|0			|0			|0			|0            |
|512		|997375			|0				|0				|0			|0			|0			|0            |
|1024		|4992600		|498600			|997375			|0			|0			|0			|0            |
|2048		|18333000		|2324222		|5208222		|0			|332333		|997000		|0            |
|4096		|76919375		|8983875		|17945833		|1001000	|993125		|997000		|997166       |
|8192		|311366800		|34905400		|68372666		|1994750	|1994166	|2001750	|1001500      |
|16384		|1253522375		|138629750		|266853571		|3989222	|3989500	|3989285	|2995500      |
|32768		|5042513444		|549907625		|1062494777		|8976000	|12968888	|8970600	|5983833      |
|65536		|20312721333	|2184827111		|4247528111		|18949333	|32907166	|17619444	|13967500     |



## Array embaralhado com repetições (em nanossegundos)
|Tamanho	|Bubble Sort	|Insertion Sort	|Selection Sort	|Heap Sort	|Shell Sort	|Merge Sort	|Quick Sort   |
|-----------|---------------|---------------|---------------|-----------|-----------|-----------|-------------|
|128		|0				|0				|0				|0			|0			|0			|0            |
|256		|0				|0				|0				|0			|0			|0			|0            |
|512		|1000750		|0				|0				|0			|0			|0			|0            |
|1024		|4992400		|997666			|994750			|0			|0			|0			|0            |
|2048		|18280888		|1994625		|3989166		|0			|443444		|665000		|0            |
|4096		|79501571		|8977000		|17952142		|997285		|997142		|994333		|1001142      |
|8192		|315600222		|34241666		|67150555		|1994555	|1994750	|1994666	|1496000      |
|16384		|1294964857		|136635142		|267650500		|3993625	|4425000	|3989142	|2992333      |
|32768		|5136491555		|549778750		|1069808444		|8969250	|10970666	|8421888	|6482800      |
|65536		|20736445777	|2198557571		|4277686444		|18945875	|27923800	|17781166	|13526000     |

Pode-se notar que, em alguns casos específicos, o método que se comporta melhor varia, mas que no geral, o Quick Sort se sai bem em boa parte.
Para que ele desempenhasse um bom papel, seu pivô selecionado era aleatório a cada iteração.