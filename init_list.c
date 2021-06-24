#include <stdlib.h>
#include "list.h"

void init_list ( list * lst ) { // init list
    lst -> front = ( node * ) malloc ( sizeof ( node ) ) ;
    lst -> rear = ( node * ) malloc( sizeof ( node ) );
    lst -> front -> next = lst -> rear ;
    lst -> front -> prev = NULL ;
    lst -> rear -> next = NULL ;
    lst -> rear -> prev = lst -> front ;
    lst -> size = 0 ;
}
