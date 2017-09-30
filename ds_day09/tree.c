#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node * left;
	struct node * right;
};

struct node * insert( struct node *, int );
struct node * create_node( int i );
void print_preorder( struct node * );
void print_in_order( struct node * );
void print_postorder( struct node * );
int find_total( struct node * );
int find_size( struct node * );
struct node * delete_node( struct node *, int );

int main(){

	struct node * root = NULL;
	
	root = insert( root, 50 );
	root = insert( root, 25 );
	root = insert( root, 75 );
	root = insert( root, 1 );
	root = insert( root, 99 );
	root = insert( root, 37 );
	root = insert( root, 66 );

	//print_in_order( root );
	print_preorder( root );
	
	if( search_tree( root, 98 ) == 1 ){
		printf( "Searched for %d and found it!\n", 98 );
	}else{
		printf( "Searched for %d and did not find it!\n", 98 );
	}
	
	if( search_tree( root, 66 ) == 1 ){
		printf( "Searched for %d and found it!\n", 66 );
	}else{
		printf( "Searched for %d and did not find it!\n", 66 );
	}	
	
	printf( "The total is: %d\n", find_total( root ) );
	
	printf( "There are %d nodes in the tree!\n", find_size( root ));
	
	printf( "Testing Delete\n" );
	root = delete_node( root, 50 );
	print_in_order( root );
	
	getchar();
	return 0;

}

struct node * create_node( int i ){
	struct node * temp = ( struct node * )malloc( sizeof( struct node ) );
	temp->value = i;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * insert( struct node * root, int i ){
	if( root == NULL ){
		return create_node( i );
	}else{
		if( i <= root->value ){
			root->left = insert( root->left, i );
		}else{
			root->right = insert( root->right, i );
		}
		return root;
	}
}

void print_in_order( struct node * root ){
	if( !root ){
		return;
	}
	print_in_order( root->left );
	printf( "Value: %d, Address: %p, Left: %p, Rigth: %p\n", root->value, root, root->left, root->right );
	print_in_order( root->right );
}

void print_preorder( struct node * root ){
	if( !root ){
		return;
	}
	printf( "Value: %d, Address: %p, Left: %p, Rigth: %p\n", root->value, root, root->left, root->right );
	print_preorder( root->left );
	print_preorder( root->right );
}

void print_postorder( struct node * root ){
	if( !root ){
		return;
	}
	print_postorder( root->left );
	print_postorder( root->right );
	printf( "Value: %d, Address: %p, Left: %p, Rigth: %p\n", root->value, root, root->left, root->right );
}

int search_tree( struct node * root, int target ){
	if( !root ){
		return -1;
	}else if( target < root->value ){
		return search_tree( root->left, target );
	}else if( target > root->value ){
		return search_tree( root->right, target );
	}else{
		return 1;
	}
}

int find_total( struct node * root ){
	if( !root ){
		return 0;
	}
	return root->value + find_total( root->left ) + find_total( root->right ) ;
}

int find_size( struct node * root ){
	if( !root ){
		return 0;
	}
	return find_size( root->left ) + 1 + find_size( root->right );
}


// This function DOES NOT WORK. TURN IN A WORKING EXAMPLE BEFORE THE
// NEXT CLASS PERIOD AND YOU WILL RECIEVE  25 EXTRA CREDIT POINTS!
struct node * delete_node( struct node * root, int target ){
	struct node * temp_a;
	struct node * temp_b;
	if( !root ){
		return root;
	}else{
		if( root->value == target ){
			// Do the deletion.
			if( root->left == root->right ){
				free( root );
				return NULL;
			}else if( root->left == NULL ){
				temp_a = root->right;
				free( root );
				return temp_a;
			}else if( root->right == NULL ){
				temp_a = root->left;
				free( root );
				return temp_a;
			}else{
				temp_a = root->right;
				temp_b = NULL;
				while( temp_a->left ){
					temp_b = temp_a;
					temp_a = temp_a->left;
				}
				root->value = temp_a->value;
				if( temp_b != NULL ){
					root = delete_node( temp_b->left, temp_b->left->value );
				}else{
					root = delete_node( root->right, root->right->value );
				}	
			}
		}else if( root->value < target ){
			root->right = delete_node( root->right, target );
		}else{
			root->left = delete_node( root->left, target );
		}
	}
}

















