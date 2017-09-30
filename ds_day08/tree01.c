#include <stdio.h>
#include <stdlib.h>

// The basic building block of a binary tree.
struct node{
	char value;
	// Instead of "next" and/or "prev" we use...
	struct node * left;
	struct node * right;
};

void print_node( struct node * );
struct node * insert( struct node *, char );

void print_tree_one( struct node * );
void print_tree_two( struct node * );
void print_tree_three( struct node * );

int main(){

	// This will be the start or base of the tree.
	struct node * root = NULL;
	
	root = (struct node *)malloc( sizeof( struct node ) );
	root->value = 'm';
	root->left = NULL;
	root->right = NULL;

	root->left = (struct node *)malloc( sizeof( struct node ) );
	root->left->value = 'e';
	root->left->left = NULL;
	root->left->right = NULL;
	
	root->right = (struct node *)malloc( sizeof( struct node ) );
	root->right->value = 'x';
	root->right->left = NULL;
	root->right->right = NULL;

	root = insert( root, 'w' );
	root = insert( root, 'z' );
	
	//print_node( root );
	//print_node( root->left );
	//print_node( root->right );
	//print_node( root->right->right );
	//print_node( root->right->left );
	print_tree_one( root );
	printf("*************************************\n");
	print_tree_two( root );
	printf("*************************************\n");
	print_tree_three( root );
}

void print_node( struct node * tree ){
	printf( "The tree's value: %c\n", tree->value );
	printf( "\tThe node's address is: %p\n", tree );
	printf( "\tThe tree's left: %p\n", tree->left );
	printf( "\tThe tree's right: %p\n", tree->right );
}

struct node * insert( struct node * tree, char c ){

	if( !tree ){
		struct node * temp = (struct node *)malloc( sizeof( struct node ) );
		temp->value = c;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}else{
		if( c <= tree->value ){
			tree->left = insert( tree->left, c );
		}else{
			tree->right = insert( tree->right, c );
		}
		return tree;
	}

}

void print_tree_one( struct node * tree ){
	if( !tree ){
		return;
	}
	print_tree_one( tree->left );
	print_node( tree );
	print_tree_one( tree->right );
}

void print_tree_two( struct node * tree ){
	if( !tree ){
		return;
	}
	print_node( tree );
	print_tree_two( tree->left );
	print_tree_two( tree->right );
}

void print_tree_three( struct node * tree ){
	if( !tree ){
		return;
	}
	print_tree_three( tree->left );
	print_tree_three( tree->right );
	print_node( tree );
}















