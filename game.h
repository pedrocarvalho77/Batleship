#ifndef GAME_H
#define	GAME_H

#include "setup.h"

typedef struct{

	char winner;

} GAME;

GAME* new_game();

void set_winner(GAME*,char);

char get_winner(GAME*);

GAME* play_game_a(SETUP*);
GAME* play_game_q(SETUP*);

#endif