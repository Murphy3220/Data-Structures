#include <stdio.h>
#include <stdlib.h>

struct node{
	char c;
	struct node * next;
};

void print_list( struct node * );
struct node * normal_insert( struct node *, char );
struct node * ordered_insert( struct node *, char );
struct node * delete_from_list( struct node *, int );
struct node * get_node( struct node *, int );
int get_length( struct node * );

int main(){

	struct node * the_list = NULL;
	// This breaks because it is uninitialized
	//struct node * the_list;
	the_list = ordered_insert( the_list, 'G' );
	the_list = ordered_insert( the_list, 'E' );
	the_list = ordered_insert( the_list, 'O' );
	the_list = ordered_insert( the_list, 'R' );
	the_list = ordered_insert( the_list, 'G' );
	the_list = ordered_insert( the_list, 'E' );

	print_list( the_list );

	/* Delete a nodee at a given position. */
	the_list = delete_from_list( the_list, 3 );
	printf( "After Delete:\n" );
	print_list( the_list );

	the_list = delete_from_list( the_list, 4 );
	the_list = delete_from_list( the_list, 0 );
	printf( "After Delete:\n" );
	print_list( the_list );
	
	
	getchar();
	return 0;

}

struct node * normal_insert( struct node * list, char c ){
	
	struct node * temp = (struct node *)malloc( sizeof( struct node ) );
	temp->next = NULL;
	temp->c = c;
	
	if( !list ){
		return temp;
	}else{
		temp->next = list;
		return temp;
	}
	
}

struct node * ordered_insert( struct node * list, char c ){

	struct node * current = list;
	struct node * previous = NULL;
	struct node * temp = (struct node *)malloc( sizeof( struct node ) );

	temp->next = NULL;
	temp->c = c;

	
	if( !list ){
		return temp;
	}else{
		// Hopefully will find the correct spot
		// for the value we are attempting to
		// insert.
		while( temp->c < current->c ){
			previous = current;
			current = current->next;
			if( !current ){
				break;
			}
		}
		if( !previous ){
			/* At start of list */
			temp->next = current;
			return temp;
		}else{
			/* We are somewhere in the list... */
			temp->next = current;
			previous->next = temp;
			return list;
		}
	}
}

struct node * delete_from_list( struct node * list, int pos ){

	int length = get_length( list );
	if( pos < 0 || pos >= length ){
		return list;
	}else{
		if( !list ){
			return NULL;
		}else if( length == 1 ){
			/* Delete from the start of the list. */			
			free( list );
			return NULL;
		}else if( pos == 0 ){
			struct node * new_start = list->next;
			free( list );
			return new_start;
		}else{
			/* Delete from somewhere in the list. */
			struct node * parent = get_node( list, pos - 1  );
			struct node * target = parent->next;
			struct node * new_child = target->next;
			parent->next = new_child;
			free( target );
			return list;
		}
	}

}

struct node * get_node( struct node * list, int pos ){
	int length = get_length( list );
	int current = 0;
	if( !list || length == 0 ){
		return NULL;
	}else{
		while( current != pos ){
			list = list->next;
			current++;
		}
		return list;
	}
}

int get_length( struct node * list ){
	int length = 0;
	while( list ){
		length++;
		list = list->next;
	}
	return length;
}

void print_list( struct node * list ){
	int counter = 0;
	while( list != NULL ){
		printf( "The value at position %d is %c\n", counter, list->c );
		counter++;
		list = list->next;
	}
}




