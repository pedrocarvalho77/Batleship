#ifndef POINT_H
#define POINT_H

#include <stdlib.h>
#include <stdio.h>

//struct do tipo coordenada
typedef struct{
							 
	int x;	//cordenada x 			
	int y;	//cordenada y	 	
						
} POINT;

//assinatura da funções para criar coordenadas

POINT* new_point(int);
void set_x(POINT*,int);
void set_y(POINT*,int);
void set2_x(POINT* p, int x);
void set2_y(POINT* p, int y);

int get_x(POINT*);
int get_y(POINT*);

//função que retorna uma coordenada dentro do tamanho do mapa

POINT* rnd_point(int);

POINT* make_point(int,int);
POINT* add_point(POINT* p, POINT* q);
int is_equal(POINT* p,POINT* q); 
int in_square(POINT* p, POINT* corner, int side); //verifica se p está no quadrado definido por (corner,side)

void print_point(POINT*);

#endif