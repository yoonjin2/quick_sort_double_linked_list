#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include <time.h>
int main()
{
	int N,K;
	scanf("%d %d",  &N,&K);
    list lst ;
    init_list ( &lst ); //init list
	int i;
	for ( i = 0 ; i < N ; i ++ ) {
		push ( &lst , i+1 );
	}
	K--;
	int idx=K;
	for( i = 0;i <N;i ++) {
		node * nd = index_node(&lst, idx);
		printf("%d", nd->key);
		remove_item(&lst,nd);
		idx+=K;
		if(size(&lst)==0) {
			break;
		}
		if(idx>=size(&lst)) {
			idx%=size(&lst);
		}
		if(i!=N-1) {
			printf(" ");	
		}
	}


	return 0;
}
