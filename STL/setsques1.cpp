#include<bits/stdc++.h>

/*
Given N strings, print unique strings in
lexiographical order
N <= 10^5
|S| <= 100000
*/

using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<string>s;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string str;
        cin>>str;
        s.insert(str);
    }
    for(auto value:s){
        cout<<value<<endl;
    }
}