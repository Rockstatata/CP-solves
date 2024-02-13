#include<bits/stdc++.h>
 
using namespace std;

bool check(int start,int V,vector<int>graph[], int color[]){
    queue<int>q;
    q.push(start);
    color[start]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: graph[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
    }
}

bool isBipartite(int V, vector<int>graph[]){ 
    int color[V+1];
    for(int i = 1;i<=V;i++)color[i]=-1;
    for(int i = 1;i<=V;i++){
        if(color[i]==-1){
            if(check(i,V,graph,color) == false){
                return false;
            }
        }
    }
    return true;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>graph[n+1];
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bool bipartite = isBipartite(n+1,graph);
    if(bipartite){
        cout<<"The graph is bipartite"<<endl;
    }
    else{
        cout<<"It's not bipartite"<<endl;
    }
}