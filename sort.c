#include "queue.h"
#include <stdlib.h>
//quick sort function
void sort_func ( queue * que , int pivot ) {
	
	if ( que -> size < 2 ) {
		return;
	}

	auto int i;

	auto queue lque, rque ;
	init_queue ( &lque );
	init_queue ( &rque );
	node * piv = que -> front -> next, * track = que -> front -> next ;
	for ( i = 0 ; i < pivot ; i ++ ) {
		if ( piv == que -> rear -> prev )
			break;
		piv = piv -> next ;
	}
	int k = piv -> key ;
	for ( i = 0 ; i < que -> size ; i ++ ) {
		if ( track == que -> rear ) {
			break;
		}
		if ( piv  == track ) {
			track = track -> next ;
			continue;
		}
		if ( track -> key < piv -> key ) {
			between ( &lque , track -> key , lque.rear -> prev , lque.rear ) ;
		} else {
			between ( &rque , track -> key , rque.rear -> prev , rque.rear ) ;
		}
		track = track -> next ;
	}
	empty_queue( que );
	if ( lque.size > 1 ) {
		sort_func ( &lque , lque.size / 2  ) ;
	}
	if ( rque.size > 1 ) {
		sort_func ( &rque , rque.size / 2 ) ;
	}
	if ( lque.size > 0 ) {
		track = lque.front -> next ;
		for ( i = 0 ; i < lque.size ; i ++ ) {
			if ( track == lque.rear ) {
			break;
			}
			between ( que , track -> key , que -> rear -> prev, que -> rear );
			track = track -> next ;
		} 
	}
	between ( que , k , que -> rear -> prev , que -> rear );
	if ( rque.size > 0 ) {
		track = rque.front -> next ;
		for ( i = 0 ; i < rque.size ; i ++ ) {
			if ( track == rque.rear ) {
				break;
			}

			between ( que , track -> key , que -> rear -> prev , que -> rear );
			track = track -> next ;
		}
	}
}
