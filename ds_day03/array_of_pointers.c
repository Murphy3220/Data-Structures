#include <stdio.h>
#include <stdlib.h>

int main(){

    int * the_array_of_pointers[ 3 ];
    the_array_of_pointers[ 0 ] = ( int * ) malloc( sizeof( int ) );
    the_array_of_pointers[ 1 ] = ( int * ) malloc( sizeof( int ) );

    malloc( sizeof( int ) * 77 );

    the_array_of_pointers[ 2 ] = ( int * ) malloc( sizeof( int ) );
    
    *the_array_of_pointers[ 0 ] = 1;
    *the_array_of_pointers[ 1 ] = 2;
    *the_array_of_pointers[ 2 ] = 3;
    
    printf( "%d is at %p\n", *the_array_of_pointers[ 0 ], the_array_of_pointers[ 0 ] );
    printf( "%d is at %p\n", *the_array_of_pointers[ 1 ], the_array_of_pointers[ 1 ] );
    printf( "%d is at %p\n", *the_array_of_pointers[ 2 ], the_array_of_pointers[ 2 ] );
    
    getchar();
    return 0;

}
