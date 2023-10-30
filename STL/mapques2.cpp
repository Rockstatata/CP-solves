#include<bits/stdc++.h>

/* Given N strings and Q queries.
In each query you are given a string 
print frequency of that string
N<= 10^6
|S| <= 100
Q <= 10^6
*/
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string,int>m;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        m[s]++;
    }
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        cout<<m[s]<<endl;
    }
}