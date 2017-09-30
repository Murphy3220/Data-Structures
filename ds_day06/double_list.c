#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node * next;
	struct node * prev;
};

void print_in_order( struct node * );
void print_backwards( struct node * );
struct node * insert_sorted( struct node *, int );

int main(){

	struct node * test_list = ( struct node * )malloc( sizeof( struct node ) );

	// Create the nodes and set some default values.
	struct node * n1 = (struct node *)malloc( sizeof( struct node ) );
	struct node * n2 = (struct node *)malloc( sizeof( struct node ) );
	struct node * n3 = (struct node *)malloc( sizeof( struct node ) );

	n1->value = 11;
	n1->next = NULL;
	n1->prev = NULL;

	n2->value = 22;
	n2->next = NULL;
	n2->prev = NULL;
	
	n3->value = 33;
	n3->next = NULL;
	n3->prev = NULL;
	
	// Connect the nodes for the "next" pointer.
	n1->next = n2;
	n2->next = n3;
	
	// Connect the nodes for the "prev" pointer.
	n3->prev = n2;
	n2->prev = n1;
	
	// Print the nodes.
	printf( "Printing Forwards:\n" );
	print_in_order( n1 );
	
	printf( "Printing Backwards\n" );
	print_backwards( n1 );
	
	printf( "Test Insert:\n" );
	n1 = insert_sorted( n1, 25 );
	print_in_order( n1 );

	//test_list->value = 1;
	//test_list->next = NULL;
	//test_list->prev = NULL;
	//
	//test_list = insert_sorted( test_list, 2 );
	//test_list = insert_sorted( test_list, 3 );
	//printf( "Test Insert:\n" );
	//print_in_order( test_list );

	
	getchar();
	return 0;
}

void print_in_order( struct node * list ){
	while( list ){
		printf( "\tThe value is %d\n", list->value );
		list = list->next;
	}
}

void print_backwards( struct node * list ){
	if( list ){
		// Fast forward to the end of the list.
		while( list->next ){
			list = list->next;
		}
		// Print backwards from the end to the start.
		while( list ){
			printf( "\tThe value is %d\n", list->value );
			list = list->prev;
		}
	}
}

struct node * insert_sorted( struct node * list, int to_insert ){

	// Create the new node - ask the OS for some memory!
	struct node * new_node = (struct node *)malloc( sizeof( struct node  ) );
	// Set default values.
	new_node->value = to_insert;
	new_node->next = NULL;
	new_node->prev = NULL;

	// Simple case: empty list
	if( !list ){
		list = new_node;
	}else{
		// Find the correct place for the new node.
		// Create a new node "current" for traversal.
		struct node * current_node = list;
		// While current has a next node to look at...
		while( current_node->next ){
			// If the new's value is greater than current's...
			if( new_node->value > current_node->value ){
				// We increment, or move to the next node in the list.
				current_node = current_node->next;
			}else{
				// Else we have found the spot to put the new node
				// so we break the while loop.
				break;
			}
		}
		// Now we need to connect the nodes.
		// There are 3 conditions we need to deal with:
		// 1. Middle of the list
		// 2. First of the list
		// 3. End of the list
		if( current_node->prev && current_node->value > new_node->value ){
			// Connect the new node somewhere in the middle of the list.
			// Three nodes are "touched" and need to have their
			// connections adjusted.
			new_node->next = current_node;
			new_node->prev = current_node->prev;
			current_node->prev->next = new_node;
			current_node->prev = new_node;
		}else if( current_node->value >= new_node->value ){
			// Connect the new node to the start of the list.
			// Only 2 nodes are "touched" the new node and the
			// old first node of the list.
			new_node->next = current_node;
			current_node->prev = new_node;
			list = new_node;
		}else{
			// Connect the new node to the end of the list.
			// Again, only 2 nodes are "touched" the new node
			// and the old last node of the list.
			new_node->prev = current_node;
			current_node->next = new_node;
		}
	}
	return list;
}











