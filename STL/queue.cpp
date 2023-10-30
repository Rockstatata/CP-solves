#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<string>q;
    q.push("abc");
    q.push("bcd");
    q.push("cde");
    q.push("def");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}