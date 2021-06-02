#include <stdlib.h>
#include "queue.h"
// function that empties queue
void empty_queue ( queue * que ) {
    node * q = que -> front -> next ; // queue is first value, that is next of the front node
    while ( q != que -> rear ) { // while queue is not rear node
        free ( q ) ; // free the queue
        q = q -> next ; // go to the next node
    }
	que -> front -> next = que -> rear ;
	que -> rear -> prev = que -> front ;
    que -> size = 0 ;
}
void free_queue ( queue * que ) { // freeing the queue
    empty_queue ( que ) ; // first, clear the queue
    free ( que -> front ) ; // free the queue -> front
    free ( que -> rear ) ; // free the queue -> rear
}
