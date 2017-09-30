//Ryan Murphy
//Data Structures
//Project 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROOM_COUNT 27
#define INF 99

typedef char;

#define TRUE 1
#define FALSE 0

struct room{
	char name[ 20 ];
	struct room * north;
	struct room * south;
	struct room * east;
	struct room * west;
	struct room * up;
	struct room * down;
	struct room * prev;
	char checked;
	int distance;
	int visited;
	int type;
};

struct player{
	struct room * location;
	int points;
	int turns;
};
struct room * create_room( char *, int );
struct room_link{
	struct room * room;
	struct room_link * next;
};
struct room_link * queue = NULL;
struct room_link * queue_remove();
void describe_room( struct room * );
void clear_checks( struct room * [], int );
void depth_first_search( struct room *, struct room * );
void connect_rooms( struct room *, struct room *, char );
char check_room( struct player * p, struct room * [] );
void breadth_first_search( struct room *, struct room * );
void shortest_path( struct room * [], struct room * );
struct room * find_shortest_distance( struct room * [] );
struct room_link * queue_remove();
void queue_insert( struct room_link * );
void show_path( struct room * );

int main()
{
	char loop = 1;
	int tunrns = 0;
	int points = 0;
	struct player * p = ( struct player * )malloc( sizeof( struct player ) );
	struct room * rooms[ ROOM_COUNT ];
	srand( time( NULL ) );


	////////ROOM CREATION////////////////////
	rooms[ 0 ] = create_room( "Room 0", 4);
	rooms[ 1 ] = create_room( "Room 1", 4);
	rooms[ 2 ] = create_room( "Room 2", 0);
	rooms[ 3 ] = create_room( "Room 3", 1);
	rooms[ 4 ] = create_room( "Room 4", 4);
	rooms[ 5 ] = create_room( "Room 5", 3);
	rooms[ 6 ] = create_room( "Room 6", 4);
	rooms[ 7 ] = create_room( "Room 7", 3);
	rooms[ 8 ] = create_room( "Room 8", 0);
	rooms[ 9 ] = create_room( "Room 9", 0);
	rooms[ 10 ] = create_room( "Room 10", 1);
	rooms[ 11 ] = create_room( "Room 11", 4);
	rooms[ 12 ] = create_room( "Room 12", 4);
	rooms[ 13 ] = create_room( "Room 13", 4);
	rooms[ 14 ] = create_room( "Room 14", 4);
	rooms[ 15 ] = create_room( "Room 15", 3);
	rooms[ 16 ] = create_room( "Room 16", 2);
	rooms[ 17 ] = create_room( "Room 17", 4);
	rooms[ 18 ] = create_room( "Room 18", 4);
	rooms[ 19 ] = create_room( "Room 19", 1);
	rooms[ 20 ] = create_room( "Room 20", 0);
	rooms[ 21 ] = create_room( "Room 21", 4);
	rooms[ 22 ] = create_room( "Room 22", 4);
	rooms[ 23 ] = create_room( "Room 23", 4);
	rooms[ 24 ] = create_room( "Room 24", 3);
	rooms[ 25 ] = create_room( "Room 25", 4);
	rooms[ 26 ] = create_room( "Room 26", 4);

	///////////CONNECTS THE ROOMS///////////////
	rooms[ 0 ]->north = rooms[ 1 ];
	rooms[ 0 ]->east = rooms[ 5 ];
	rooms[ 1 ]->south = rooms[ 0 ];
	rooms[ 1 ]->north = rooms[ 2 ];
	rooms[ 1 ]->east = rooms[ 4 ];
	rooms[ 2 ]->south = rooms[ 1];
	rooms[ 3 ]->south = rooms[ 4 ];
	rooms[ 3 ]->east = rooms [ 8 ];
	rooms[ 4 ]->north = rooms[ 3 ];
	rooms[ 4 ]->south = rooms[ 5];
	rooms[ 4 ]->east = rooms[ 7];
	rooms[4]->west = rooms[1];
	rooms[5]->north = rooms[4];
	rooms[5]->east = rooms[6];
	rooms[5]->west = rooms[0];
	rooms[6]->north = rooms[7];
	rooms[6]->west = rooms[5];
	rooms[6]->down = rooms[15];
	rooms[7]->west = rooms[4];
	rooms[7]->south = rooms[6];
	rooms[8]->west = rooms[3];
	rooms[9]->north = rooms[10];
	rooms[10]->north = rooms[11];
	rooms[10]->south = rooms[9];
	rooms[10]->east = rooms[13];
	rooms[11]->south = rooms[10];
	rooms[11]->east = rooms[12];
	rooms[12]->south = rooms[13];
	rooms[12]->west = rooms[11];
	rooms[12]->east = rooms[17];
	rooms[13]->west = rooms[10];
	rooms[13]->south = rooms[14];
	rooms[13]->north = rooms[12];
	rooms[14]->north = rooms[13];
	rooms[14]->east = rooms[15];
	rooms[15]->west = rooms[14];
	rooms[15]->up = rooms[6];
	rooms[16]->down = rooms[25];
	rooms[17]->down = rooms[26];
	rooms[17]->east = rooms[12];
	rooms[26]->west = rooms[21];
	rooms[21]->south = rooms[22];
	rooms[21]->west = rooms[20];
	rooms[20]->east = rooms[21];
	rooms[21]->east = rooms[26];
	rooms[22]->west = rooms[19];
	rooms[22]->south = rooms[23];
	rooms[22]->north = rooms[21];
	rooms[19]->south = rooms[18];
	rooms[18]->north = rooms[19];
	rooms[18]->east = rooms[23];
	rooms[23]->east = rooms[24];
	rooms[23]->north = rooms[22];
	rooms[23]->west = rooms[18];
	rooms[24]->west = rooms[23];
	rooms[24]->north = rooms[25];
	rooms[25]->south = rooms[24];
	rooms[25]->up = rooms[16];

	p->location = rooms[ 0 ];//STARTING LOCATION
	p->turns = 0;//INITIALIZE TURN
	p->points = 0;//INITILIZE POINTS

	////////////GAME LOOP///////////////////////////
	while( loop ){
		describe_room( p->location );
		printf( "Whhere do you want to go? " );
		fflush( stdin );
		loop = getchar();
		switch( loop ){
		case 'q':
			loop = 0;
			break;
			break;
		case 'n':
			if( p->location->north ){
				p->location = p->location->north;
				loop = check_room( p, rooms );
			}else{
				printf( "You cant go that way!\n" );
			}
			p->turns++;
			break;
		case 's':
			if( p->location->south ){
				p->location = p->location->south;
				loop = check_room( p, rooms );
			}else{
				printf( "You cant go that way!\n" );
			}
			p->turns++;
			break;
		case 'e':
			if( p->location->east ){
				p->location = p->location->east;
				loop = check_room( p, rooms );
			}else{
				printf( "You cant go that way!\n" );
			}
			p->turns++;
			break;
		case 'w':
			if( p->location->west ){
				p->location = p->location->west;
				loop = check_room( p, rooms );
			}else{
				printf( "You cant go that way!\n" );
			}
			p->turns++;
			break;
		case 'u':
			if( p->location->up ){
				p->location = p->location->up;
				loop = check_room( p, rooms );
			}else{
				printf( "You cant go that way!\n" );
			}
			p->turns++;
			break;
		case 'd':
			if( p->location->down ){
				p->location = p->location->down;
				loop = check_room( p, rooms );
			}else{
				printf( "You cant go that way!\n" );
			}
			p->turns++;
			break;
		case 'h':
			printf( "Please enter n, s, e, w, u, or d. Enter q to quit\n" );
			break;
		default:
			printf( "That is not valid. Please enter a valid command!\n" );
			break;
		}
	}

	printf( "Turns: %d\n", p->turns );//DISPLAYS TOTAL TURNS
	printf( "Points: %d\n\n", p->points );//DISPLAYS TOTAL POINTS
	fflush( stdin );

	depth_first_search( rooms[ 0 ], rooms[ 16 ] );
	clear_checks( rooms, ROOM_COUNT );
	breadth_first_search( rooms[ 0 ], rooms[ 16 ] );
	clear_checks( rooms, ROOM_COUNT );
	shortest_path( rooms, rooms[ 0 ] );
	printf( "%s can be reached in %d moves\n", rooms[ 16 ]->name, rooms[ 16 ]->distance );

	printf("\nThis path will lead you to %s the fastest:\n", rooms[16]->name),show_path(rooms[ 16 ] );

	getchar();
	return 0;
}

/////////////CREATES A ROOM//////////////////////////
struct room * create_room( char * name, int type ){
	struct room * temp_room = ( struct room * )malloc( sizeof( struct room ) );
	strcpy( temp_room->name, name );
	temp_room->type = type;
	temp_room->north = NULL;
	temp_room->south = NULL;
	temp_room->east = NULL;
	temp_room->west = NULL;
	temp_room->up = NULL;
	temp_room->down = NULL;
	temp_room->checked = FALSE;
	temp_room->prev = NULL;
	return temp_room;
}

////////////CLEARS THE ROOM CHECKS////////////////////////////
void clear_checks( struct room * rooms[], int size ){
	int i = 0;
	for( i = 0; i < size; i++ ){
		rooms[ i ]->prev = NULL;
		rooms[ i ]->distance = INF;
		rooms[ i ]->checked = FALSE;
	}
}

////////////DESCRIBES THE ROOM/////////////////////////
void describe_room( struct room * r ){
	printf( "You are in: %s\n", r->name );
	if( r->north ){
		printf( "There is a path to the north\n" );
	}
	if( r->south ){
		printf( "There is a path to the south\n" );
	}
	if( r->east ){
		printf( "There is a path to the east\n" );
	}
	if( r->west ){
		printf( "There is a path to the west\n" );
	}
	if( r->up ){
		printf( "There is a path up above\n");
	}
	if( r->down){
		printf( "There is a path down below\n");
	}
}

/////////////CHECKS THE ROOM TYPE///////////////////////
char check_room( struct player * p, struct room * rooms[] ){
	int i = 1;
	p->location->visited = 0;
	p->location->visited++;
	switch( p->location->type ){
	case 0:
		p->points = p->points - 1;
		printf( "\nThis is a dead end! You just lost 1 point!\n\n" );
		break;
	case 1:
		p->points = p->points - 2;
		printf("\nA ghost in the room just stole 2 of your points!\n\n");
		break;
	case 2:
		p->points = p->points + 5;
		printf( "\nYou have reached the end of the maze!\n\n" );
		break;
	case 3:
		p->points = p->points + 3;
		printf( "\nYou found a stash worth 3 points!\n\n" );
		break;
	case 4:
		printf( "\nThere is nothing in this room.\n\n" );
		break;
	}

	// Checks to see if player is at the end of maze.
	if( p->location == rooms[ 16 ] ){
		return 0;
	}else{
		return 1;
	}
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
			printf("Found the solution in: %s\n", end->name );
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
				if( temp->room->up ){
					struct room_link * up_temp = (struct room_link *)malloc( sizeof( struct room_link ) );
					up_temp->room = temp->room->up;
					up_temp->next = stack;
					stack = up_temp;
				}
				if( temp->room->down ){
					struct room_link * down_temp = (struct room_link *)malloc( sizeof( struct room_link ) );
					down_temp->room = temp->room->down;
					down_temp->next = stack;
					stack = down_temp;
				}
			}
			free( temp );
		}
	}while( stack && !found );
	if( !found ){
		printf( "The solution wasnt found!\n" );
	}
}

/////////////////CONNECTS THE ROOMS//////////////////////////////
void connect_rooms( struct room * room_a, struct room * room_b, char d ){
	switch( d ){
	case 'n':
		room_a->north = room_b;
		room_b->south = room_a;
		break;
	case 's':
		room_a->south = room_b;
		room_b->north = room_a;
		break;
	case 'e':
		room_a->east = room_b;
		room_b->west = room_a;
		break;
	case 'w':
		room_a->west = room_b;
		room_b->east = room_a;
		break;
	case 'u':
		room_a->up = room_b;
		room_b->down = room_a;
		break;
	case 'd':
		room_a->down = room_b;
		room_b->up = room_a;
		break;
	}
}

struct room_link * queue_remove(){
	struct room_link * temp = queue;
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

void queue_insert( struct room_link * room ){
	room->next = queue;
	queue = room;
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
				if( temp->room->up ){
					struct room_link * up_temp = ( struct room_link * )malloc( sizeof( struct room_link ) );
					up_temp->room = temp->room->up;
					queue_insert( up_temp );
				}
				if( temp->room->down ){
					struct room_link * down_temp = ( struct room_link * )malloc( sizeof( struct room_link ) );
					down_temp->room = temp->room->down;
					queue_insert( down_temp );
				}
			}
			free( temp );
		}
	}while( queue && !found );
	if( !found ){
		printf( "Solution not found!\n" );
	}

}

/////////////////FINDS THE SHORTEST PATH TO END//////////////////////
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
		if( current_room->up ){
			int temp_distance = current_room->distance + 1;
			if( temp_distance < current_room->up->distance ){
				current_room->up->distance = temp_distance;
				current_room->up->prev = current_room;
			}
		}
		if( current_room->down ){
			int temp_distance = current_room->distance + 1;
			if( temp_distance < current_room->down->distance ){
				current_room->down->distance = temp_distance;
				current_room->down->prev = current_room;
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

///////SHOWS THE ROOM PATH FROM BEGGINING TO END//////////////////
void show_path( struct room * end ){
	if( end->prev ){
		show_path( end->prev );
	}
	printf( "%s\n", end->name );
}
