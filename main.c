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
    list lst , lst2;
    init_list ( &lst ); //init list
    init_list ( &lst2 );
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
		push ( &lst2 , key [ i ] );
	}
//	show ( &lst ); // unsorted linked list
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
	start = clock ();
	merge_sort ( &lst2 );
	end = clock () ;
	regen_sorted ( &lst2 );
	if ( lst2.is_sorted == true ) {
		puts("\nmerge sort -- is sorted");
	} else {
		puts("\nmerge sort -- is not sorted");
	}
	printf ("\n\nmerge sort : %lf\n" , ( double ) ( end - start ) / CLOCKS_PER_SEC ) ; 
	//show( &lst2);
	free_list ( &lst2 );
	return 0;
}
