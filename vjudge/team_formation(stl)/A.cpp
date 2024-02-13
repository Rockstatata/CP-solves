#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,x,max = INT_MIN;
    cin>>n>>m;
    vector<set<int>>v;
    set<int>s;
    for(int i = 0;i<n;i++){
        for(int j=  0;j<m;j++){
            cin>>x;
            s.insert(x);
        }
        v.push_back(s);
        s.clear();
    }   
    for(int i = 0;i<n;i++){
        if(*v[i].begin()>=max){
            max = *v[i].begin();
        }
    }
    cout<<max<<endl;
}