#include <stdio.h>
#include <stdlib.h>

struct node{
	int payload;
	struct node * next;
};

void print_node( struct node * );
void print_list( struct node * );
struct node * prepend_node( struct node *, int );
struct node * new_node( int );
int total_list( struct node * );
struct node * delete_end( struct node * );
int count_nodes( struct node * );
struct node * delete_start( struct node * );

int main(){

	// Create the first element of the list.
	struct node * n1 = new_node( 11 );
	
	// Add additional elements to the list.
	// Note that n1 will change - we will have a
	// different first element after each call
	// to prepend_node.
	n1 = prepend_node( n1, 22 );
	n1 = prepend_node( n1, 33 );
	
	print_list( n1 );
	
	printf( "The total is: %d\n", total_list( n1 ) );
	
	n1 = delete_end( n1 );
	printf( "After first delete count is: %d\n", count_list( n1 ) );
	print_list( n1 );

	n1 = delete_end( n1 );
	printf( "After second delete count is: %d\n", count_list( n1 ) );
	print_list( n1 );

	
	n1 = delete_end( n1 );
	printf( "After third delete count is: %d\n", count_list( n1 ) );
	print_list( n1 );
	
	n1 = prepend_node( n1, 44 );
	n1 = prepend_node( n1, 55 );
	n1 = prepend_node( n1, 66 );
	
	printf( "Before delete start count is: %d\n", count_list( n1 ) );
	print_list( n1 );
	
	n1 = delete_start( n1 );
	printf( "After first delete of start count is: %d\n", count_list( n1 ) );
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

struct node * new_node( int i ){
	struct node * temp = ( struct node * )malloc( sizeof( struct node ) );
	temp->payload = i;
	temp->next = NULL;
	return temp;
}

struct node * prepend_node( struct node * list, int i ){
	struct node * temp = new_node( i );
	temp->next = list;
	return temp;
}

int total_list( struct node * list ){
	int total = 0;
	while( list ){
		total += list->payload;
		list = list->next;
	}
	return total;
}

int count_list( struct node * list ){
	int count = 0;
	while( list ){
		count++;
		list = list->next;
	}
	return count;
}

struct node * delete_start( struct node * list ){
	struct node * temp = NULL;
	if( list ){
		if( list->next ){
			temp = list->next;
			free( list );
			return temp;
		}else{
			free( list );
			return NULL;
		}
	}else{
		return NULL;
	}
}


struct node * delete_end( struct node * list ){
	struct node * start = list;
	struct node * prev = list;
	if( list ){
		if( !list->next ){
			// There is only one element in the list.
			free( list );
			return NULL;
		}else{
			// We have a list with 2 or more elements.
			while( list->next ){
				prev = list;
				list = list->next;
			}
			prev->next = NULL;
			free( list );
			return start;
		}
	}else{
		// List is empty.
		return NULL;
	}

}












