/*
	graph or map = a data structure that consists of a set of nodes
	and a set of edges that relate or connect the nodes to one
	another.
	
	vertex = a node in the graph
	
	edge (aka. arc) = a pair of vertices representing a connection between
	two nodes on the graph.
	
	undirected graph = a graph in which the edges have no direction.
	
	directed graph = a graph in which each edge is directed from
	one vertex to another ( or the same ) vertex.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room{
	char name[ 20 ];
	struct room * north;
	struct room * south;
	struct room * east;
	struct room * west;
	int type;
};

struct player{
	struct room * location;
	int turns;
};



int main(){

	// Set the value for the main loop.
	int loop = 1;
	
	// Declare the player and room structures.
	struct player * p = ( struct player * )malloc( sizeof( struct player ) );
	struct room * r01 = ( struct room * )malloc( sizeof( struct room ) );
	struct room * r02 = ( struct room * )malloc( sizeof( struct room ) );
	struct room * r03 = ( struct room * )malloc( sizeof( struct room ) );
	struct room * r04 = ( struct room * )malloc( sizeof( struct room ) );
	struct room * r05 = ( struct room * )malloc( sizeof( struct room ) );
	struct room * r06 = ( struct room * )malloc( sizeof( struct room ) );
	struct room * r07 = ( struct room * )malloc( sizeof( struct room ) );
	
	// Set the values for the rooms.
	strcpy( r01->name, "One" );
	r01->north = NULL;
	r01->south = r03;
	r01->east = r02;
	r01->west = NULL;
	r01->type = 1;
	
	strcpy( r02->name, "Two" );
	r02->north = NULL;
	r02->south = r04;
	r02->east = NULL;
	r02->west = r01;
	r02->type = 1;
	
	strcpy( r03->name, "Three" );
	r03->north = r01;
	r03->south = r05;
	r03->east = r04;
	r03->west = NULL;
	r03->type = 1;
	
	strcpy( r04->name, "Four" );
	r04->north = r02;
	r04->south = r06;
	r04->east = NULL;
	r04->west = r03;
	r04->type = 1;
	
	strcpy( r05->name, "Five" );
	r05->north = r03;
	r05->south = NULL;
	r05->east = NULL;
	r05->west = NULL;	
	r05->type = 0;
	
	strcpy( r06->name, "Six" );
	r06->north = r04;
	r06->south = NULL;
	r06->east = r07;
	r06->west = NULL;	
	r06->type = 1;
	
	strcpy( r07->name, "Seven" );
	r07->north = NULL;
	r07->south = NULL;
	r07->east = NULL;
	r07->west = NULL;
	r07->type = 9;
	
	// Set players initial location.
	p->location = r01;
	p->turns = 0;
	
	// Main program loop.
	while( loop ){
		if( p->location->type == 0 ){
			printf( "You have lost in %d turns!\n", p->turns );
			break;
		}else if( p->location->type == 9 ){
			printf( "You have Won in %d turns!\n", p->turns );
			break;
		}else{
			printf( "You are in room: %s\n", p->location->name );
			if( p->location->north ){
				if( p->location->north->type == 0 ){
					printf( "There is a path to the North that is very scary looking.\n" );
				}else if( p->location->north->type == 9 ){
					printf( "There is a path to the North that is very profitable looking.\n" );
				}else{
					printf( "There is a path to the North.\n" );
				}
			}
			if( p->location->south ){
				if( p->location->south->type == 0 ){
					printf( "There is a path to the South that is very scary looking.\n" );
				}else if( p->location->south->type == 9 ){
					printf( "There is a path to the South that is very profitable looking.\n" );
				}else{
					printf( "There is a path to the South.\n" );
				}
			}
			if( p->location->east ){
				if( p->location->east->type == 0 ){
					printf( "There is a path to the East that is very scary looking.\n" );
				}else if( p->location->east->type == 9 ){
					printf( "There is a path to the East that is very profitable looking.\n" );
				}else{
					printf( "There is a path to the East.\n" );
				}
			}
			if( p->location->west ){
				if( p->location->west->type == 0 ){
					printf( "There is a path to the West that is very scary looking.\n" );
				}else if( p->location->west->type == 9 ){
					printf( "There is a path to the West that is very profitable looking.\n" );
				}else{
					printf( "There is a path to the West.\n" );
				}
			}
		}
		printf( "What do you want to do? " );
		fflush( stdin );
		loop = getchar();
		switch( loop ){
			case 'q':
				printf( "You played for %d turns, thanks for playing!\n", p->turns );
				loop = 0;
				break;
			case 'n':
				// If p's current location has a pointer to the North
				if( p->location->north ){
					p->location = p->location->north;
				}else{
					printf( "You can't go that way!\n" );
				}
				p->turns++;
				break;
			case 's':
				// If p's current location has a pointer to the South
				if( p->location->south ){
					p->location = p->location->south;
				}else{
					printf( "You can't go that way!\n" );
				}
				p->turns++;
				break;
			case 'e':
				// If p's current location has a pointer to the East
				if( p->location->east ){
					p->location = p->location->east;
				}else{
					printf( "You can't go that way!\n" );
				}
				p->turns++;
				break;
			case 'w':
				// If p's current location has a pointer to the West
				if( p->location->west ){
					p->location = p->location->west;
				}else{
					printf( "You can't go that way!\n" );
				}
				p->turns++;
				break;
			default:
				printf( "Please enter a valid command!\n" );
				break;
		}
	}
	fflush( stdin );
	getchar();
	return 0;
}





