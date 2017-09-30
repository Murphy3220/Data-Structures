#include <stdio.h>

int main( int argc, char * argv[] ){

	int i = 0;
	int total = 0;
		
	if( argc == 1 ){
		printf( "Please enter a few command line arguments!\n" );
	}else{
		for( i = 1; i < argc; i++ ){
			printf( "%s\n", argv[ i ] );
			total += atoi( argv[ i ] );
		}
		printf( "The total is: %d\n", total );
		printf( "The number of arguments is: %d\n", argc - 1 );
		printf( "The average is: %0.2f\n", (float)total/(argc - 1) );
	}

	getchar();
	return 0;

}