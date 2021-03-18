#include "quadtree.h"

QD_NODE* new_qd_node(QD_TNODE  type){

	QD_NODE* qd_node = (QD_NODE*) malloc(sizeof(QD_NODE));

    if(qd_node == NULL){
        printf("Error\n");
        exit(0);
    }
	qd_node->type = type;

    return qd_node;
}

QD_NODE* search(QD_NODE* qtree, POINT* p, POINT* se_corner, int side){

    POINT* newcorner;
    POINT* mi = make_point(get_x(se_corner) - side/2, get_y(se_corner) - side/2);
	
    if(qtree == NULL) return NULL;

        if(in_square(p, se_corner,side) == 1){
            newcorner = make_point(get_x(se_corner),get_y(mi));
            if(in_square(p, newcorner,side/2) == 1){
                return search(qtree->node.quadrants[0], p, newcorner, side/2);
		    }
            
            newcorner = make_point(get_x(mi),get_y(mi));
            if(in_square(p, newcorner,side/2) == 1){
                return search(qtree->node.quadrants[1], p, newcorner, side/2);
            }
            
            newcorner = make_point(get_x(mi),get_y(se_corner));
            if(in_square(p, newcorner,side/2) == 1){
                return search(qtree->node.quadrants[2], p, newcorner, side/2);
            }
            
            newcorner = make_point(get_x(se_corner),get_y(se_corner));
            if(in_square(p, newcorner,side/2) == 1){
                return search(qtree->node.quadrants[3], p, newcorner, side/2);
            }
            return qtree;
        }
    return NULL;
}

int insert(QD_NODE* qtree, POINT* p, POINT* se_corner, int side){

    CELL* c;
    POINT* newcorner;
    POINT* mi = make_point(get_x(se_corner) - side/2, get_y(se_corner) - side/2);

        if(in_square(p, se_corner,side) == 1){
            newcorner = make_point(get_x(se_corner),get_y(mi));
            if(in_square(p, newcorner,side/2) == 1){
                if(qtree->node.quadrants[0] == NULL){
                    qtree->node.quadrants[0] = new_qd_node(QDNODE);
                }
                return insert(qtree->node.quadrants[0], p, newcorner, side/2);
            }
            
            newcorner = make_point(get_x(mi),get_y(mi));
            if(in_square(p, newcorner,side/2) == 1){
                if(qtree->node.quadrants[1] == NULL){
                     qtree->node.quadrants[1] = new_qd_node(QDNODE);
                }
                return insert(qtree->node.quadrants[1], p, newcorner, side/2);
            }
            
            newcorner = make_point(get_x(mi),get_y(se_corner));
            if(in_square(p, newcorner,side/2) == 1){
                if(qtree->node.quadrants[2] == NULL){
                     qtree->node.quadrants[2] = new_qd_node(QDNODE);
                }
                return insert(qtree->node.quadrants[2], p, newcorner, side/2);
            }
            
            newcorner = make_point(get_x(se_corner),get_y(se_corner));
            if(in_square(p, newcorner,side/2) == 1){
                if(qtree->node.quadrants[3] == NULL){
                    qtree->node.quadrants[3] = new_qd_node(QDNODE);
                }
                return insert(qtree->node.quadrants[3], p, newcorner, side/2);
            }
            qtree->type = QDLEAF;
            qtree->node.leaf.p = p;
            c = new_cell();
            set_state(c,'1');
            qtree->node.leaf.field_pointer = c;
            return 1;
        }
    return 0;
}

int change_field_pointer(QD_NODE* qtree){

    if(qtree == NULL) return 0;
    qtree->node.leaf.field_pointer->state= 3;
    return 1;
}