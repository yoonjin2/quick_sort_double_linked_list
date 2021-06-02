#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include <time.h>
int main()
{
	srand ( time ( NULL ) ) ;
    queue que;
    init_queue ( &que ); //init queue
    int i , key[NUM] ;
	for ( i = 0 ; i < NUM ; i ++ ) {
	//	key[i] =i;
		key[i] = ( rand () % LIM ) +1 ;
	}
	for ( i = 0 ; i < NUM ; i ++ ) {
		swap ( &key [ rand () % NUM ], &key [ rand () % NUM ] ); 
	}
	for ( i = 0 ; i < NUM ; i ++ ) {
		between ( &que, key[i], que.rear->prev , que.rear );
	}
	show ( &que ); // unsorted linked list
	puts("\n\n");
	sort_func ( &que, que.size / 2 ) ;
	show( &que ); // sorted linked list
	free_queue ( &que ) ;
    return 0;
}
