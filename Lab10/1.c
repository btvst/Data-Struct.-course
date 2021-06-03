#include "1.h"

void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		printf(" %d ",root->value);
		inorder(root->right);
	}
}

node *add(node *root, int key){
	if(root==NULL){
		return newNode(key);
	}

	if(key<root->value){
		root->left=add(root->left,key);
		return root;
	}
	else if(key>=root->value){
		root->right=add(root->right,key);
		return root;
	}
}

node* newNode(int key){
	node *temp=(node*)malloc(sizeof(node));
	temp->value = key;
	temp->left=NULL;
	temp->right=NULL;
	temp->bal=0; //Change this

	return temp;
}

node *find(node *root, int key){
	node *temp=NULL;

	if(!root){
		return temp;
	}
	else if(root->value == key){
		temp=root;
	}
	else if(root->value < key){
		temp=find(root->right, key);
	}
	else if(root->value > key){
		temp=find(root->left, key);
	}

	return temp;
}


node *getParent(node *root, node *x){
	//node *ans=find(root,x->value);

	if(root==x || x==NULL || root==NULL){
		return NULL;
	}
	else{
		node *temp=root;
		if(temp->value > x->value){
			if(x==temp->left){
				return temp;
			}
			getParent(temp->left,x);
		}
		else if(temp->value <= x->value){
			if(x==temp->right){
				return temp;
			}
			getParent(temp->right,x);
		}
	}
}

node *deleteNode(node *root, int key){
	node *temp=root;
	if(temp==NULL)	return NULL;
	else if(temp->value < key){
		temp->right=deleteNode(temp->right, key);
	}
	else if(temp->value > key){
		temp->left=deleteNode(temp->left,key);
	}
	else{
		if(temp->left==NULL && temp->right==NULL){
			free(temp);
			return NULL;
		}
		else if(temp->left==NULL){
			node *temp1=temp;
			temp=temp->right;
			free(temp1);
		}
		else if(temp->right==NULL){
			node *temp1=temp;
			temp=temp->left;
			free(temp1);
		}
		else{
			node *temp1=findMin(temp->right);
			temp->value=temp1->value;
			temp->right = deleteNode(root->right,temp->value);
		}
	}
	return temp;
}

node *findMin(node *root){
	if(root!=NULL){
		while(root->left!=NULL){
			root=root->left;
		}
		return root;
	}
}
