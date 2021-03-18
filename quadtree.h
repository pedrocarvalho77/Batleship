#ifndef	QUADTREE_H
#define QUADTREE_H

#include "cell.h"

typedef enum { QDNODE, QDLEAF} QD_TNODE;

typedef struct QD_Node_ {
  QD_TNODE  type;
                                       
  union {

    struct QD_Node_ *quadrants[4];                                              

    struct {

    	CELL* field_pointer;                           

     	POINT* p;                                                        

    } leaf;

  } node;

} QD_NODE;

QD_NODE* new_qd_node();
QD_NODE* search(QD_NODE*, POINT* , POINT*, int);
int insert(QD_NODE*, POINT*, POINT*, int);
int change_field_pointer(QD_NODE*);


#endif