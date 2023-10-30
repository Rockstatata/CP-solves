#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>v{2,3,4,5,6,8};
    vector<int>::iterator it;
    for(int &value: v){ // range based loop
        cout<<value<<" ";
    }
    cout<<endl;
    vector<pair<int,int>>v_p={{1,2},{2,3}};
    for(pair<int,int>&value: v_p){
        cout<<value.first<<" "<<value.second<<endl;
    }
    // auto keyword dynamically takes data types
    auto a = 1.0;
    cout<<a<<endl;
    for(auto & value:v_p){
        cout<<value.first<<" "<<value.second<<endl;
    } 
    for(auto &value: v){
        cout<<value<<" ";
    }
}