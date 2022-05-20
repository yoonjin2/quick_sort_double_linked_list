#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>
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
	if ( lst -> size != 0 )	{
		if ( lst -> rear -> prev -> key > item ) {
			lst -> is_sorted = false;
		} 
	}	
	between ( lst , item , lst -> rear -> prev , lst -> rear ) ;
}
void regen_sorted ( list * lst ) {
	node *p;
	for ( p = lst -> front -> next; p != lst -> rear -> prev ; p = p -> next ) {
		if ( p -> key > p -> next -> key ) {
			lst -> is_sorted = false ;
			return ;
		}
	}
	lst -> is_sorted = true;
}
