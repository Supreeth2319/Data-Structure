#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct NODE
{
int data;
struct NODE*next;
};
void push(struct NODE**head_ref,int new_data);
bool ispresent(struct NODE*head,int data);
struct NODE*get_union(struct NODE*head1,struct NODE*head2)
{
  struct NODE*result=NULL;
  struct NODE*t1=head1,*t2=head2;
  while(t1!=NULL)
    {
      push(&result,t1->data);
      t1=t1->next;
    }
  while(t2!=NULL)
    {
      if(!ispresent(result,t2->data))
        push(&result,t2->data);
      t2=t2->next;
    }
  return result;
}
struct NODE*get_intersection(struct NODE*head1,struct NODE*head2)
{
  struct NODE*result=NULL;
  struct NODE*t1=head1;
  while(t1!=NULL)
    {
      if(ispresent(head2,t1->data))
        push(&result,t1->data);
      t1=t1->next;
}
  return result;
}
void push(struct NODE**head_ref,int new_data)
{
  
  struct NODE* new_NODE=(struct NODE*)malloc(sizeof(struct NODE));
  new_NODE->data=new_data;
  new_NODE->next=(*head_ref);
  (*head_ref)=new_NODE;
}
void printlist(struct NODE*NODE)
{
  while(NODE!=NULL)
    {
      printf(" %d ",NODE->data);
      NODE=NODE->next;
}
}
bool ispresent(struct NODE*head,int data)
{
  struct NODE*t=head;
  while(t!=NULL)
    {
      if(t->data==data)
        return 1;
      t=t->next;
    }
  return 0;
}
int main()
{
  struct NODE*head1=NULL;
  struct NODE*head2=NULL;
  struct NODE*intersecn=NULL;
  struct NODE*unin=NULL;
  push(&head1,32);
  push(&head1,17);
  push(&head1,22);
  push(&head1,9);
  push(&head1,16);
  push(&head1,15);
  push(&head1,10);
  push(&head1,7);
  push(&head1,3);
  push(&head1,99);
  push(&head2,28);
  push(&head2,1);
  push(&head2,8);
  push(&head2,37);
  push(&head2,13);
  push(&head2,9);
  push(&head2,02);
  push(&head2,16);
  push(&head2,78);
  intersecn=get_intersection(head1,head2);
  unin=get_union(head1,head2);
  printf("\nfirst list is\n");
  printlist(head1);
  printf("\nsecond list is \n");
  printlist(head2);
  printf("\nintersection list is \n");
  printlist(intersecn);
  printf("\nunion list is \n");
  printlist(unin);
  return 0;
  }
