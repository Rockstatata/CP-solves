#include<bits/stdc++.h>
 
using namespace std;

int fun(int n){
    if(n>100){
        return n-10;
    }
    else{
        return fun(fun(n+11));
        
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fun(95)<<endl;
}