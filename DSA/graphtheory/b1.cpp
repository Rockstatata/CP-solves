#include <bits/stdc++.h>
using namespace std;

    
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        static int timer = 1;
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,
    vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(1, -1, vis, adj, tin, low, bridges);
        return bridges;
    }

int main() {

    int n,m;
    cin>>n>>m;
    int x,y;
    vector<vector<int>> connections;
    vector<int>mini;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        mini.push_back(x);
        mini.push_back(y);
        connections.push_back(mini);
        mini.clear();
    }

    vector<vector<int>> bridges = criticalConnections(n+1, connections);
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}