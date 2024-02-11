// Edges to make connected components one component

#include<bits/stdc++.h>
 
using namespace std;

const int N = 20;
vector<int>graph[N];

int vis[N] {0};
int level[N] {0};

void dfs(int n){
    vis[n] = 1;
    for(auto child:graph[n]){
        if(vis[child]) continue;
        dfs(child);
    }
}


void bfs(int n){
    int count=0;
    queue<int>q;
    q.push(n);
    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        if(!vis[cur_v]){
            cout<<cur_v<<" ";
            vis[n]=1;
        }
        for(int child:graph[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child] = level[cur_v]+1;
            }
        }
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,v1,v2;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    vector<int>count;
    for(int i = 1;i<=n;i++){
        if(vis[i]) continue;
         bfs(i);
        count.push_back(i);
    }
    cout<<"edge needed: "<<count.size()-1<<endl;
    for(int i = 0;i<count.size()-1;i++){
        cout<<count[i]<<" "<<count[i+1]<<endl;
    }
    for(int i = 1;i<=n;i++){
        cout<<i<<": "<<level[i]<<endl;
    }

}