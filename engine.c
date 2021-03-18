#include "engine.h"

int main(int argc, char** argv){
	
	ENGINE* e = (ENGINE*) malloc(sizeof(ENGINE));
	if(e == NULL){
		printf("Error\n");
		exit(0);
	}
	srand(time(NULL));
	system("clear");
	print_logo();
	e->s = setup_input();
	if(e->s->type_of_storage == 'Q'){
		e->g = play_game_q(e->s);	
	}
	else{
		e->g = play_game_a(e->s);
	}
	
	if(e->g->winner == '1'){
		printf("Player 1 you have won\n");
	}
	else{
		printf("Player 2 you have won\n");
	}
	free(e->s->p1->field);
	free(e->s->p2->field);
	free(e->s);
	free(e->g);
	exit(0);
}