#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node * next;
};

void print_list( struct node * );
void print_backwards( struct node * );
struct node * find_node( struct node *, int );
struct node * insert_sorted( struct node * list, int x );

int main(){

	struct node * n1 = (struct node *)malloc( sizeof( struct node) );
	struct node * n2 = (struct node *)malloc( sizeof( struct node) );
	struct node * n3 = (struct node *)malloc( sizeof( struct node) );
	struct node * n4 = (struct node *)malloc( sizeof( struct node) );
	n1->value = 11;
	n2->value = 22;
	n3->value = 33;
	n4->value = 44;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	
	print_list( n1 );
	print_backwards( n1 );
	
	if( find_node( n1, 43 ) ){
		printf( "Found it!\n" );
	}else{
		printf( "Did not find it!\n" );
	}
	
	n1 = insert_sorted( n1, 27 );
	print_list( n1 );
	printf( "**** Recursion and ordered insertion ****\n" );
	n1 = insert_sorted( n1, 1 );
	n1 = insert_sorted( n1, 55 );
	print_list( n1 );
	getchar();
	return 0;

}

void print_list( struct node * list ){
	while( list ){
		printf( "The value is: %d\n", list->value );
		list = list->next;
	}
}

void print_backwards( struct node * list ){
	if( list ){
		print_backwards( list->next );
		printf( "The values in reverse order are: %d\n", list->value );
	}
}

struct node * find_node( struct node * list, int target ){
	if( !list || list->value == target ){
		return list;
	}else{
		return find_node( list->next, target );
	}
}

struct node * insert_sorted( struct node * list, int x ){
	if( list == NULL || x < list->value ){
		struct node * temp = list;
		list = ( struct node * )malloc( sizeof( struct node ));
		list->value = x;
		list->next = temp;
	}else{
		list->next = insert_sorted( list->next, x );
	}
	return list;
}













