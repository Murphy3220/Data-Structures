#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_COUNT 7
#define INF 99

typedef char bool;
#define TRUE 1
#define FALSE 0

struct room{

	char name[ 20 ];
	struct room * north;
	struct room * south;
	struct room * east;
	struct room * west;
	
	char checked;
	int distance;
	struct room * prev;
	
};

struct room_link{
	struct room * room;
	struct room_link * next;
};

struct room_link * queue = NULL;

struct room * create_room( char * );
void depth_first_search( struct room *, struct room * );
void clear_checks( struct room * [], int );
void queue_insert( struct room_link * );
struct room_link * queue_remove();
void breadth_first_search( struct room *, struct room * );
void shortest_path( struct room * [], struct room * );
struct room * find_shortest_distance( struct room * [] );
void show_path( struct room * );

int main(){

	struct room * rooms[ ROOM_COUNT ];
	rooms[ 0 ] = create_room( "Room 0" );
	rooms[ 1 ] = create_room( "Room 1" );
	rooms[ 2 ] = create_room( "Room 2" );
	rooms[ 3 ] = create_room( "Room 3" );
	rooms[ 4 ] = create_room( "Room 4" );
	rooms[ 5 ] = create_room( "Room 5" );
	rooms[ 6 ] = create_room( "Room 6" );

	rooms[ 0 ]->east = rooms[ 1 ];
	rooms[ 1 ]->west = rooms[ 0 ];
	rooms[ 1 ]->east = rooms[ 2 ];
	rooms[ 2 ]->west = rooms[ 1 ];
	rooms[ 1 ]->south = rooms[ 3 ];
	rooms[ 3 ]->north = rooms[ 1 ];
	rooms[ 2 ]->south = rooms[ 4 ];
	rooms[ 4 ]->north = rooms[ 2 ];
	rooms[ 3 ]->east = rooms[ 4 ];
	rooms[ 4 ]->west = rooms[ 3 ];
	rooms[ 3 ]->south = rooms[ 5 ];
	rooms[ 5 ]->north = rooms[ 3 ];
	
	depth_first_search( rooms[ 0 ], rooms[ 5 ] );
	clear_checks( rooms, ROOM_COUNT );
	breadth_first_search( rooms[ 0 ], rooms[ 6 ] );
	clear_checks( rooms, ROOM_COUNT );
	shortest_path( rooms, rooms[ 0 ] );
	printf( "%s can be reached in %d moves\n", rooms[ 5 ]->name, rooms[ 5 ]->distance );
	show_path( rooms[ 5 ] );
	//printf( "%s can be reached in %d moves\n", rooms[ 2 ]->name, rooms[ 2 ]->distance );
	//printf( "%s can be reached in %d moves\n", rooms[ 6 ]->name, rooms[ 6 ]->distance );
	getchar();
	return 0;
}

struct room * create_room( char * name ){
	struct room * temp_room = ( struct room * )malloc( sizeof( struct room ) );
	strcpy( temp_room->name, name );
	temp_room->north = NULL;
	temp_room->south = NULL;
	temp_room->east = NULL;
	temp_room->west = NULL;
	temp_room->checked = FALSE;
	temp_room->prev = NULL;
	return temp_room;
}

void depth_first_search( struct room * start, struct room * end ){

	int found = FALSE;
	struct room_link * stack = ( struct room_link * )malloc( sizeof( struct room_link ) );
	stack->room = start;
	stack->next = NULL;
	do{
		struct room_link * temp = stack;
		stack = stack->next;
		if( temp->room == end ){
			printf("Found Solution in room: %s!\n", end->name );
			found = TRUE;
		}else{
			if( !temp->room->checked ){
				temp->room->checked = TRUE;
				if( temp->room->north ){
					struct room_link * north_temp = (struct room_link *)malloc( sizeof( struct room_link ) );
					north_temp->room = temp->room->north;
					north_temp->next = stack;
					stack = north_temp;
				}
				if( temp->room->south ){
					struct room_link * south_temp = (struct room_link *)malloc( sizeof( struct room_link ) );
					south_temp->room = temp->room->south;
					south_temp->next = stack;
					stack = south_temp;
				}
				if( temp->room->east ){
					struct room_link * east_temp = (struct room_link *)malloc( sizeof( struct room_link ) );
					east_temp->room = temp->room->east;
					east_temp->next = stack;
					stack = east_temp;
				}
				if( temp->room->west ){
					struct room_link * west_temp = (struct room_link *)malloc( sizeof( struct room_link ) );
					west_temp->room = temp->room->west;
					west_temp->next = stack;
					stack = west_temp;
				}
			}
			free( temp );
		}
	}while( stack && !found );
	if( !found ){
		printf( "Solution not found!\n" );
	}
}

void clear_checks( struct room * rooms[], int size ){
	int i = 0;
	for( i = 0; i < size; i++ ){
		rooms[ i ]->prev = NULL;
		rooms[ i ]->distance = INF;
		rooms[ i ]->checked = FALSE;
	}
}


void queue_insert( struct room_link * room ){
	room->next = queue; // the global queue
	queue = room;
}

struct room_link * queue_remove(){
	struct room_link * temp = queue; // the global queue again
	struct room_link * back = NULL;
	if( !temp ){
		return NULL;
	}else if( !temp->next ){
		queue = NULL;
		return temp;
	}else{
		while( temp->next ){
			back = temp;
			temp = temp->next;
		}
		back->next = NULL;
	}
	return temp;
}

void breadth_first_search( struct room * start , struct room * end ){
	int found = FALSE;
	struct room_link * new_link = ( struct room_link * )malloc( sizeof( struct room_link ) );
	new_link->room = start;
	new_link->next = NULL;
	queue_insert( new_link );
	do{
		struct room_link * temp = queue_remove();
		if( temp->room == end ){
			printf( "Found solution in room: %s\n", end->name );
			found = TRUE;
		}else{
			if( !temp->room->checked ){
				temp->room->checked = TRUE;
				if( temp->room->north ){
					struct room_link * north_temp = ( struct room_link * )malloc( sizeof( struct room_link ) );
					north_temp->room = temp->room->north;
					queue_insert( north_temp );
				}
				if( temp->room->south ){
					struct room_link * south_temp = ( struct room_link * )malloc( sizeof( struct room_link ) );
					south_temp->room = temp->room->south;
					queue_insert( south_temp );
				}
				if( temp->room->east ){
					struct room_link * east_temp = ( struct room_link * )malloc( sizeof( struct room_link ) );
					east_temp->room = temp->room->east;
					queue_insert( east_temp );
				}
				if( temp->room->west ){
					struct room_link * west_temp = ( struct room_link * )malloc( sizeof( struct room_link ) );
					west_temp->room = temp->room->west;
					queue_insert( west_temp );
				}
			}
			free( temp );
		}
	}while( queue && !found );
	if( !found ){
		printf( "Solution not found!\n" );
	}
	
}

// Based Dijkstra's Algorithm
void shortest_path( struct room * rooms[], struct room * start ){
	
	struct room * current_room = NULL;
	clear_checks( rooms, ROOM_COUNT );
	start->distance = 0;
	
	while( current_room = find_shortest_distance( rooms ) ){
		if( current_room->distance == INF ){
			break;
		}
		current_room->checked = TRUE;
		if( current_room->north ){
			int temp_distance = current_room->distance + 1;
			if( temp_distance < current_room->north->distance ){
				current_room->north->distance = temp_distance;
				current_room->north->prev = current_room;
			}
		}
		if( current_room->south ){
			int temp_distance = current_room->distance + 1;
			if( temp_distance < current_room->south->distance ){
				current_room->south->distance = temp_distance;
				current_room->south->prev = current_room;
			}
		}
		if( current_room->east ){
			int temp_distance = current_room->distance + 1;
			if( temp_distance < current_room->east->distance ){
				current_room->east->distance = temp_distance;
				current_room->east->prev = current_room;
			}
		}
		if( current_room->west ){
			int temp_distance = current_room->distance + 1;
			if( temp_distance < current_room->west->distance ){
				current_room->west->distance = temp_distance;
				current_room->west->prev = current_room;
			}
		}
	}
}

struct room * find_shortest_distance( struct room * rooms[] ){
	struct room * rv = NULL;
	int i = 0;
	for( i = 0; i < ROOM_COUNT; i++ ){
		if( ( !rooms[ i ]->checked ) && ( rooms[ i ]->distance < INF ) ){
			if( !rv ){
				rv = rooms[ i ];
			}else if( rooms[ i ]->distance < rv->distance ){
				rv = rooms[ i ];
			}
		}
	}
	return rv;
}

void show_path( struct room * end ){
	if( end->prev ){
		show_path( end->prev );
	}
	printf( "%s\n", end->name );
}






