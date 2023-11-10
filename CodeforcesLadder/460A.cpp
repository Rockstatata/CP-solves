#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,d=0,m=1;
    cin>>a>>b;
    while(a--){
        d++;
        if(b*m==d){
            a++;
            m++;
        }
    }
    cout<<d<<endl;
}