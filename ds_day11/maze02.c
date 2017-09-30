#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct room{
	char name[ 20 ];
	struct room * north;
	struct room * south;
	struct room * east;
	struct room * west;
	int visited;
	int type;
};

struct player{
	int points;
	int turns;
	struct room * location;
};

struct room * create_room( char *, int );
/* The direction defines a starting point and will also cover the reverse. */
void connect_rooms( struct room *, struct room *, char );
void describe_room( struct room * );
char check_room( struct player * p, struct room * [] );

int main(){
	
	char loop = 1;
	struct room * rooms[ 9 ];
	struct player * p = ( struct player * )malloc( sizeof( struct player ) );
	srand( time( NULL ) );
	rooms[ 0 ] = create_room( "Room One", 1 );
	rooms[ 1 ] = create_room( "Room Two", 1 );
	rooms[ 2 ] = create_room( "Room Three", 3 );
	rooms[ 3 ] = create_room( "Room Four", 1 );
	rooms[ 4 ] = create_room( "Room Five", 1 );
	rooms[ 5 ] = create_room( "Room Six", 1 );
	rooms[ 6 ] = create_room( "Room Seven", 0 );
	rooms[ 7 ] = create_room( "Room Eight", 1 );
	rooms[ 8 ] = create_room( "Room Nine", 2 );
	connect_rooms( rooms[ 0 ], rooms[ 1 ], 'e' );
	connect_rooms( rooms[  1  ], rooms[  4  ], 's' );
	connect_rooms( rooms[  2  ], rooms[  5  ], 's' );
	connect_rooms( rooms[  3  ], rooms[  4  ], 'e' );
	connect_rooms( rooms[  4  ], rooms[  5  ], 'e' );
	connect_rooms( rooms[  3  ], rooms[  6  ], 's' );
	connect_rooms( rooms[  4  ], rooms[  7  ], 's' );
	connect_rooms( rooms[  5  ], rooms[  8  ], 's' );
	connect_rooms( rooms[  6  ], rooms[  7  ], 'e' );
	
	p->location = rooms[ 0 ];
	p->turns = 0;
	p->points = 0;
	check_room( p, rooms );
	
	// The main game loop.
	while( loop ){
		describe_room( p->location );
		printf( "What do you want to do? " );
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
					printf( "You walked into a wall dummy!\n" );
				}
				p->turns++;
			break;
			case 's':
				if( p->location->south ){
					p->location = p->location->south;
					loop = check_room( p, rooms );
				}else{
					printf( "You walked into a wall dummy!\n" );
				}
				p->turns++;
			break;
			case 'e':
				if( p->location->east ){
					p->location = p->location->east;
					loop = check_room( p, rooms );
				}else{
					printf( "You walked into a wall dummy!\n" );
				}
				p->turns++;
			break;
			case 'w':
				if( p->location->west ){
					p->location = p->location->west;
					loop = check_room( p, rooms );
				}else{
					printf( "You walked into a wall dummy!\n" );
				}
				p->turns++;
			break;
			case 'h':
				printf( "Please enter n, s, e, or w. q to quit\n" );
			break;
			default:
				printf( "Please enter a valid command!\n" );
			break;
		}
	}
	
	printf( "Turns: %d\n", p->turns );
	printf( "Points: %d\n", p->points );
	fflush( stdin );
	getchar();
	return 0;
}

struct room * create_room( char * name, int type ){
	struct room * temp_room = ( struct room * )malloc( sizeof( struct room ) );
	strcpy( temp_room->name, name );
	temp_room->type = type;
	temp_room->visited = 0;
	temp_room->north = NULL;
	temp_room->south = NULL;
	temp_room->east = NULL;
	temp_room->west = NULL;
	return temp_room;
}

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
	}
}

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
}

char check_room( struct player * p, struct room * rooms[] ){
	// Stuff happens!
	int i = 1;
	int good = rand() % 6 + 1;
	int bad = rand() % 6 + 1;
	int index;
	 p->location->visited++;
	 switch( p->location->type ){
		 case 0:
			p->points = p->points - 5;
			printf( "Ouch! You just lost 5 points!\n" );
		 break;
		 case 1:
			//?
		 break;
		 case 2:
			// Victory!
			printf( "You have reached the end of the maze!\n" );
		 break;
		 case 3:
			p->points = p->points + 2;
			printf( "Excellent! You just gained 2 points!" );
		 break;
	 }
	 
	 // Change to room type!
	 for( i = 1; i < 7; i++ ){
		rooms[ i ]->type = 1;
	 }
	 while( bad == good ){
		bad = rand() % 6 + 1;
	 }
	 rooms[ good ]->type = 3;
	 rooms[ bad ]->type = 0;

	 // Spin the center room!
	 if( p->location == rooms[ 4 ] ){
		if( rooms[ 4 ]->north == rooms[ 1 ] ){
			index = 1;
		}else if( rooms[ 4 ]->north == rooms[ 5 ] ){
			index = 5;
		}else if( rooms[ 4 ]->north == rooms[ 7 ] ){
			index = 7;
		}else if( rooms[ 4 ]->north == rooms[ 3 ] ){
			index = 3;
		}
		switch( index ){
			case 1:
				rooms[ 4 ]->north = rooms[ 5 ];
				rooms[ 4 ]->south = rooms[ 3 ];
				rooms[ 4 ]->east = rooms[ 7 ];
				rooms[ 4 ]->west = rooms[ 1 ];
			break;
			case 5:
				rooms[ 4 ]->north = rooms[ 7 ];
				rooms[ 4 ]->south = rooms[ 1 ];
				rooms[ 4 ]->east = rooms[ 5 ];
				rooms[ 4 ]->west = rooms[ 3 ];
			break;
			case 7:
				rooms[ 4 ]->north = rooms[ 3 ];
				rooms[ 4 ]->south = rooms[ 7 ];
				rooms[ 4 ]->east = rooms[ 1 ];
				rooms[ 4 ]->west = rooms[ 5 ];
			break;
			case 3:
				rooms[ 4 ]->north = rooms[ 1 ];
				rooms[ 4 ]->south = rooms[ 5 ];
				rooms[ 4 ]->east = rooms[ 3 ];
				rooms[ 4 ]->west = rooms[ 7 ];
			break;
		}
		printf("You feel a little dizzy!\n");
	}
	 
	 
	 // Check for player victory!
	 if( p->location == rooms[ 8 ] ){
		return 0;
	 }else{
		return 1;
	 }
	 
}


























