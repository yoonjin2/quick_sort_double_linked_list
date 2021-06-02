#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int remove_item ( queue * que , node * q )
{	
	int val;
    if ( que -> size == 0 ) {
        val = -1;
    } else {
		node * x = q -> next;
		node *y = q -> prev ;
        x -> prev = y;
		y -> next = x; 
		val = q -> key ;
        free ( q ) ;
        que -> size -- ;
    }
	return val ;
}
