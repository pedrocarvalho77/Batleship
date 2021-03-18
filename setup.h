#ifndef SETUP_H
#define	SETUP_H

#include "player.h"

typedef struct{

	char type_of_storage;
	char type_of_game;
	int map_size;
	int max_numb_boat; //int para o numero maximo de barcos possiveis tendo em conta a dimensao do mapa
	int numb_boat_T;
	int numb_boat_U;
	int numb_boat_II;
	int numb_boat_I;
	int numb_boat_L;
	int total_numb_boat; //numero total de numeros de barcos de todos tipos
	PLAYER* p1;
	PLAYER* p2;

} SETUP;

SETUP* setup_input();

SETUP* new_setup();

void rnd_setup(SETUP*,PLAYER*,PLAYER*);
void man_setup(SETUP*,PLAYER*,PLAYER*);

void set_type_of_game(SETUP*);
void set_type_of_storage(SETUP* s);
void set_map_size(SETUP*);
void set_rnd_map_size(SETUP*);
void set_max_numb_boats(SETUP*);
void set_numb_boat_type(SETUP*);
void set_rnd_numb_boat_type(SETUP*);
void set_total_numb_boat(SETUP*,int);

int get_type_of_game(SETUP*);
int get_map_size(SETUP*);
int get_max_numb_boats(SETUP*);
int get_numb_boat_type(SETUP*,char*);
int get_total_numb_boat(SETUP*);

void get_rnd_boats(PLAYER*,SETUP*);
void get_boats(PLAYER*,SETUP*);

int has_boat_a(POINT*,PLAYER*,int,BOAT*);
int has_boat_q(POINT*,PLAYER*,int,BOAT*);

void place_boat_a(BOAT*,PLAYER*,POINT*,int);
void place_boat_q(BOAT*,PLAYER*,POINT*,int);

int rnd_map_size();
int rnd_numb_noat(int);

void print_map_size(SETUP*);
void print_max_numb_boats(SETUP*);
void print_numb_boat_type(SETUP*);

#endif