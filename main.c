#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include <time.h>
int main()
{
	srand ( time ( NULL ) ) ;
    queue que;
    init_queue ( &que );
    int i , key[1000] ;
	for ( i = 0 ; i < 1000 ; i ++ ) {
	//	key[i]=i;
		key[i]= rand () % 1000;
	}
	for ( i = 0 ; i < 1000 ; i ++ ) {
		swap ( &key [ rand () % 1000 ], &key [ rand () % 1000 ] ); 
	}
	for ( i = 0 ; i < 1000 ; i ++ ) {
		between ( &que, key[i], que.rear->prev , que.rear );
	}
	show ( &que );
	puts("\n\n");
	sort_func ( &que, que.size / 2 ) ;
	show( &que );
	free_queue ( &que ) ;
    return 0;
}
