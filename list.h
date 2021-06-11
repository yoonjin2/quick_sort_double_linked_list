#define NUM 6
#define LIM 45
typedef struct node{
	int key;
	struct node *prev;
	struct node *next;
} node;

typedef struct list {
	node *front;
	node *rear;
	int size; 
} list;

void init_list ( list * lst );
void between  ( list *lst , int item , node * r , node * element ) ;
int remove_item ( list *lst , node * element ) ;
int size ( list *lst ) ;
_Bool empty ( list * lst ) ;
void show ( list * lst ) ;
void free_list ( list * lst ) ;
void empty_list ( list * lst ) ;
node * find ( list * lst, int key ) ;
void sort_func ( list * lst , int pivot ) ;
void swap ( int * a, int * b );
