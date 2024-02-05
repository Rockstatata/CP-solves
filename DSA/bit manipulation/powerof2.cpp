#include<bits/stdc++.h>
 
using namespace std;

bool powerof2(int n){
    return (n&n-1)?0:1;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n=16;
    int res = powerof2(n);
    if(res==1){
        cout<<"Power of 2"<<endl;
    }
    else{
        cout<<"Not Power of 2"<<endl;
    }
}