#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

#include <string.h>

char *strrem(char *orig, char *tok) {
  size_t len = strlen(tok);
  if (len > 0) {
      char *ptr = orig;
      while ((ptr = strstr(ptr, tok)) != NULL) {
          memmove(ptr, ptr + len, strlen(ptr + len) + 1);
      }
  }
  return orig;
}
int main(int argc, char ** argv) { 
  list *lst =(list *) malloc ( sizeof ( list ));
	init_list (lst);
	int idx=1;
	for (idx = 1 ; idx < argc ; idx ++) {
	  char *orig = argv[idx];
		float coef=0 , expo=0;
		char var;
		bool prflag;
		while(true) {
			prflag = true;
		  coef=0 ;
			expo=0;
		  sscanf(orig , "%*c%f%c^%f" , &coef , &var , &expo );
			if (orig[0] =='+') {
				prflag = false;
			}
			char * str = (char *)malloc (sizeof(char)*100);
		  char * cache = (char *)malloc(sizeof(char)*100);
			if (!prflag&& (coef > 0 )) {
					sprintf (cache,"%+.2f" , coef);
			} else if ( coef == 0 ) {
				continue;
			} else {
				sprintf (cache,"%.2f" , coef);
			}
			strcat (str,cache);
		  str[strlen(str)]=var;
			str[strlen(str)]='^';
			sprintf (cache,"%.2f" , expo);
			strcat(str,cache);
			puts(orig);
			puts(str);
			orig=strrem(orig,str);
			element_t value = {coef, var , expo };
			push ( lst , value );
			if ( !strlen(orig) ) {
		    break;
			}
		}
	}
	beautify (lst);
	sort_func(lst);
	show(lst);
}

