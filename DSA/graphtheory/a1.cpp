// Removing Edges which aren't bridges

#include<bits/stdc++.h>
 
using namespace std;

const int N = 20;
vector<int>graph[N];

int vis[N] {0};
int level[N] {0};
vector<int>removeedge;

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
            if(vis[child]){
                if(level[cur_v]==level[child]){
                    removeedge.push_back(cur_v);
                    removeedge.push_back(child);
                }
            }
            if(!vis[child]){
                q.push(child);
                cout<<child<<" ";
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
    
    bfs(1);

    cout<<"Edge remove: "<<removeedge.size()/4<<endl;
    for(int i = 0;i<removeedge.size()-1;i+=4){
        cout<<removeedge[i]<<" "<<removeedge[i+1]<<endl;
    }
}