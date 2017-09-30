#include <stdio.h>

int main( int argc, char * argv[] ){

    // Basic variable.
    int x = 10;
    // Print the value of the variable.
    printf( "The value of x is: %d\n",  );
    // Print the address of the variable.
    printf( "The address of x is: %p\n", &x );

    // Create a pointer and assign it to the ADDRESS of the variable x.
    int * pointer = &x;
    // Print the address of the pointer it self. It is just another
    // variable afterall.
    printf( "The address of pointer is: %p\n", &pointer );
    // Print the value held in the pointer. This is not the value pointed to.
    printf( "The actual value held in pointer is: %p\n", pointer );
    // This is the value you seek, The value pointed to by the pointer.
    printf( "The value pointed to is %d\n", *pointer );
    
    getchar();
    return 0;

}
