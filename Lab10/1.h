#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node *left;
	struct Node *right;
	int bal: 2;
};

typedef struct Node node;

struct Tree{
	node *root;
};

typedef struct Tree tree;

node *add(node* root, int key);
/* adds node x in the tree root*/

node *find(node *root, int key);
/* returns the first found node containing key */

node *deleteNode(node *root, int key);
/* deletes 1 node containing key */

void inorder(node *root);

node *newNode(int x);

node *getParent(node *root, node *x);

node *findMin(node *root);
