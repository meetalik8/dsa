#include <stdio.h>
#include <stdlib.h>
#define size 3
struct queue{
    int front,rear;;
    int a[size];
}s1;
void enq(){
    int x;
    if(s1.rear==size-1)
    {
        printf("\nqueue full \n");
        return;
    }
    printf("enter element to insert: ");
    scanf("%d",&x);
    s1.rear++;
    s1.a[s1.rear]=x;
    if(s1.front==-1){
        s1.front++;
        return;
    }
    return;
}
void deq(){
    if(s1.rear==-1){
        printf("\n queue underflow\n");
    }
    else{
    printf("\ndeleted element is: \n");
    printf("%d",s1.a[s1.front]);
    s1.front++;
    s1.rear
    }
    return;
}
void display(){
    if(s1.rear==-1)
    {
        printf("\n queue underflow\n");
    }
    else if(s1.front==s1.rear==-1){
        printf("\n stack is empty");
    }
    else{
    printf("\n the queue is:\n");
    for(int i=s1.front;i<=s1.rear;i++){
        printf("%d \t",s1.a[i]);
    }
    }
}
void main(){
    s1.front=-1;
    s1.rear=-1;
    int choice=0;
    while(choice!=4)
    {
        printf("\n make a choice \n");
        printf("1.enqueue  2.dequeue ;  3.display  4.exit ");
        scanf("%d",&choice);
        switch(choice){
            case 1:enq();
                   break;
            case 2:deq();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            case 5: default: printf("\n make a right choice.");
        }
    }
}
