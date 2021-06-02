#define NUM 6
#define LIM 45
typedef struct node{
	int key;
	struct node *prev;
	struct node *next;
} node;

typedef struct queue {
	node *front;
	node *rear;
	int size; 
} queue;

void init_queue ( queue * que );
void between  ( queue *que , int item , node * r , node * q ) ;
int remove_item ( queue *que , node * q ) ;
int size ( queue *que ) ;
_Bool empty ( queue * que ) ;
void show ( queue * que ) ;
void free_queue ( queue * que ) ;
void empty_queue ( queue * que ) ;
node * find ( queue * que, int key ) ;
void sort_func ( queue * que , int pivot ) ;
void swap ( int * a, int * b );
