#include<bits/stdc++.h>
 
using namespace std;

const int N = 20;
vector<int>graph[N];

int vis[N] {0};
int level[N] {0};
vector<int>countt(N,0);

void dfs(int n){
    vis[n] = 1;
    for(auto child:graph[n]){
        
        if(vis[child]) continue;
        dfs(child);
    }
}


void bfs(int n){
    int count=0;
    for(int i = 1;i<=n;i++){
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int cur_v = q.front();
            q.pop();
            if(!vis[cur_v]){
                cout<<cur_v<<" ";
                countt.push_back(cur_v);
                vis[i]=1;
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
    for(int i = 0;i<n-1;i++){
        cout<<countt[i]<<" "<<countt[i+1]<<endl;
    }
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
    bfs(n);
    for(int i = 1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
        countt.push_back(i);
    }
    for(int i = 1;i<=n;i++){
        cout<<i<<": "<<level[i]<<endl;
    }

}