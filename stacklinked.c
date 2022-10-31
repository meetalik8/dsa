#include<stdio.h>
#include<stdlib.h>
struct stack {
    int data;
    struct stack *next;
};
 struct stack *top =NULL;
void display() {
    if(top==NULL) {
        printf("No elements present\n");
        return;
    }
    while(top!=NULL) {
        printf("%d \n",(top)->data);
        top=(top)->next;
    }
}
void push(struct stack **top,int x) {
    struct stack *pnew =(struct stack *)malloc(sizeof(struct stack));
    pnew->data =x;
    pnew->next =*top;
    *top =pnew;
}
void pop(struct stack **top) {
    struct stack *temp;
    if(*top==NULL) {
        printf("Stack Underflow\n");
    }
    else {
        temp=*top;
        *top=(*top)->next;
        printf("Popped Element is :%d\n",temp->data);
        free(temp);
    }
}

int main() {
    int choice,val;
    printf("1.Display\n2.Push\n3.Pop\n4.Exit\n");

    while(choice!=4) {
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            display(top);
            break;
        case 2:
            printf("Enter push element :");
            scanf("%d",&val);
            push(&top,val);
            break;
        case 3:
            pop(&top);

            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
