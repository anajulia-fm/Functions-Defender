
# A função 'mk_u' tem a missão de colocar um CARACTER CONHECIDO em cada uma
das posições da matriz universo - a matriz universo é aquela qué é impressa
na tela-, fazendo assim que, após verificação, não sejam alocados valores
repitidos na matriz universo.

# Função main: 
   - Matriz Universo -> A matriz universo representa o mapa "global", ou seja,
   o mapa em toda sua extensão;
   - Mapa do Arquivo Binário -> Representa a matriz que comportará o mapa lido
   da pasta de mapas;
   - Variaveis de Navegação (i, j, k, l) -> Essas Variaveis são utilizadas para
   navegar dentro dos vetores onde o par ordenado (j, i) é equivalente ao conjunto
   de coordenadas (x, y) da 'matriz universo' e o (l, k) o da matriz 'mapa do
   arquivo binario';
   - Variavel de impressão (y) -> Tem a função de alocar o local correto de impressão
   tanto no eixo x quanto no y;
   - Variavel de Incremento de posição da matriz (x) -> Quando é incrementado aumenta
   em x unidades onde começa a impressãoda matriz;
   - Variaveis de Loop (horaDoLoop) -> Quando o caracter que indica que a Matriz acabou
   é encontrado a variavel é igualada a um, indicando que na proxima interação a matriz
   que contem o mapa devera ser reiniciada -> mapaDoArquivoBinario[0][0], OBS.: Esta
   função não interfere nos valores da matrizUniverso;
   - Variavel flagL -> Indica que novos valores foram alocados na matriz Universo;
   - Variavel tempL -> A cada interação armazena o ultimo valor de l conhecido, sendo
   que l é o valor no eixo x da matriz mapaDoArquivoBinario.