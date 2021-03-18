#ifndef PLAYER_H
#define	PLAYER_H

#include "cell.h"
#include "quadtree.h"

typedef struct {

	int id;
	int hp;
	CELL*** field;
	QD_NODE* qtree;

} PLAYER;

//assinatura da função para criar um jogador
PLAYER* new_player(int,int);

void set_id(PLAYER*,int);
void set_hp(PLAYER*,int);
void set_field(PLAYER*,int);

int get_id(PLAYER*);
int get_hp(PLAYER*); 

void print_id(PLAYER*);

void print_field_q(PLAYER*,int);
void print_field_s(PLAYER*,int);
void print_field_p(PLAYER*,int);

#endif