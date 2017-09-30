#include <stdio.h>

int main( int argc, char * argv[] ){

    // Print a C-String
    printf( "Hello Class!" );

    // Print a C-String with invisible characters.
    // \t = tab
    // \n = newline
    printf( "\nHello\t\tWorld with invisible characters!\n\n" );

    // Print a variable using a format specifier.
    // %d for integers
    int x = 42;
    printf( "Now with a variable: %d\n", x );

    // %f for floating point or double
    float y = 3.12345678912345;
    printf( "A different variable: %f\n", y );
    printf( "The same variable: %.2f\n", y );

    // With padding:
    printf( "We can also pad a value: %5d\n", x );
    printf( "We can also pad a value: %05d\n", x );

    // C-Strings
    char name[ 4 ] = { 'T', 'C', 'C', '\0' };
    printf( "Hello %s", name );

    // You can have several and mixed arguments in the same statement.
    printf( "\nHello %s, the answer to the question\nis %d, and the other number is %f\n", name, x, y );

    // This is here to keep windows happy - so the CMD doesn't
    // blink away.
    getchar();
    
    // Our main function has a return type - usually rather the
    // program terminated successfuly.
    return 0;
}
