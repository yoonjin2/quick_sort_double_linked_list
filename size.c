#include <stdio.h> 
#include "queue.h"
#include <stdbool.h>

// return size of queue
int size( queue * que ) {
	return que -> size ;
}

// check if queue is empty
bool empty ( queue * que ) {
    if ( que -> size == 0 ) {
        return true ;
	}

    else {
        return false ;
	}
}
