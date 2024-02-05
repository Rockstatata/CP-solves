#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr [] {1,1,2,3,3,3,3,4,5};
    int len = 9,x=3,mid;
    int l1 = 0,r1=len-1;
    while(l1<=r1){
        mid=(l1+r1)/2;
        if(x<=arr[mid]){
            r1=mid-1;
        }
        else{
            l1=mid+1;
        }
    }
    int l2=0,r2=len-1;
    while(l2<=r2){
        mid = (l2+r2)/2;
        if(x>=arr[mid]){
            l2=mid+1;
        }
        else{
            r2=mid-1;
        }
    }
    cout<<l1<<" "<<r2<<endl;
}