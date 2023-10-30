#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num,count =0;
    cin>>num;
    while(num>0){
        if(num & 1){
            count++;
        }
        num>>=1;
    }
    cout<<count<<endl;
}