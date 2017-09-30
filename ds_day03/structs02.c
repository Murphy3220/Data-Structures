#include <stdio.h>

struct point{
    int x;
    int y;
};

void print_point( struct point );

int main(){


    struct point points[ 3 ];
    points[ 0 ].x = 11;
    points[ 0 ].y = 22;
    points[ 1 ].x = 33;
    points[ 1 ].y = 44;
    points[ 2 ].x = 55;
    points[ 2 ].y = 66;

    int i = 0;
    for( i = 0; i < 3; i++ ){
        print_point( points[ i ] );
    }

    getchar();
    return 0;

}

void print_point( struct point p ){
    printf("x: %d,\ty:%d\n", p.x, p.y );
}











