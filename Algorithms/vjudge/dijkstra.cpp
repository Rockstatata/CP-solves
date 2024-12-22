#include <bits/stdc++.h>

using namespace std;

// Function to reconstruct the path
vector<int> reconstructPath(int source, int target, vector<int>& parent) {
    vector<int> path;
    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    if (path[0] != source)
        path.clear(); // Path does not lead to the source
    return path;
}

// Dijkstra's algorithm
void dijkstra(int source, int target, int n, vector<vector<pair<int, int>>>& adj) {
    vector<long long> dist(n + 1, LLONG_MAX);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [currDist, u] = pq.top();
        pq.pop();

        if (currDist > dist[u]) continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[target] == LLONG_MAX) {
        cout << -1 << endl;
        return;
    }

    // Reconstruct the path
    vector<int> path = reconstructPath(source, target, parent);

    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    dijkstra(1, n, n, adj);

    return 0;
}
