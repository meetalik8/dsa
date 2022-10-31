#include <stdio.h>
#include <stdlib.h>
// #define size 5
struct node{
    int data;
    struct node *next;
    // int a[size];
};
 struct node *head=NULL;
void insert(){
    int x;
    struct node *pnew, *hpptr;
    printf("enter element to insert: ");
    scanf("%d",&x);
    pnew=(struct node *)malloc(sizeof(struct node));
    pnew->data=x;
    pnew->next=NULL;
    if(head==NULL)
    {
        head=pnew;
        return;
    }
    if(head->data>x){
        pnew->next=head;
        head=pnew;
        return;
    }
    hpptr=head;
    while(hpptr->next!=NULL &&hpptr->next->data<x){
        hpptr=hpptr->next;
        pnew->next=hpptr->next; 
        hpptr->next=pnew;
    }
}
void delete(){
    int x;
    struct node *hpptr=NULL;
    struct node *pnew,*temp;
    printf("enter element to delete: ");
    scanf("%d",&x);
    pnew=(struct node *)malloc(sizeof(struct node));
    pnew->data=x;
    pnew->next=NULL;
    if(head==NULL){
        printf("\n list is EMPTY\n");
        return;
    }
    hpptr=head;
    if(head->data==x){
        temp=head;
        head=head->next;
        free(temp);
        return;
    }
    while(hpptr->next!=NULL&&hpptr->next->data!=x){
        hpptr=hpptr->next;
        if(hpptr->next==NULL){
            printf("\n element not found\n");
            return;
        }
        temp=hpptr->next;
        hpptr->next=temp->next;
        free(temp);
        return;
    }
}
void display(){
    struct node *hpptr=NULL;
     hpptr=head;
    if(head==NULL)
    {
        printf("\n LIST EMPTY\n");
        return;
    }
    printf("\n the list is:\n");
    while(hpptr!=NULL){
        printf("%d \t",hpptr->data);
        hpptr=hpptr->next;
    }
    return;
}
void main(){
    int choice=0;
    while(choice!=4)
    {
        printf("\n make a choice \n");
        printf("1.insert  2.delete  3.display  4.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:insert();
                   break;
           case 2:delete();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            case 5: default: printf("\n make a right choice.");
        }
    }
}
