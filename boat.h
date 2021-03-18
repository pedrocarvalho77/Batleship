#ifndef BOAT_H
#define BOAT_H

#include <string.h>
#include "point.h"

//struct do tipo barco
typedef struct{
	
	char* type; //string com o tipo de barco, ex "T", "L", etc.
	char bitmap[5][5];

} BOAT;

//assinatura das funções para criar barcos
BOAT* new_boat(char*);

void set_boat_type(BOAT*,char*);

char* get_boat_type(BOAT*);

//função para rodar o bitmap do barco
void rotate_boat(BOAT*);
//função que retorna um valor aleatorio entre 0 e 3 para saber se roda o bitmap em 0º,90º,180º,270º 
int rnd_rotation();

//funçao auxiliar para  que retorna o tipo de barco, dando um iterador do ciclo como input
char* int_to_char(int);

void print_boat_type(char*);
void print_boat(BOAT*);

#endif