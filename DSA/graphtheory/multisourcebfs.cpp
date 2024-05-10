#include<bits/stdc++.h>
 
using namespace std;

const int N = 1e5+10;
vector<int>g[N];

int vis[N];
int level[N];
queue<int>q;

void bfs(int source){
    vis[source]=1;  
    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        cout<<cur_v<<" "; 
        for(int child:g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v]+1;
            }
        }
    }
    cout<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int m;
    cin>>m;
    for(int i = 0;i<m;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    int x = q.front();
    q.pop();
    bfs(x);
    for(int i = 1;i<=n;i++){
        cout<<i<<": "<<level[i]<<endl;
    }

}