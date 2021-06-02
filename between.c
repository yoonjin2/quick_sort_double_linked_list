#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
// add number between two nodes
void between( queue * que , int item , node * b , node * n) {
    node * q ;
    if ( ( q = ( node * ) malloc ( sizeof ( node ) ) ) == NULL ) {
        return ;
	}
	if ( ( b != n -> prev ) ) {
		return ;
	}
    else {
        q -> key = item ;
        b -> next = q ;
        q -> prev = b;
        q -> next = n ;
		n -> prev = q ;
    }
    que -> size ++ ;
}
