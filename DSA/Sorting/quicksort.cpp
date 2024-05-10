#include<bits/stdc++.h>

using namespace std;

void swap(int& x,int& y)
{
    int temp=x;
    x=y;
    y=temp;
}

int partition(int A[],int l,int h)
{
    int pivot;
    // First Element Pivoting
    //pivot=A[l];

    // Middle Element Pivoting
    int mid = (l+h)/2;
    pivot = A[mid];

    // Randomize Pivoting 
    //int rad = l+ (rand() % (h-l-1));
    //pivot = A[rad];
 
    int i=l,j=h;
    
    do
    {
        do{
            i++;
        }
        while(A[i]<=pivot);
        do{
            j--;
        }
        while(A[j]>pivot);
        
        if(i<j)swap(A[i],A[j]);
    }
    while(i<j);
    
    swap(A[l],A[j]);
    return j;
}
void QuickSort(int A[],int l,int h)
{
    int j;
    if(h==1){
        return;
    }
    if(l<h)
    {
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
} 

int main()
{
    int A[]={11,2,5},n=3,i;
    
    QuickSort(A,0,n);
    
    for(i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    
    return 0;
}