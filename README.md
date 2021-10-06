# Batleship Game made for a university subject

## How to compile

Para compilar é preciso:

1. make static 
2. make engine
3. ./engine

Esta versão do battleship contém um random setup e manual setup;

Com um tamanho para o mapa entre 20 a 40;

De seguia é pedido para ser inserido em concordancia com os dois jogadores o numero de barcos para cada tipo de baro;

Esta verão contem 5 tipos de barcos:

1º) Tipo T;
2º) Tipo U;
3º) Tipo |; 
4º) Tipo ||;
5º) Tipo L;


Depois é pedido para colocar os barcos um a um;

Finalmente o jogo começa, pedindo as coordenadas para os tiros, começando primeiro o jogador 1 e depois o jogador 2;

Por cada tiro acertado numa peça é reduzido 1 de hp ao jogador contrário;

O jogo termina quando algum dos jogadores tiver o hp a 0 (hp é o numero total de peças de todos barcos, por exemplo neste caso o barco do tipo "|" tem 5 peças logo quando é atribuido este barco a um jogador o seu hp é incrementado em 5);

O trabalho foi divido em 8 ficheiros .c

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Para a parte b)

A certo momento do jogo é questionado se pretende usar quadtrees ou arrays.
Foi adicionado mais um ficheiro .c.
