#include <stdio.h>
#include "queue.h"
//show queue
void show(queue *que) {
    node * t = que -> front -> next;
	auto int i;
    for ( i = 0 ; i < que -> size ; i ++ ) {
        printf ( "%d\n" , t -> key ) ;
        t = t -> next ;
    }
}
