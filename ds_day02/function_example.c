 #include <stdio.h>

// Function prototypes.
void print_hello();

void print_number( int );

int double_number( int );

int sum_of_three( int, int, int );

int main( int argc, char * argv[] ){

    // The function call
    print_hello();

    print_number( 42 );

    printf( "The value is: %d\n", double_number( 42 ));

    printf( "The value is: %d\n", sum_of_three( 1, 2, 3 ));

    // Nested function calls.
    // Innermost function call is called first.
    // 1. sum_of_three
    // 2. double_number
    // 3. print_number
    print_number( double_number( sum_of_three( 4, 5, 6 ) ) );

    // Passing a value - not a reference.
    // Think "copy" of the original value.
    int x = 10;
    double_number( x );
    print_number( x );
    x = double_number( x );
    print_number( x );

    getchar();
    return 0;
}

// Function defs.

// Simple function:
// no arguments, what would be between the parens
// no return value, the "void"
void print_hello(){
    printf( "Hello World\n" );
}

// Simple function:
// 1 argument, the "int x" between the parens.
// no return value, the "void"
void print_number( int x ){
    printf( "%d\n", x );
}

// Simple function:
// 1, argument, the "int x" between the parens.
// a return value, the int - whatever the argument is for the return keyword.
int double_number( int x ){
    return x + x;
}

// Simple function:
// 3, argumenta, the "int ..."s between the parens.
// a return value, the int - whatever the argument is for the return keyword.
int sum_of_three( int x, int y, int z ){
    return x + y + z;
}






