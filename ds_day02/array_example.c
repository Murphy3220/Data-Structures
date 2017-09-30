#include <stdio.h>

void print_array( int[], int );
void initialize_array( int[], int );
void double_array( int[], int );

int main( int argc, char * argv[] ){

    // Literal int array!
    int the_numbers[ 10 ] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    
    int i = 0;
    for( i = 0; i < 10; i++ ){
        printf( "%d\n", the_numbers[ i ] );
    }


    
    int other_numbers[ 5 ];
    initialize_array( other_numbers, 5 );
    other_numbers[ 0 ] = 99;
    other_numbers[ 1 ] = 98;
    //other_numbers[ 2 ] = 97;
    //other_numbers[ 3 ] = 96;
    other_numbers[ 4 ] = 95;

    for( i = 0; i < 5; i++ ){
        printf( "%d\n", other_numbers[ i ] );
    }

    print_array( other_numbers, 5 );

    double_array( other_numbers, 5 );
    print_array( other_numbers, 5 );

    print_array( other_numbers, 5 );
    
    getchar();
    return 0;

}

void print_array( int numbers[], int size ){
    int i = 0;
    printf( "The array contains %d values\n", size );
    for( i = 0; i < size; i++ ){
        printf( "\t%d\n", numbers[ i ] );
    }
}

void double_array( int numbers[], int size ){
    int i = 0;
    for( i = 0; i < size; i++ ){
        numbers[ i ] = numbers[ i ] + numbers[ i ];
    }
}

void initialize_array( int numbers[], int size ){
    int i = 0;
    for( i = 0; i < size; i++ ){
        numbers[ i ] = 0;
    }
}
















