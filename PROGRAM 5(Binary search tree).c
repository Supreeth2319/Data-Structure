#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};

typedef struct node *NODE;


NODE insert(int item,NODE root)
{
	NODE temp,cur,prev;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;
	if(root==NULL)
               {
		return temp;
                }
	prev=NULL;
	cur=root;
	while(cur!=NULL)
	{
		prev=cur;
	    	if(item==cur->info)
		{
			printf("Duplicate item are not allowed\n");
			free(temp);
			return root;
		}
		if(item<cur->info)	
                 cur=cur->llink;
		else			
                 cur=cur->rlink;
	}
	if(item<prev->info)
		prev->llink=temp;
	else
		prev->rlink=temp;
	return root;
}

NODE search(int item, NODE root)
{
	NODE cur;
      cur=root;
	if(root==NULL)
      return NULL;
	while(cur!=NULL)
	{
		if(item==cur->info)
                 {
                     printf("key  found");
                      return root;
                  }              
		if(item<cur->info)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
      if( cur==NULL)
      printf("key not found");
	return root;
}



void inorder(NODE root)
{
	if(root==NULL) return;
	inorder(root->llink);
	printf("%d\t",root->info);
	inorder(root->rlink);
}

void preorder(NODE root)
{
	if(root==NULL) return;
	printf("%d\t",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}

void postorder(NODE root)
{
	if(root==NULL) return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d\t",root->info);
  }

void main()
{
	int item,ch,n;
	NODE root=NULL;
	while (1)
	{
	printf("\nEnter thechoice\n1.Insert\n2.Search\n3.Inorder\n4.Preorder\n5.Postorder \n6:Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
    			case 1:
				printf("Enter the number of items\n");
				scanf("%d",&n);
				printf("Enter the item to be inserted\n");
				root=insert(item,root);
				break;
                        case 2 :	
                                printf("Enter the item to be searched\n");
			        scanf("%d",&item);
				root=search(item,root);
				break;
			case 3:
           			if(root==NULL)
				{
					printf("Tree is empty\n");
					break;
				}
				printf("Inorder traversal is \n");
				inorder(root);
				printf("\n");
				break;

			case 4: if(root==NULL)
				{
					printf("Tree is empty\n");
					break;
				}
				printf("Preorder traversal is \n");
				preorder(root);
				printf("\n");
				break;
			
			case 5: if(root==NULL)
				{
					printf("Tree is empty\n");
					break;
				}
				printf("Postorder traversal is \n");
				postorder(root);
				printf("\n");
				break;
			
			case 6: exit(0);
			default: printf("Enter valid choice\n");
		}
	}
}
