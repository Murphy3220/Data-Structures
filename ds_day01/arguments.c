//Ryan Murphy
//Data Structures
//Assignemtn 3

#include<iostream>
#include<iomanip>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Creates the struct for the Die.
struct Roll{
	int Die1;
	int Die2;
	struct Roll * next;
};

void print_list( struct Roll *);//displays the rolls
void print_node( struct Roll * );
struct Roll * new_roll( int Die1, int Die2 );
int total_list( struct Roll *);
struct Roll * add_roll( struct Roll * list, int Die1, int Die2 );
int main(int argc, char *argv[])
{
	int Die1 = (rand () %6) +1;
	int Die2 = (rand () %6) +1;
	srand((unsigned) time( NULL )); //random-number generator

	if (argc == 3) {
		printf("You did not enter how many times to roll the die.\n");
	}
	else{
		//list = roll_die(list,Die1, Die2, argv);
		int i;

		struct Roll *list = new_roll(Die1, Die2);
		for (i=0;i<3;i++)
		{
		list = add_roll(list, Die1, Die2);
		}
		print_list(list);
		printf("The Total is: %d\n", total_list(list));
	}
	getchar();
	return 0;
}
void print_node( struct Roll * n ){
	printf( "%d  %d\n", n->Die1, n ->Die2);
}
void print_list( struct Roll * list){
	while( list ){
		print_node( list );
		list = list->next;
		}
}
struct Roll * new_roll( int Die1, int Die2 )
{
	Die1 = (rand () %6) +1;
	Die2 = (rand () %6) +1;
	struct Roll * roll_die = ( struct Roll * )malloc( sizeof( struct Roll ) );
	roll_die ->Die1 = Die1;
	roll_die ->Die2 = Die2;
	roll_die ->next = NULL;
	return roll_die;
}
struct Roll * add_roll( struct Roll * list, int Die1, int Die2 )
{
	struct Roll * roll_die = new_roll( Die1,Die2 );
	roll_die->next = list;
	return list;
}
int total_list( struct Roll * list ){
	int total = 0;
	while( list ){
		total += list->Die1 + list ->Die2;
		list = list->next;
	}
	return total;
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