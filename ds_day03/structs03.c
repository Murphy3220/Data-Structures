#include <stdio.h>
#include <stdlib.h>

struct point{
    int x;
    int y;
};

void print_point( struct point * );

struct point * construct_point( int, int );

int main(){

    struct point * p1;
    p1 = ( struct point * )malloc( sizeof( struct point ) );
    p1->x = 11;
    p1->y = 22;
    print_point( p1 );

    free( p1 );
    p1 = NULL;
    //print_point( p1 );

    malloc( sizeof( int ) * 100 );

    p1 = ( struct point * )malloc( sizeof( struct point ) );
    p1->x = 11;
    p1->y = 22;
    print_point( p1 );

    struct point * p2 = construct_point( 44, 55 );
    print_point( p2 );
    struct point * p3 = construct_point( 77, 88 );
    print_point( p3 );
    free( p2 );
    print_point( p3 );

    getchar();
    return 0;

}

void print_point( struct point * p ){
    printf("x: %d,\ty:%d\taddress: %p\n", p->x, p->y, p );
}

struct point * construct_point( int a, int b ){
    struct point * temp;
    temp = (struct point *) malloc( sizeof( struct point ) );
    temp->x = a;
    temp->y = b;
    return temp;
}









