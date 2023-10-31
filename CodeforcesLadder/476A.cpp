#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,low,high,mov;
    cin>>n>>m;
    low=ceil(n/2.0);
    high=n;
    mov=low;
    if(low%m==0){
        cout<<mov<<endl;
    }
    else{
        while(mov%m!=0){
            mov++;
            if(mov>high){
                cout<<-1<<endl;
                return 0;
            }
        }
        cout<<mov<<endl;
    }
}