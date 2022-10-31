#include <stdio.h>
#include<stdlib.h>
void main(){
    int a[10];
    int i,j,k,temp,n;
    printf("enter no of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\n enter element  to insert: ");
        scanf("%d",&a[i]);
    }
    for(k=1;k<n;k++){
        temp=a[k];
        j=k-1;
        if(j>=0 && temp<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for(i=0;i<n;i++){
        printf("%d, ",a[i]);
    }
}
