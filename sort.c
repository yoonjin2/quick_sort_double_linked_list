#include "list.h"
#include <stdlib.h>
//quick sort function
void sort_func ( list * lst , int pivot ) {
	
	if ( lst -> size < 2 ) {
		return;
	}

	auto int i;

	auto list llst, rlst ;
	init_list ( &llst );
	init_list ( &rlst );
	node * piv = lst -> front -> next, * track = lst -> front -> next ;
	for ( i = 0 ; i < pivot ; i ++ ) {
		if ( piv == lst -> rear -> prev )
			break;
		piv = piv -> next ;
	}
	int k = piv -> key ;
	for ( i = 0 ; i < lst -> size ; i ++ ) {
		if ( track == lst -> rear ) {
			break;
		}
		if ( piv  == track ) {
			track = track -> next ;
			continue;
		}
		if ( track -> key < piv -> key ) {
			between ( &llst , track -> key , llst.rear -> prev , llst.rear ) ;
		} else {
			between ( &rlst , track -> key , rlst.rear -> prev , rlst.rear ) ;
		}
		track = track -> next ;
	}
	empty_list( lst );
	if ( llst.size > 1 ) {
		sort_func ( &llst , llst.size / 2  ) ;
	}
	if ( rlst.size > 1 ) {
		sort_func ( &rlst , rlst.size / 2 ) ;
	}
	if ( llst.size > 0 ) {
		track = llst.front -> next ;
		for ( i = 0 ; i < llst.size ; i ++ ) {
			if ( track == llst.rear ) {
			break;
			}
			between ( lst , track -> key , lst -> rear -> prev, lst -> rear );
			track = track -> next ;
		} 
	}
	between ( lst , k , lst -> rear -> prev , lst -> rear );
	if ( rlst.size > 0 ) {
		track = rlst.front -> next ;
		for ( i = 0 ; i < rlst.size ; i ++ ) {
			if ( track == rlst.rear ) {
				break;
			}

			between ( lst , track -> key , lst -> rear -> prev , lst -> rear );
			track = track -> next ;
		}
	}
}
