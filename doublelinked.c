#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;

void display(){
    struct node*hpptr=NULL;
    hpptr= head;
    if(head==NULL)
    { printf("\nList is empty \n");
        return;
    }
  while (hpptr!=NULL)
   {
    printf("%d \n",hpptr->data);
    hpptr= hpptr->next;
   }
   return;
} 
void insert(int x)
{
   struct node *pnew,*hpptr;
   pnew=(struct node *)malloc(sizeof(struct node));
   pnew->data=x;
   pnew->next=NULL;
   pnew->prev=NULL;
   
   if(head==NULL)
   {
       head=pnew;
       return;
   }
   //this is for insert beginning
   if(head->data>x)
   {
       pnew->next=head;
       head->prev=pnew;
       head=pnew;
       return;
   }
   hpptr=head;
   //for end or in between
   while(hpptr->next !=NULL && hpptr->next->data <x)
   hpptr=hpptr->next;
   //4 adjustments for double
   pnew->next=hpptr->next;
   if(hpptr->next!=NULL)
   //this would cause segmentation error without the if condition
   hpptr->next->prev=pnew;
   hpptr->next=pnew;
   pnew->prev=hpptr;
   return;
}
void delete1(int x){
    struct node *temp,*hpptr;
    if (head==NULL)
    {
        printf("List is empty nothing to delete");
        return;
    }
    if (head->data==x)
    { 
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        return;
    }
    hpptr=head;
    while(hpptr->next!=NULL && hpptr->next->data!=x)
    hpptr=hpptr->next;
    if(hpptr->next=NULL)
    {
        printf("\n element not found");
        return;
    }
    temp= hpptr->next;
    hpptr->next=temp->next;
    temp->next->prev=hpptr;
    free(temp);
    return;
    
}

int main(){
 display();  
 insert(10);
 insert(5);
 insert(30);
 insert(40);
 insert(20);
 insert(2);
 insert(100);
 display();
 delete1(105);
 delete1(35);
 delete1(30);
 delete1(100);
 delete1(2);
 display();
}
