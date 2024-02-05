#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int len = 5;
    int *arr = new int[len] {2,4,6,7,8};
    int n;
    cout<<"How many operations do you want to make?"<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        cout<<"Write the element which will be inserted"<<endl;
        int q;
        cin>>q;
        int temp[len+1] {};
        for(int i = 0;i<len;i++){
            temp[i]=arr[i];
        }
        int l = 0, r = len-1;
        int mid = (l+r)/2;
        while(l<=r){
            if(q<=temp[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            mid=(l+r)/2;
        }
        for(int i=len-1;i>=l;i--){
            temp[i+1] = temp[i];
        }
        temp[l]=q;
        delete []arr;
        len++;
        arr = new int[len];
        for(int i = 0;i<len;i++){
            arr[i]=temp[i];
        }
        cout<<"Size of the array: "<<len<<endl;
        for(int i = 0;i<len;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}