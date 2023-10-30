#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string x,y;
    cin>>x>>y;
    long long int a = stol(x);
    reverse(y.begin(),y.end());
    long long int b = stol(y);
    long long int res =a+b;
    cout<<res<<endl;
}