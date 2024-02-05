// Ternary Search

/*

There will be 2 mids

mid1 = l+((r-l)/3)
mid2 = r-((r-l)/3)

so, if, r= 12, l = 0 => mid1 = 4, mid2 = 8

5 conditions:
while l<=r {
    if key==mid1  {

    }
    if key==mid2 {

    }
    if key<mid1  (in the left most half ) {
        r = mid1-1;
        mid1 = l+(r-l)/3  => 1
        mid2 = l+(r-l)/3  => 2
    }
    if key>mid2  (in the right most half) {
        l = mid2+1;
    }
    else         (in the middle) {
        l = mid1+1;
        r = mid2-1;
    }

}

*/

#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[] {7,12,19,24,31,48,51,63,67,73,81,92};
    int key = 49;
    int l=0,r=11,res=-1;
    while(l<=r){
        int mid1=l+(r-l)/3;
        int mid2=r-(r-l)/3;
        if(arr[mid1]==key){
            res=mid1;
            cout<<res<<endl;
            break;
        }
        if(arr[mid2]==key){
            res=mid2;
            cout<<res<<endl;
            break;
        }
        if(arr[mid1]>key){
            r=mid1-1;
        }
        else if(arr[mid2]<key){
            l=mid2+1;
        }
        else{
            l=mid1+1;
            r=mid2-1;
        }
    }
    if(res==-1){
        cout<<"Not present"<<endl;
    }
}