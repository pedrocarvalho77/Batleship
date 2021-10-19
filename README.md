# Batleship Game feito para unidade curricular
O trabalho eśta divido em 8 ficheiros '.c'

## Como compilar e correr
Para compilar é preciso:

1. make static 
2. make engine
3. ./engine

# Como jogar

Esta versão do battleship contém um random setup e um manual setup

O tamanho do mapa varia entre 20 a 40 unidades

Em seguia é pedido para ser inserido em ***concordância*** com os dois jogadores o número de barcos para cada tipo de barco

Esta versão contem 5 tipos de barcos:

1. Tipo T;
2. Tipo U;
3. Tipo |; 
4. Tipo ||;
5. Tipo L;

Depois é pedido para colocar os barcos um a um no mapa

Finalmente o jogo começa, pedindo as coordenadas para os tiros, começando primeiro o jogador 1 e depois o jogador 2

Por cada tiro acertado numa peça é reduzido 1 de hp ao jogador adversário

O jogo termina quando algum dos jogadores tiver o hp a 0 (hp é o numero total de peças de todos barcos, por exemplo neste caso o barco do tipo "|" tem 5 peças logo quando é atribuido este barco a um jogador o seu hp é incrementado em 5)

A certo momento do jogo é questionado se pretende usar ***quadtrees ou arrays***
