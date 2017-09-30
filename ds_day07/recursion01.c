#include <stdio.h>

void print_something();
void count_recursion( int );
void print_ten_times( int );
double factorial( double );

int main(){

	// This function is broken.
	// The recursion never stops.
	//print_something();

	// Utility function to count the level
	// of recursion. Also broken.
	//count_recursion( 1 );
	
	print_ten_times( 1 );
	
	printf( "The factorial of %f is: %f\n", 10.0, factorial( 10.0 ));
	
	getchar();
	return 0;

}

void print_something(){
	printf( "Hello Class!" );
	print_something();
	printf( "Bye Class!" );
}

void count_recursion( int x ){
	printf( "x = %d\n", x );
	x++;
	count_recursion( x );
}

void print_ten_times( int x ){
	printf( "x = %d\n", x );
	x++;
	if( x < 10 ){
		print_ten_times( x );
	}
	printf( "After!\n" );
}

double factorial( double f ){
	printf( "Before: %d\n", f );
	if( f == 0 ){
		return 1;
	}else{
		return f * factorial( f - 1 );
	}
}






