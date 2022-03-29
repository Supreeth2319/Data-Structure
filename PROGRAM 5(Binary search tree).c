#include<stdio.h>
#include<stdlib.h>
struct node
{
char info;
struct node*llink,*rlink;
};
typedef struct node*node;
node insert(int item,node root)
{
  node temp,prev,cur;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->llink=temp->rlink=NULL;
  temp->info=item;
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
        printf("duplicate element is not allowed\n");
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
node search(int item,node root)
{
  node cur;
  cur=root;
  while(cur!=NULL)
    {
      if(item==cur->info)
      {
        printf("key found");
        return root;
      }
      if(item<cur->info)
        cur=cur->llink;
      else
        cur=cur->rlink;
    }
  if(cur==NULL)
    printf("key not found");
  return root;
}
void preorder(node root)
{
  if(root==NULL)return;
  printf("%d\t",root->info);
  preorder(root->llink);
  preorder(root->rlink);
}
void postorder(node root)
{
  if(root==NULL)return;
  postorder(root->llink);
  postorder(root->rlink);
  printf("%d\t",root->info);
  
}
void inorder(node root)
{
  if(root==NULL)return;
  inorder(root->llink);
  printf("%d\t",root->info);
  inorder(root->rlink);
}
int main()
{
  int ch,item;
  node root=NULL;
  while(1)
    {
      printf("\n1.insert\n\t2.search\n\t3.preorder\n\t4.postorder\n\t5.inorder\n\n");
printf("enter your choice\n");
      scanf("%d",&ch);
      switch(ch)
        {
          case 1:printf("enter item");
          scanf("%d",&item);
          root=insert(item,root);
          break;
          case 2:printf("enter item to be searched");
          scanf("%d",&item);
          root=search(item,root);
          break;
          case 3:if(root==NULL)
          {
            printf("tree empty");
          }
          else
          {
            printf("preorder traversal");
            preorder(root);
          }
          break;
          case 4:if(root==NULL)
          {
            printf("tree empty");
          }
          else
          {
            printf("postorder traversal");
            postorder(root);
        }
          break;
          case 5:if(root==NULL)
          {
            printf("tree empty");
          }
          else
          {
            printf("inorder traversal");
            inorder(root);
    }
          break;
          default: exit(0);
}
      }
  }
