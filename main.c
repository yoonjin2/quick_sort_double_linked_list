#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include <time.h>
int compare ( const void * a , const void * b ) {
	return * (int * ) a - * ( int * ) b ; 
}
int main()
{
	srand ( time ( NULL ) ) ;
    list lst ;
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
		push ( &lst , key [ i ] );
	}
	show ( &lst ); // unsorted linked list
	puts( "\n\n" );
	clock_t start , end ;
	start = clock () ;	
	sort_func ( &lst ) ;
	end = clock () ;
	printf("%d\n" , lst.size);
	show( &lst ); // sorted linked list
	regen_sorted ( &lst );
	if ( lst.is_sorted == true ) {
		puts("quick sort -- is sorted");
	} else {
		puts ("quick sort -- not sorted");
	}
	free_list ( &lst );
	printf("\n\nquick sort --doubly linked list : %lf" , ( double ) (end - start) / CLOCKS_PER_SEC ) ;
	start = clock ();
	qsort ( key , NUM , sizeof ( int ) , compare );
	end = clock ();
	printf("\n\nquick sort --array : %lf" , ( double ) ( end - start ) / CLOCKS_PER_SEC ) ;
	return 0;
}
