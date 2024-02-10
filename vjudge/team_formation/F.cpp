#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,x,y;
    cin>>n>>x>>y;
    long long time = x, count=1,res=0, countx=x;
    while(count<n){
        time+=y;
        if(y%x){
            res=1;
        }
        count+=(1+(y/x));
        countx--;
        if(res && countx==0){
            count++;
            res=0;
            countx=x;
        }
    }
    if(count>n){
        time-=(((count-n)/2)*x);
    }
    cout<<time<<endl;
}