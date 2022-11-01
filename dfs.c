/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#define size 6
struct stack{
    int top;
    int a[size];
}s1;
int adj[size][size];
int vis[size];
void push(int x){
    s1.top++;
    s1.a[s1.top]=x;
    return;
}
int pop(){
    int t=s1.a[s1.top];
    s1.top--;
    return t;
}
void dfs(int s){
    push(s);
    vis[s]=1;
    int p =pop();
    if(p!=0)
    printf("%d \t",p);
    while(p!=0){
        for(int i=1;i<=size;i++){
            if(adj[p][i]==1&&vis[0]){
                push(i);
                vis[i]=1;
            }
        }
        p=pop();
        if(p!=0)
    printf("%d \t",p);
    }
}
void main(){
    int sp,ep,nodes,edges,i,j,sv;
    printf("nodes: ");
    scanf("%d",&nodes);
    printf("\nedges: ");
    scanf("%d",&edges);
    for(i=0;i<=size;i++){
        for(j=0;j<=size;j++){
        adj[i][j]=0;
    }
    }
    for(i=0;i<=size;i++){
        vis[i]=0;
    }
    for(i=1;i<=edges;i++){
    printf("starting: ");
    scanf("%d",&sp);
    printf("\n ending");
    scanf("%d",&ep);
    adj[sp][ep]=1;
    adj[ep][sp]=1;
}
printf("\n matrix is \n");
 for(int i=1;i<=size;i++)
    {
        printf("\n");
        for(int j=1;j<=size;j++)
        {
            printf("%d\t",adj[i][j]);
        }
    }
    printf("source vertex \n");
    scanf("%d",&sv);
    dfs(sv);
}
