#include<bits/stdc++.h>
 
using namespace std;

void dijkstra(long long source, long long n, vector<pair<long long,long long>>adj[]){
    vector<long long>dist(n+1,LLONG_MAX);
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
    dist[source] = 0;
    pq.push({0,source});

    while(!pq.empty()){
        long long currDist = pq.top().first;
        long long u = pq.top().second;
        pq.pop();

        if(currDist>dist[u])continue;

        for(auto edge:adj[u]){
            long long v = edge.first;
            long long w = edge.second;
            if(dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }

    for (long long i = 1; i <= n; ++i) {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    vector<pair<long long,long long>>adj[n+1];

    for(long long i = 0;i<m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    dijkstra(1,n,adj);
}