#include <stdio.h>
#include "list.h"
//show list
void show( list *lst ) {
    node * t = lst -> front -> next;
	register int i;
    for ( i = 0 ; i < lst -> size ; i ++ ) {
        printf ( "%d\n" , t -> key ) ;
        t = t -> next ;
    }
}
