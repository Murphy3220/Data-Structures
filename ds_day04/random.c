#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int get_random();

int main(){

	int i = 0;

	srand( (unsigned)time( 0 ) );

	for( i = 0; i < 10; i++ ){ 
		printf( "%d\n", get_random() );
	}

	getchar();
	return 0;

}

int get_random(){
	return ( rand() % 99 ) + 1 ;
}