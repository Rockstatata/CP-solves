#include<bits/stdc++.h>

/*
Given N strings and Q queries.
In each query you are given a string 
print yes if string is present else 
print no.
N <= 10^6
|S| <= 100
Q <= 10^6
*/
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unordered_set<string>s;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string x;
        cin>>x;
        s.insert(x);
    }
    int q;
    cin>>q;
    while(q--){
        string x;
        cin>>x;
        if(s.find(x)==s.end()){
            cout<<"no\n";
        } 
        else{
            cout<<"yes\n";
        }
    }
}