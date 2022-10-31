#include <stdio.h>
#include <stdlib.h>
#define size 5
struct stack{
    int top;
    int a[size];
}s1;
void push(){
    int x;
    if(s1.top==size-1)
    {
        printf("\nStack full \n");
        return;
    }
    printf("enter element to insert: ");
    scanf("%d",&x);
    s1.top++;
    s1.a[s1.top]=x;
    return;
}
void pop(){
    if(s1.top==-1){
        printf("\n stack underflow\n");
        return;
    }
    while(s1.top!=-1){
    printf("\ndeleted element is: \n");
    printf("%d",s1.a[s1.top]);
    s1.top--;
    }
    return;
}
void display(){
    if(s1.top==-1)
    {
        printf("\n stack underflow\n");
    }
    printf("\n the stack is:\n");
    for(int i=s1.top;i>=0;i--){
        printf("%d \n",s1.a[i]);
    }
}
void main(){
    s1.top=-1;
    int choice=0;
    while(choice!=4)
    {
        printf("\n make a choice \n");
        printf("1.push  2.pop  3.display  4.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            case 5: default: printf("\n make a right choice.");
        }
    }
}
