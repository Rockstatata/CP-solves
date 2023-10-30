#include<bits/stdc++.h>
 
using namespace std;

bool binarysearch(vector<int> &v,int l,int r,int x){
    int m;
    while(l<=r){
        m = (l+r)/2;
        if(v[m]==x){
            return true;
        }
        if(v[m]<x){
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,num;
    cin>>n>>k;
    vector<int>m;
    for(int i = 0;i<n;i++){
        cin>>num;
        m.push_back(num);
    }
    for(int i=0;i<k;i++){
        cin>>num;
        bool result = binarysearch(m,0,n-1,num);
        cout<<((result)?"YES":"NO")<<endl;
    }
}