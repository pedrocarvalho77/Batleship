#include "cell.h"

CELL* new_cell(){

	CELL* c;
	c = (CELL*) malloc(sizeof(CELL));
	if(c == NULL){
		printf("Error\n");
		exit(0);
	}
	
	set_state(c,'0');
	set_pointer_to_null(c);
	
	return c;
}
CELL** new_array_cell(int map_size){
	
	CELL** c;
	c = (CELL**) malloc(map_size*sizeof(CELL*));
	if(c == NULL){
		printf("Error\n");
		exit(0);
	} 
	
	for(int i=0; i<map_size;i++){
		c[i] = new_cell();
	}
	return c;
}
void set_state(CELL* c, char cell_state){
	c->state = cell_state;
}
void set_pointer_to_null(CELL* c){
	c->boat_pointer = (BOAT*) malloc(sizeof(BOAT));
	c->boat_pointer = NULL;
}
void set_pointer(CELL* c , BOAT* b){
	if(b == NULL){
		printf("Error\n");
		exit(0);
	}
	c->boat_pointer = b;
	c->boat_pointer->type = (char*) malloc(sizeof(char));
}
char get_state(CELL* c){
	return c->state;
}
BOAT* get_pointer(CELL *c){
	return c->boat_pointer;
}
void print_cell(CELL* c){

	printf("Stafe os cell is: %c\n", c->state);
	printf("Pointer: %p\n", &c->boat_pointer);
}