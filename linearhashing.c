#include <stdio.h>
void display(int arr[],int n){
    for(int i=0;i<n;i++)
    printf("%d \n",arr[i]);
}
void hashing(int table[], int m, int n,int arr[]){
   for(int i=0;i<n;i++){
    int k=(arr[i])%m;
    if(table[k]==-1){
        table[k]=arr[i];
    }
    else{
        for(int j=0;j<m;j++){
            int t=(k+j)%m;
        if(table[t]==-1){
            table[t]=arr[i];
            break;
        }
      }
    }
  }
  display(arr,n);
}

void main(){
    int arr[] = {50, 700, 76, 85, 92, 73, 101,97,95,83};
    int n=10;
    int m=10;
    int hasht[10];
    for(int i=0;i<m;i++){
        hasht[i]==-1;
    }
    hashing(hasht,m,n,arr);
}
