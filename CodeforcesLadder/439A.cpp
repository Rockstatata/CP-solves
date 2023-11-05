#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,d,time=0,count=0;
    cin>>n>>d;
    int songs[n];
    for(int i=0;i<n;i++){
        cin>>songs[i];
    }
    for(int i = 0;i<n-1;i++){
        time+=songs[i]+10;
        if(time>d){
            cout<<-1<<endl;
            return 0;
        }
        else{
            count+=2;
        }
    }
    time+=songs[n-1];
    if(time>d){
        cout<<-1<<endl;
        return 0;
    }
    else{
        count+=((d-time)/5);
        cout<<count<<endl;
    }
}