#include <stdlib.h>
#include "queue.h"

void init_queue ( queue * que ) { // init queue
    que -> front = ( node * ) malloc ( sizeof ( node ) ) ;
    que -> rear = ( node * ) malloc( sizeof ( node ) );
    que -> front -> next = que -> rear ;
    que -> front -> prev = que -> front ;
    que -> rear -> next = que -> rear ;
    que -> rear -> prev = que -> front ;
    que -> size = 0 ;
}
