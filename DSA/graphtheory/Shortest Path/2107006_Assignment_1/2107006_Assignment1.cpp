// Lab Assignment 1: Implementing Dijkstra's Algorithm with a User-Defined Min-Heap.
// SUBMITTED BY,
// SARWAD HASAN SIDDIQUI
// ROLL - 2107006

// MAIN ASSIGNMENT FILE

#pragma once

#include "min_heap.cpp"
 
using namespace std;

vector<int> dijkstra(int noofnodes,vector<vector<int>> graph[], int source){
    min_heap<int>pq;
    vector<int> distTo(noofnodes, INT_MAX);
    distTo[source] = 0;
    pq.insert(source,0);
    while (!pq.is_empty())
        {
            pair<int,int> keyvalue = pq.extract_min();
            int node = keyvalue.first;
            int dis = keyvalue.second;

            for (auto it : graph[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
                    pq.insert(v, dis + w);
                }
            }
        }
        return distTo;
}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    min_heap<int>p1;
    int noofnodes,noofedges,source;
    cout<<"How many nodes are in the graph?"<<endl;
    cin>>noofnodes;
    vector<vector<int>>graph[noofnodes];
    cout<<"How many edges are there in the graph?"<<endl;
    cin>>noofedges;
    int x,y,d;
    for(int i = 0;i<noofedges;i++){
        cin>>x>>y>>d;
        graph[x].push_back({y,d});
        graph[y].push_back({x,d});
    }
    cout<<"Select the source node"<<endl;
    cin>>source;
    vector<int> result = dijkstra(noofnodes,graph,source);
    for(int i = 0;i<result.size();i++){
        cout<<"Distance from source "<<source<<" of node "<<i<<" is "<<result[i]<<endl;
    }
}