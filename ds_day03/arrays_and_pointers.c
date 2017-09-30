#include <stdio.h>
#include <stdlib.h>

void print_array_the_easy_way( int[], int );
void print_array_the_hard_way( int *, int );
void print_array_of_chars_the_hard_way( char *, int );

int main(){

    printf( "On this system ints are %d\n", sizeof( int ) );
    printf( "On this system chars are %d\n", sizeof( char ) );
    printf( "On this system short are %d\n", sizeof( short ) );
    printf( "On this system double are %d\n", sizeof( double ) );



    int the_numbers[] = { 1, 2, 3, 4, 5 };
    char the_letters[] = { 'a', 'p', 'p', 'l', 'e' };
    
    printf( "Print the array the easy way:\n" );
    print_array_the_easy_way( the_numbers, 5 );

    printf( "Print the array the hard way:\n" );
    print_array_the_hard_way( the_numbers, 5 );

    printf( "Print the array (of chars) the hard way:\n" );
    print_array_of_chars_the_hard_way( the_letters, 5 );

    int * new_numbers = ( int * ) malloc( sizeof( int ) * 5 );
    new_numbers[ 0 ] = 11;
    new_numbers[ 1 ] = 12;
    new_numbers[ 2 ] = 13;
    new_numbers[ 3 ] = 14;
    new_numbers[ 4 ] = 15;

    printf( "Print the array the easy way:\n" );
    print_array_the_easy_way( new_numbers, 5 );

    printf( "Print the array the hard way:\n" );
    print_array_the_hard_way( new_numbers, 5 );

    getchar();
    return 0;

}

void print_array_the_easy_way( int the_numbers[], int size ){

    int i = 0;
    for( i = 0; i < size; i++ ){
        printf( "\t%d\n", the_numbers[ i ] );
    }

}

void print_array_the_hard_way( int * the_numbers, int size ){

    int i = 0;
    for( i = 0; i < size; i++ ){
        printf( "The value is: %d, the address is: %p, the size of the pointers is: %d\n", *the_numbers, the_numbers, sizeof( the_numbers ) );
        the_numbers++;
    }
}

void print_array_of_chars_the_hard_way( char * the_letters, int size ){

    int i = 0;
    for( i = 0; i < size; i++ ){
        printf( "The value is: %c, the address is: %p, the size of the pointers is: %d\n", *the_letters, the_letters, sizeof( the_letters )  );
        the_letters++;
    }
}












