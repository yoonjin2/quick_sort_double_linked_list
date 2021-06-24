#include <stdio.h>
#include <stdlib.h>
#include "list.h"
// add number between two nodes
void between( list * lst , int item , node * b , node * n ) {
    node * element ;
    if ( ( element = ( node * ) malloc ( sizeof ( node ) ) ) == NULL ) {
        return ;
	}
	if ( ( b != n -> prev ) ) {
		free( element );
		return ;
	}
    else {
        element -> key = item ;
        b -> next = element ;
        element -> prev = b;
        element -> next = n ;
		n -> prev = element ;
    }
    lst -> size ++ ;
}
void push ( list * lst , int item ) {
	between ( lst , item , lst -> rear -> prev , lst -> rear ) ;
}
