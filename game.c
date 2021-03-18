#include "game.h"

GAME* new_game(){

	GAME* g = (GAME*) malloc(sizeof(GAME));

	return g;
}
void set_winner(GAME* g, char player){
	g->winner = player;
}
char get_winner(GAME* g){
	return g->winner;
}
GAME* play_game_a(SETUP* s){

	GAME* g = new_game();
	POINT* p;
	
	while(s->p1->hp != 0 && s->p2->hp != 0){

		int x,y;
		
		//jogada do p1
		printf("Player1 ,where you want to shoot?\n");

		p = new_point(get_map_size(s));
		x = get_x(p);
		y = get_y(p);

		// '0' celula que tem como estado agua
		// '1' celula que tem como estado peça por acertar
		// '2' celula que tem como estado peça que ja foi acertada
		// '3' celula que tem como estado tiro sobre agua
		//ciclo para verificar o estado das celulas do mapa do jogador 2
		while(s->p2->field[y][x]->state == '2' || s->p2->field[y][x]->state == '3'){
			print_field_s(s->p2,get_map_size(s));
			printf("You have already shotted at this position\n");
			p = new_point(get_map_size(s));
		}
		if(s->p2->field[y][x]->state == '0'){
			printf("You haven't hitted a piece\n");
			s->p2->field[y][x]->state = '3';
		}
		else if(s->p2->field[y][x]->state == '1'){
			printf("You have hitted a piece\n");
			s->p2->field[y][x]->state = '2';
			s->p2->field[y][x]->boat_pointer = NULL;
			set_hp(s->p2,-1);
		}
		print_field_p(s->p2,get_map_size(s));
		print_field_s(s->p2,get_map_size(s));
		
		//jogada do p2
		printf("Player 2, where you want to shoot?\n");
		p = new_point(get_map_size(s));
		x = get_x(p);
		y = get_y(p);
		
		//mesmo ciclo descrito acima mas agora para o jogador 1
		while(s->p1->field[y][x]->state == '2' || s->p1->field[y][x]->state == '3'){
			print_field_s(s->p1,get_map_size(s));
			printf("You have already shotted at this position\n");
			p = new_point(get_map_size(s));
		}
		if(s->p1->field[y][x]->state == '0'){
			printf("You haven't hitted a piece\n");
			s->p1->field[y][x]->state = '3';
		}
		else if(s->p1->field[y][x]->state == '1'){
			printf("You have hitted a piece\n");
			s->p1->field[y][x]->state = '2';
			set_hp(s->p1,-1);
		}
		print_field_p(s->p2,get_map_size(s));
		print_field_s(s->p1,get_map_size(s));
	}
	if(s->p1->hp == 0){
		g->winner = '2';
	}
	else{
		g->winner = '1';
	}
	return g;

	free(p);
}
GAME* play_game_q(SETUP* s){

	GAME* g = new_game();
	POINT* p;
	
	while(s->p1->hp != 0 && s->p2->hp != 0){

		int side;
		QD_NODE* qd_node;
		POINT* se_corner;
		
		//jogada do p1
		printf("Player1 ,where you want to shoot?\n");

		p = new_point(get_map_size(s));

		if(get_map_size(s) <= 32) side = 32;
		else side = 64;

		se_corner = make_point(side,side);

		qd_node = search(qd_node, p,se_corner,side);
		if(qd_node == NULL){
			printf("You haven't hitted a piece\n");
		}
		else{
			printf("You have hitted a piece\n");
			change_field_pointer(qd_node);
			set_hp(s->p2,-1);
		}
		
		print_field_q(s->p2,get_map_size(s));

		//jogada do p2
		printf("Player 2, where you want to shoot?\n");
		p = new_point(get_map_size(s));

		if(get_map_size(s) <= 32) side = 32;
		else side = 64;

		se_corner = make_point(side,side);

		qd_node = search(qd_node, p,se_corner,side);
		if(qd_node == NULL){
			printf("You haven't hitted a piece\n");
		}
		else{
			printf("You have hitted a piece\n");
			change_field_pointer(qd_node);
			set_hp(s->p2,-1);
		}

		print_field_q(s->p2,get_map_size(s));

	}
	if(s->p1->hp == 0){
		g->winner = '2';
	}
	else{
		g->winner = '1';
	}
	return g;
}