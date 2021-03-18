#include "player.h"

PLAYER* new_player(int player_id, int map_size){

	PLAYER* p = (PLAYER*) malloc(sizeof(PLAYER));
	if(p == NULL){
		printf("Error\n");
		exit(0);
	} 
	set_id(p,player_id);
	set_field(p,map_size);
	p->hp = 0;
	return p;
}
void set_id(PLAYER* p, int player_id){
	p->id = player_id;
}
void set_hp(PLAYER* p, int numb){
	p->hp = p->hp + numb;
}
void set_field(PLAYER* p, int map_size){
	
	p->field = (CELL***) malloc(map_size*sizeof(CELL**));
	if(p->field == NULL){
		printf("Error\n");
		exit(0);
	}
	for(int i=0; i<map_size; i++){
		p->field[i] = new_array_cell(map_size);
		for(int j=0; j<map_size; j++){
			p->field[i][j] = new_cell();
		}
	}
}
int get_id(PLAYER* p){
	return p->id;
}
int get_hp(PLAYER* p){
	return p->hp;
}
void print_id(PLAYER* p){
	printf("Player %d\n", p->id);
}

//função parar printar o mapa de cada jogador, mas printando o estado das celulas
void print_field_s(PLAYER* p, int map_size){

	for(int i=0; i<map_size; i++){
		for(int j=0; j<map_size; j++){
				printf("%c", p->field[i][j]->state);
		}
		printf("\n");
	}
	printf("\n");
}

void print_field_q(PLAYER* pl, int map_size){

	int side;
	POINT* se_corner;
	POINT* p;
	QD_NODE* qd_node;

	if(map_size <= 32) side = 32;
	else side = 64;
	
	se_corner = make_point(side,side);

	for(int i=0; i<map_size; i++){
		for(int j=0; j<map_size; j++){
			p = make_point(i,j);
			qd_node = search(pl->qtree,p, se_corner,side);
			if(qd_node == NULL) printf("0");
			else if(qd_node->node.leaf.field_pointer->state == 3){
				printf("3");
			}
			else printf("0");
		}		
		printf("\n");
	}
	printf("\n");
}

////função parar printar o mapa de cada jogador, mas printando os desenhos dos barcos
void print_field_p(PLAYER* p, int map_size){

	for(int i=0; i<map_size; i++){
		for(int j=0; j<map_size; j++){
			if(p->field[i][j]->boat_pointer == NULL){
				printf("~");
			}
			else{
				if(strcmp(p->field[i][j]->boat_pointer->type,"T") == 0){
					printf("T");
				}
				else if(strcmp(p->field[i][j]->boat_pointer->type,"U") == 0){
					printf("U");	
				}
				else if(strcmp(p->field[i][j]->boat_pointer->type,"||") == 0){
					printf("I");	
				}
				else if(strcmp(p->field[i][j]->boat_pointer->type,"|") == 0){
					printf("i");	
				}
				else if(strcmp(p->field[i][j]->boat_pointer->type,"L") == 0){
					printf("L");	
				}
			}
		}
		printf("\n");
	}
	printf("\n");
}