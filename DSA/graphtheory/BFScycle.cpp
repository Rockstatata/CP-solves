#include<bits/stdc++.h>
 
using namespace std;

bool detectcycle(int n, vector<int> graph[],int vis[],int node,int parent){
    queue<pair<int,int>>q;
    bool cycle = false;
    q.push({node,parent});
    vis[0] = 1;
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        vis[node] = 1;
        q.pop();
        for(int child:graph[node]){
            if(!vis[child]){
                vis[child] = 1;
                q.push({child,node});
            }
            else if(parent!=child){
                cycle = true;
            }
        }
    }
    return cycle;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,x,y,parent=0,cycle=0;
    cin>>n>>m;
    vector<int>graph[n+1];
    int vis[n] {0};
    for(int i = 0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }   
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(detectcycle(n+1,graph,vis,i,parent)){
                cout<<"There's a cycle"<<endl;
                cycle=1;
                break;
            }
        }
    }
    if(!cycle) cout<<"There's no cycle"<<endl;
    
}