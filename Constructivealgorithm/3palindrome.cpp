#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    for(int i = 0;i<200000/4;i++){
        s+="aa";
        s+="bb";
    }   
    cout<<s.substr(0,n)<<endl;
}