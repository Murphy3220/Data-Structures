#include <stdio.h>
#include <stdlib.h>

struct node{
	int payload;
	struct node * next;
};

void print_node( struct node * );
void print_list( struct node * );

int main(){

	struct node * n1 = ( struct node *)malloc( sizeof( struct node ) );
	struct node * n2 = ( struct node *)malloc( sizeof( struct node ) );
	struct node * n3 = ( struct node *)malloc( sizeof( struct node ) );
	
	n1->payload = 11;
	n1->next = n2;
	n2->payload = 22;
	n2->next = n3;
	n3->payload = 33;
	n3->next = NULL;
	
	//print_node( n1 );
	//print_node( n2 );
	//print_node( n3 );
	
	print_list( n1 );
	
	getchar();
	return 0;
}

void print_node( struct node * n ){
	printf( "%d\n", n->payload );
}

void print_list( struct node * list ){
	while( list ){
		print_node( list );
		list = list->next;
	}
}




















