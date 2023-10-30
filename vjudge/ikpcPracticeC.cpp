#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,count=0,flag=0;
    char c;
    cin>>n;
    queue<char>q;
    vector<char>v;
    for(int i = 0;i<n;i++){
        cin>>c;
        if(c=='"')count++;
        q.push(c);
    }
    for(int i = 0;i<n;i++){
        c=q.front();
        q.pop();
        if(c=='"'){
            count--;
        }
        if(c==',' && count%2==0){
            v.push_back('.');
        }
        else{
            v.push_back(c);
        }
    }
    for(int i = 0;i<n;i++){
        cout<<v[i];
    }

}