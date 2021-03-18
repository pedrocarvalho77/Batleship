#include "point.h"

POINT* new_point(int map_size){
	
	POINT* p = (POINT*) malloc(sizeof(POINT));
	if(p == NULL){
		printf("Error\n");
		exit(0);
	}
	printf("Insert x between 0 and %d: ", (map_size-1));
	set_x(p,map_size-1);
	printf("Insert y between 0 and %d: ", (map_size-1));
	set_y(p,map_size-1);
	
	return p;
}
void set_x(POINT* p, int map_size){
	
	scanf("%d",&p->x);
	while(p->x<0 || p->x>map_size){
		printf("x:");
		scanf("%d",&p->x);
	}
}
void set_y(POINT* p, int map_size){	
	
	scanf("%d",&p->y);
	while(p->y<0 || p->y>map_size){
		printf("y:");
		scanf("%d",&p->y);
	}
}
void set2_x(POINT* p, int x){
	p->x = x;
}
void set2_y(POINT* p, int y){
	p->y = y;
}
int get_x(POINT* p){
	return p->x;
}
int get_y(POINT* p){
	return p->y;
}
POINT* rnd_point(int map_size){

	POINT* p = (POINT*) malloc(sizeof(POINT));
	if(p == NULL){
		printf("Error\n");
		exit(0);
	}
	p->x = rand() % map_size;
	p->y = rand() % map_size;

	return p;
}
void print_point(POINT* p){

	printf("(x,y) = (%d,%d)\n", p->x,p->y);
}

POINT* make_point(int x,int y){

	POINT* p = (POINT*) malloc(sizeof(POINT));
	if(p == NULL){
		printf("Error\n");
		exit(0);
	}
	p->x=x;
	p->y=y;

	return p;
}
POINT* add_point(POINT* p, POINT* q){

	POINT* r;
	int x;
	int y;

	x = get_x(p) + get_x(q);
	y = get_y(p) + get_y(q);

	r = make_point(x,y);

	return r; 
}

int is_equal(POINT* p,POINT* q){

	if(get_x(p) == get_x(q) && get_y(p) == get_y(q)){
		return 1;
	}
	return 0;
}

int in_square(POINT* p, POINT* corner, int side){

	if(get_x(p) < get_x(corner) || get_y(p) < get_y(corner)){
		return 0;
	}
	if(get_x(p) > (get_x(corner) + side) || get_y(p) > (get_y(corner) + side)){
		return 0;
	}
	return 1;
}