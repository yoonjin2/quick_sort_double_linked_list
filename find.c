#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
node * find ( queue * que, int key ) {
	node * err;
	if ( ( err = ( node * ) malloc ( sizeof ( node ) ) ) == NULL ) {
		printf("Can't return ERROR NODE") ;
		exit ( 1 );
	}
	err -> key = -1;
	node * p = que -> front -> next ;
	while ( p -> key != key ) {
		p = p -> next ;
	}
	if ( p == que -> rear ) {
		return err ;
	}
	return p;
}
