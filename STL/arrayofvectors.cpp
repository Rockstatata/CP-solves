#include<bits/stdc++.h>
 
using namespace std;

void printvec(vector<int>&v){
    cout<<"size: "<<v.size()<<endl;
    for(int i = 0;i<v.size();i++){
        // v.size() -> O(1)
        cout<<v.at(i)<<endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>v[10]; // 10 vectors, 2D array of vectors
    int n,x,len;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>len;
        for(int j = 0;j<len;j++){
            cin>>x;
            v[i].push_back(x);
        }
    }
    for(int i = 0;i<n;i++){
        printvec(v[i]);
    }
}