#include <stdio.h>
#include <stdlib.h>

struct node{
    int payload;
    struct node * next;
};


int main(){

    struct node * n1 = (struct node *) malloc( sizeof( struct node ) );
    struct node * n2 = (struct node *) malloc( sizeof( struct node ) );
    struct node * n3 = (struct node *) malloc( sizeof( struct node ) );
    n1->payload = 13;
    n1->next = n2;
    n2->payload = 42;
    n2->next = n3;
    n3->payload = 99;
    n3->next = n1;

    printf( "%d\n", n1->payload );
    printf( "%d\n", n2->payload );
    printf( "%d\n", n3->payload );

    printf( "%d\n", n1->payload );
    printf( "%d\n", n1->next->payload );
    printf( "%d\n", n1->next->next->payload );

    printf( "%d\n", n1->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->payload );

    getchar();
    return 0;

}









