#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <time.h>
int main()
{
	srand ( time ( NULL ) ) ;
    list lst;
    init_list ( &lst ); //init list
    int i , key[NUM] ;
	for ( i = 0 ; i < NUM ; i ++ ) {
	//	key[i] =i;
		key[i] = ( rand () % LIM ) + 1 ;
	}
	for ( i = 0 ; i < NUM ; i ++ ) {
		swap ( &key [ rand () % NUM ], &key [ rand () % NUM ] ); 
	}
	for ( i = 0 ; i < NUM ; i ++ ) {
		between ( &lst, key[i], lst.rear->prev , lst.rear );
	}
	show ( &lst ); // unsorted linked list
	puts( "\n\n" );
	sort_func ( &lst ) ;
	show( &lst ); // sorted linked list
	free_list ( &lst ) ;
    return 0;
}
