#include<bits/stdc++.h>
 
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>>g[N]; //node,weight

int djikstra(int source, int n, vector<pair<int,int>>g[N]){
    vector<int>dist(N,INF);
    set<pair<int,int>>s;
    int ans;
    s.insert({0,source});
    dist[source]=0; 
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto it: g[x.second]){
            if(dist[it.first]>dist[x.second]+it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first]=dist[x.second]+it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(dist[i]==INF)return -1;
        ans=max(ans,dist[i]);
    }
    return ans;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int,int>>g[N];
    for(auto vec: times){
        g[vec[0]].push_back({vec[1],vec[2]});
    }
    return djikstra(k,N,g);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    for(int i = 0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt}); //if directed only
        //g[y].push_back({x,wt}); //if undirected

    }
}