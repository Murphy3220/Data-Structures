#include <stdio.h>
#include <stdlib.h>

/* The Fibonacci sequence:

0 1 1 2 3 5 8 13 21 34 ... ...

*/

void fibonacci( int, int, int );

int main( int argc, char * argv[] ){

	int a = 0;
	int b = 0;
	int max = 0;
	
	if( argc != 4 ){
		printf( "Usage: 3 integers!" );
	}else{
		a = atoi( argv[ 1 ] );
		b = atoi( argv[ 2 ] );
		max = atoi( argv[ 3 ] );
		printf( "Welcome to the Fibonacci Series Program!\n" );
		printf( "You entered a = %d, b = %d, mac = %d\n", a, b, max );
		printf( "The Fibonacci series for %d and %d to %d\n", a, b, max );
		fibonacci( a, b, max );
	}

	getchar();
	return 0;

}

void fibonacci( int a, int b, int max ){
	printf( " %d, %d,", a, b );
	a = a + b;
	b = a + b;
	if( b < max ){
		fibonacci( a, b, max );
	}
}




