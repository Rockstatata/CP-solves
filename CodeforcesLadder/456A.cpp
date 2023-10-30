#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y,w,z,count=0;
    cin>>n;
    //pair<pair<int,int>,pair<int,int>>p;
    for(int i = 0;i<n;i+=2){
        cin>>x>>y;
        cin>>w>>z;
        if(x<w && y>z){
            count+=2;
        }
    }
    if(n==count){
        cout<<"Happy Alex"<<endl;
    }
    else{
        cout<<"Poor Alex"<<endl;
    }

}