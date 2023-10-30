#include<bits/stdc++.h>
 
using namespace std;

void printvec(vector<pair<int,int>>&v){
    cout<<"size: "<<v.size()<<endl;
    for(int i = 0;i<v.size();i++){
        // v.size() -> O(1)
        cout<<v.at(i).first<<" "<<v.at(i).second<<endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int,int>>v={{1,2},{2,3},{3,4}};//to initialize multiple values we use second bracket
    printvec(v);
    int n,x,y;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        v.push_back({x,y});
        v.push_back(make_pair(x,y));
    }
    printvec(v);
    
}