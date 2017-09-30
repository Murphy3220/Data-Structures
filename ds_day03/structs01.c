#include <stdio.h>

struct point{
    int x;
    int y;
};

typedef struct dot{
    int x;
    int y;
}dot;

void print_point( struct point );
void print_dot( dot );

int main(){

    printf( "Hello Structs!\n" );

    struct point p1;
    p1.x = 11;
    p1.y = 22;
    
    print_point( p1 );

    printf( "A point is of size: %d\n", sizeof( struct point ));

    dot d1;
    d1.x = 111;
    d1.y = 222;

    print_dot( d1 );
    printf( "A dot is of size: %d\n", sizeof( dot ));


    getchar();
    return 0;

}

void print_point( struct point p ){
    printf("x: %d,\ty:%d\n", p.x, p.y );
}

void print_dot( dot d ){
    printf("x: %d,\ty:%d\n", d.x, d.y );
}










