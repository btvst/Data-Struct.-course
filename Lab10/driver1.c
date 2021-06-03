#include "1.h"

int main(int argc, char *argv[]){
	FILE *fptr = fopen(argv[1],"r");
	int ele;
	node *root=NULL;

	while(fscanf(fptr,"%d\n",&ele)!=EOF){
		//printf("%d\n",ele);
		root = add(root,ele);
	}
	
	int op=1;
	while(op!=0){
		printf("(1)Inorder trav:\n(2)Find a key:\n(3)Get parent of a node:\n(4)Delete a node:\n");
		scanf("%d",&op);
		switch(op){
			case 1:
			{
				inorder(root);
				printf("\n");
				break;
			}
			case 2:
			{
				int key;
				printf("Enter search key:\n");
				scanf("%d",&key);
				node *ans = find(root, key);
				if(!ans){
					printf("Node not found\n");
				}
				else{
					printf("%d found\n",ans->value);
				}
				break;
			}
			case 3:
			{
				int key;
				printf("Enter child key:\n");
				scanf("%d",&key);
				node *ans=find(root,key);
				node *par=NULL;
				if(ans != NULL){
					par=getParent(root, ans);
				}
				if(par != NULL){
					printf("Parent node value: %d\n",par->value);
				}
				else{
					if(root == NULL){
						printf("Tree is empty\n");
					}
					else if(ans == NULL){
						printf("Tree does not contain %d\n",key);
					}
					else{
						printf("%d is the root node\n",ans->value);
					}
				}
				break;
			}
			case 4:
			{
				int key;
				printf("Enter node to be deleted:\n");
				scanf("%d",&key);
				root = deleteNode(root,key);
				printf("%d deleted\n",key);
				break;
			}				
			default:
			{
				break;
			}
		}

		printf("Perform operation again (1-Yes/0-No):\n");
		scanf("%d",&op);
	}
}
