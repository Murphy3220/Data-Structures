#include <stdio.h>

struct example{
	double value;
};

int main(){

	int i = 0;

	struct example stuff[ 4 ];

	// Note the use of the dot syntax "." which is used for
	// regular structs and not pointers to structs where
	// we need to use the arrow operator "->"
	stuff[ 0 ].value = 22.2;
	stuff[ 1 ].value = 33.3;
	stuff[ 2 ].value = 44.4;
	stuff[ 3 ].value = 55.5;

	for( i = 0; i < 4; i++){
		// And again for the output we use the dot.
		printf( "The value is: %f\n", stuff[ i ].value );
	}
	
	getchar();
	return 0;
}