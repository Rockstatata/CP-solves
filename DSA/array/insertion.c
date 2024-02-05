#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<strings.h>

void insert(int arr[],int n,int x,int i){
    printf("Before\n");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int j = n-1;j>=i;j--){
        arr[j+1]=arr[j];
    }
    arr[i]=x;
    printf("After\n");
    for(int i = 0;i<=n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void delete(int arr[],int n,int i){
    printf("Before\n");
    for(int i = 0;i<n+1;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int j = i;j<n;j++){
        arr[j]=arr[j+1];
    }
    arr[n]=0;
    printf("After\n");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

 
int main(){
    int n,x,i;
    scanf("%d",&n);
    int arr[n+1];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Write the element you want to insert and the position\n");
    scanf("%d %d",&x,&i);
    insert(arr,n,x,i);
    printf("Write the element you want to delete\n");
    scanf("%d",&i);
    delete(arr,n,i);
}