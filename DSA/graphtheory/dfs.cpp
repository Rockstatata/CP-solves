#include<bits/stdc++.h>
 
using namespace std;

const int N = 1e5+10;
bool vis[N];
vector<int> g[N];

void dfs(int vertex){
    // Take action on vertex after entering the vertex
    // just entered the child from parent 
    //if(vis[vertex]) return;
    cout<<vertex<<endl;
    vis[vertex]=true;
    for(auto child: g[vertex]){
        cout<<"Par "<<vertex<<", child"<< child <<endl;
        if(vis[child]) continue;
        // Take action on child before entering the child node 
        dfs(child);
        // Take action on child after exiting child node

    }
    // Take action on vertex before exiting the vertex

}

// Time Complexity => O(V+E)
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<9;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
}