#ifndef CELL_H
#define CELL_H

#include "boat.h"

typedef struct{
	
	char state;					 
	BOAT* boat_pointer;
	int shot_count;
				
} CELL;

//assinatura da função para criar uma celula

//função para criar uma celula
CELL* new_cell();
//função para criar um array de celulas
CELL** new_array_cell(int);

void set_state(CELL*, char);
void set_pointer_to_null(CELL*);
void set_pointer(CELL*, BOAT*);

char get_state(CELL*);
BOAT* get_pointer(CELL*);

void print_cell(CELL*);

#endif