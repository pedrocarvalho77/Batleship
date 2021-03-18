#include "setup.h"

SETUP* setup_input(){

	SETUP* s = new_setup();

	set_type_of_game(s);
	set_type_of_storage(s);
	set_map_size(s);
	set_max_numb_boats(s);

	s->p1 = new_player(1,get_map_size(s));
	s->p2 = new_player(2,get_map_size(s));
	
	print_map_size(s);
	print_max_numb_boats(s);

	if(get_type_of_game(s) == 'R'){
		rnd_setup(s,s->p1,s->p2);
	}
	else{
		man_setup(s,s->p1,s->p2);
	}
	return s;
}
SETUP* new_setup(){

	SETUP* s;
	s = (SETUP*) malloc(sizeof(SETUP));
	if(s == NULL){
		printf("Error\n");
		exit(0);
	}
	return s;
}
void rnd_setup(SETUP* s, PLAYER* p1,PLAYER* p2){
	
	set_numb_boat_type(s);

	print_numb_boat_type(s);

	get_rnd_boats(p1,s);
	get_rnd_boats(p2,s);
}
void man_setup(SETUP* s, PLAYER* p1,PLAYER* p2){

	set_numb_boat_type(s);

	print_numb_boat_type(s);
	
	get_boats(p1,s);
	get_boats(p2,s);

}
void set_type_of_game(SETUP* s){
	
	printf("Random or manual setup?\n");
	printf("Insert 'R' for random or 'M' for manual\n");
	s->type_of_game = getchar();

	while(s->type_of_game != 'R' && s->type_of_game != 'M'){
		printf("Wrong type of game, insert 'R' for random 'M' for manual\n");
		getchar();
		s->type_of_game = getchar();
	}
}
void set_type_of_storage(SETUP* s){

	printf("QuadTree or Array?\n");
	printf("Insert 'Q' for QuadTree or 'A' for Array\n");
	
	while(getchar() == '\0');
	
	s->type_of_storage = getchar();

	while(s->type_of_storage != 'Q' && s->type_of_storage != 'A'){
		printf("Wrong type of storage, insert 'Q' for QuadTree 'A' for Array\n");
		getchar();
		s->type_of_storage = getchar();
	}
}
void set_map_size(SETUP* s){

	if(get_type_of_game(s) == 'M'){
		printf("Insert size of the map between 20 and 40\n");
		scanf("%d", &s->map_size);
		//ADICIONAR IS DIGIT
		while(s->map_size<20 || s->map_size>40){
			printf("Wrong size, insert again\n");
			scanf("%d", &s->map_size);
		}
	}
	else{
		set_rnd_map_size(s);
	}
}
void set_rnd_map_size(SETUP* s){
	s->map_size = rnd_map_size();
}
void set_max_numb_boats(SETUP* s){
	s->max_numb_boat = (s->map_size*s->map_size/25);
}
//função para definir o numero de barcos para cada tipo
void set_numb_boat_type(SETUP* s){

	char* boat_type;
	int num = 0;
	int total_boats = 0;
	int max_bound = get_max_numb_boats(s)-4;

	boat_type = (char*) malloc(sizeof(char));
	for(int i=0; i<5;i++){
		
		strcpy(boat_type,int_to_char(i));
		
		printf("Insert a nº between %d and %d for boat's of type ", 1, max_bound);
		print_boat_type(boat_type);
		scanf("%d", &num);
		while(num <= 0 || num > max_bound){
			printf("Insert again a Numb between %d and %d\n", 1, max_bound);
			scanf("%d",&num);
		}
		if(max_bound == num){
			max_bound = 1;
		}else{
			max_bound = max_bound-num;
		}
		total_boats = total_boats + num;
		printf("Total number of boats yet: %d\n", total_boats);
		switch(i){
			case 0:
				s->numb_boat_T=num;
				break;
			case 1:
				s->numb_boat_U=num;
				break;
			case 2:
				s->numb_boat_II=num;
				break;
			case 3:
				s->numb_boat_I=num;
				break;
			case 4:
				s->numb_boat_L=num;
				break;
			default:
				break;
		}
	}
	set_total_numb_boat(s,total_boats);
}

//função para de definir aleatoriamente o numero de barcos para cada tipo
void set_rnd_numb_boat_type(SETUP* s){

	char* boat_type;
	int num = 0;
	int total_boats = 0;
	int max_bound = get_max_numb_boats(s)-4;
	
	boat_type = (char*) malloc(sizeof(char));
	for(int i=0; i<5; i++){

		strcpy(boat_type,int_to_char(i));
		num = rnd_numb_noat(max_bound);
		if(num > (get_max_numb_boats(s)/2)){
			num = rnd_numb_noat(max_bound);
		}
		printf("%d boat's of type ", num);
		print_boat_type(boat_type);
		if(max_bound == num){
			max_bound = 1;
		}
		else{
			max_bound = max_bound - num;
		}
		total_boats = total_boats + num;
		printf("Total number of boats yet: %d\n", total_boats);
		switch(i){
			case 0:
				s->numb_boat_T=num;
				break;
			case 1:
				s->numb_boat_U=num;
				break;
			case 2:
				s->numb_boat_II=num;
				break;
			case 3:
				s->numb_boat_I=num;
				break;
			case 4:
				s->numb_boat_L=num;
				break;
			default:
				break;
		}
	}	
	set_total_numb_boat(s,total_boats);
}
void set_total_numb_boat(SETUP* s, int total){
	s->total_numb_boat = total;
}
int get_type_of_game(SETUP* s){
	return s->type_of_game;
}
int get_map_size(SETUP*s){
	return s->map_size;
}
int get_max_numb_boats(SETUP*s){
	return s->max_numb_boat;
}
int get_numb_boat_type(SETUP* s, char* boat_type){
	
	if(strcmp(boat_type,"T") == 0){
		return s->numb_boat_T;
	}
	else if(strcmp(boat_type,"U") == 0){
		return s->numb_boat_U;
	}
	else if(strcmp(boat_type,"||") == 0){
		return s->numb_boat_II;
	}
	else if(strcmp(boat_type,"|") == 0){
		return s->numb_boat_I;	
	}
	else if(strcmp(boat_type,"L") == 0){
		return s->numb_boat_L;
	}
	return -1;
}
int get_total_numb_boat(SETUP* s){
	return s->total_numb_boat;
}

//funçao que obtem coordenadas aleatorias para os barcos

void get_rnd_boats(PLAYER* pl ,SETUP* s){

	POINT* p;
	BOAT* b;
	char* boat_type;
	int numb_boat_type = 0;
	int rotation = 0;
	int aux_p = 0;
	
		boat_type = (char*) malloc(sizeof(char));
		printf("Generating boats for the player %d\n", get_id(pl));

		for(int i=0; i<5; i++){
			
			strcpy(boat_type,int_to_char(i));
			numb_boat_type = get_numb_boat_type(s,boat_type);
			
			printf("Player %d has %d boats type ",get_id(pl),numb_boat_type);
			print_boat_type(boat_type);

			for(int j=0;j<numb_boat_type;j++){

				b = new_boat(boat_type);
				p = rnd_point(get_map_size(s));
				rotation = rnd_rotation();
				
				for(int i=0; i<rotation; i++){
					rotate_boat(b);
				}
				if(s->type_of_storage == 'A'){
					aux_p = has_boat_a(p,pl,get_map_size(s),b);

					while(aux_p == 1 || aux_p == 2){	
						
						p = rnd_point(get_map_size(s));
						rotation = rnd_rotation();
						for(int i=0; i<rotation; i++){
							rotate_boat(b);
						}
						aux_p = has_boat_a(p,pl,get_map_size(s),b);
					}
				}
				else{
					aux_p = has_boat_q(p,pl,get_map_size(s),b);

					while(aux_p == 1 || aux_p == 2){	
						
						p = rnd_point(get_map_size(s));
						rotation = rnd_rotation();
						for(int i=0; i<rotation; i++){
							rotate_boat(b);
						}
						aux_p = has_boat_q(p,pl,get_map_size(s),b);
					}
				}
				aux_p = 0;
				print_boat(b);
				print_point(p);
			if(s->type_of_storage == 'A'){
				place_boat_a(b,pl,p,get_map_size(s));
			}
			else{
				place_boat_q(b,pl,p,get_map_size(s));
			}
				print_field_p(pl,get_map_size(s));
			}
		}

}

//função para obter coordenadas para os barcos

void get_boats(PLAYER* pl, SETUP* s){
	
	POINT* p;
	BOAT* b;
	char* boat_type;
	int numb_boat_type = 0;
	int rotation = 0;
	int aux_p = 0;

	boat_type = (char*) malloc(sizeof(char));

	printf("\nPlayer %d, place your boats\n", get_id(pl));
	printf("Player %d, has %d boats type ",get_id(pl), numb_boat_type);
	print_boat_type(boat_type);

	for(int i=0; i<5; i++){
		strcpy(boat_type,int_to_char(i));
		numb_boat_type = get_numb_boat_type(s,boat_type);
		for(int j=0;j<numb_boat_type;j++){

			b = new_boat(boat_type);		
			printf("Where do you want to place boat number %d of type ", (j+1));
			print_boat_type(boat_type);
			
			p = new_point(get_map_size(s));
			
			printf("What rotation do you want for the boat, 0º,90º,180º,270º, 360º?\n");
			scanf("%d", &rotation);
			
			while(rotation != 0 && rotation != 90 && rotation != 180 && rotation != 270 && rotation != 360){
				printf("Impossible rotation, insert again\n");
				scanf("%d", &rotation);
			}
			rotation = rotation/90;
			for(int i=0; i<rotation; i++){
				rotate_boat(b);
			}

			if(s->type_of_storage == 'A'){
				aux_p = has_boat_a(p,pl,get_map_size(s),b);
				
				while(aux_p == 1 || aux_p == 2){	
					if(aux_p == 1){
						printf("You already have a boat in that position, insert again\n");
					}
					else{
						printf("Outside the map boundaries, enter again\n");	
					}
					p = new_point(get_map_size(s));
					printf("What rotation do you want for the boat, 0º,90º,180º,270º,360º?\n");
					scanf("%d", &rotation);
				
					while(rotation != 0 && rotation != 90 && rotation != 180 && rotation != 270 && rotation != 360){
						printf("mpossible rotation, insert again\n");
						scanf("%d", &rotation);
					}
					rotation = rotation/90;
					for(int i=0; i<rotation; i++){
						rotate_boat(b);
					}
					aux_p = has_boat_a(p,pl,get_map_size(s),b);
				}
			}
			else{
				aux_p = has_boat_q(p,pl,get_map_size(s),b);
				while(aux_p == 1 || aux_p == 2){	
					if(aux_p == 1){
						printf("You already have a boat in that position, insert again\n");
					}
					else{
						printf("Outside the map boundaries, enter again\n");	
					}
					p = new_point(get_map_size(s));
					printf("What rotation do you want for the boat, 0º,90º,180º,270º,360º?\n");
					scanf("%d", &rotation);
				
					while(rotation != 0 && rotation != 90 && rotation != 180 && rotation != 270 && rotation != 360){
						printf("mpossible rotation, insert again\n");
						scanf("%d", &rotation);
					}
					rotation = rotation/90;
					for(int i=0; i<rotation; i++){
						rotate_boat(b);
					}
					aux_p = has_boat_q(p,pl,get_map_size(s),b);
				}
			}
			print_boat(b);
			aux_p = 0;
			if(s->type_of_storage == 'A'){
				place_boat_a(b,pl,p,get_map_size(s));
			}
			else{
				place_boat_q(b,pl,p,get_map_size(s));
			}
				print_field_p(pl,get_map_size(s));
		}
	}
}

//funçao para verificar se é possivel colocar o barco na posição pretendida

int has_boat_a(POINT* p, PLAYER* pl, int map_size, BOAT* b){

	int x = get_x(p);
	int y = get_y(p);
	for(int i=0;i<5; i++){
		for(int j=0;j<5;j++){
			if(y+i >= map_size || x+j >= map_size){
				return 2;
			}
			if(pl->field[y+i][x+j]->boat_pointer != NULL){
				return 1;
			}
		}
	}
	return 0;
}

int has_boat_q(POINT* p, PLAYER* pl, int map_size, BOAT* b){

	int side;
	int x; 
	int y;
	
	QD_NODE* qd_node;
	POINT* se_corner;
	POINT* aux_p;

	x = get_x(p);
	y = get_y(p);

	if(map_size <= 32) side = 32;
	else side = 64;
	
	se_corner = make_point(side,side);
	aux_p = make_point(x,y);

	for(int i=0;i<5; i++){
		for(int j=0;j<5;j++){
			qd_node = search(qd_node, aux_p,se_corner,side);
			if(y+i >= map_size || x+j >= map_size){
				return 2;
			}
			if(qd_node != NULL && b->bitmap[i][j] == '1'){
				return 1;
			}
		}
	}
	return 0;
}

//função para colocar os marcos no mapa de cada jogador
void place_boat_a(BOAT* b, PLAYER* pl, POINT* p,int map_size){
	
	int x = get_x(p);
	int y = get_y(p);
	int max_x;
	int max_y;
	if(x>=(map_size-5) || y>=(map_size-5)){
		max_x = map_size-x;
		max_y = map_size-y;
	}
	else{
		max_x = 5;
		max_y = 5;
	}
	for(int i=0; i<max_y;i++){
		x = get_x(p);
		for(int j=0; j<max_x; j++){
			if(b->bitmap[i][j] == '1'){
				pl->field[y][x]->boat_pointer = b;
				pl->field[y][x]->state = '1';
			}
			x++;
		}
		y++;
	}
	if(strcmp(b->type,"T") == 0){
		set_hp(pl,9);
	}
	else if(strcmp(b->type,"U") == 0){
		set_hp(pl,13);
	}
	else if(strcmp(b->type,"||") == 0){
		set_hp(pl,10);
	}
	else if(strcmp(b->type,"|") == 0){
		set_hp(pl,5);
	}
	else if(strcmp(b->type,"L") == 0){
		set_hp(pl,9);
	}
}
void place_boat_q(BOAT* b, PLAYER* pl, POINT* p, int map_size){

	int side;
	int x = get_x(p);
	int y = get_y(p);
	POINT* se_corner;
	POINT* aux_p;
	if(map_size <= 32) side = 32;
	else side = 64;
	
	aux_p = make_point(0,0);
	se_corner = make_point(side,side);
	
	for(int i=0; i<5; i++){
		set2_x(aux_p,x+i);
		for(int j=0; j<5; j++){
			set2_y(aux_p,y+j);
			if(b->bitmap[i][j] == '1'){
				insert(pl->qtree, aux_p, se_corner, side);
			}
		}
	}

	if(strcmp(b->type,"T") == 0){
		set_hp(pl,9);
	}
	else if(strcmp(b->type,"U") == 0){
		set_hp(pl,13);
	}
	else if(strcmp(b->type,"||") == 0){
		set_hp(pl,10);
	}
	else if(strcmp(b->type,"|") == 0){
		set_hp(pl,5);
	}
	else if(strcmp(b->type,"L") == 0){
		set_hp(pl,9);
	}
}
int rnd_map_size(){
	return (20 + rand() % 21);
}
int rnd_numb_noat(int max){
	return (1 + rand() % max);
}
void print_map_size(SETUP* s){
	printf("The map has a size of [%dx%d]\n", get_map_size(s),get_map_size(s));
}
void print_max_numb_boats(SETUP* s){
	printf("This game has a maximum of %d boats\n", get_max_numb_boats(s));
}
void print_numb_boat_type(SETUP* s){

	for(int i=0; i<5; i++){
		printf("\nHas a total of %d boats of type ", get_numb_boat_type(s,int_to_char(i)));
		print_boat_type(int_to_char(i));
	}
}