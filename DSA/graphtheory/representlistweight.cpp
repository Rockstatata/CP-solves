#include<bits/stdc++.h>
 
using namespace std;

const int N= 1e3+10;
vector<pair<int,int>>graph[N];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2,wt});
        graph[v2].push_back({v1,wt});
    }
    
    int i = 0,j=0;
    for(pair<int,int> child : graph[i]){
        if(child.first==j){
            //connected;
            //child.second is weight
        }
    }
}