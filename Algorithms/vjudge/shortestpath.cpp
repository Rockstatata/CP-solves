#include <bits/stdc++.h>

using namespace std;

vector<int> reconstructPath(int source, int target, vector<int>& parent) {
    vector<int> path;
    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    if (path[0] != source)
        path.clear(); 
    return path;
}

void dijkstra(int source, int target, int n, vector<vector<pair<int, int>>>& adj) {
    vector<long long> dist(n, LLONG_MAX);
    vector<int> parent(n, -1);
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


    vector<int> path = reconstructPath(source, target, parent);
    int pathLength = path.size();

    cout << dist[target] << " " << pathLength - 1 << endl;

    for (int i = 0; i < pathLength - 1; ++i) {
        cout << path[i] << " " << path[i + 1] << endl;
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    dijkstra(s, t, n, adj);

    return 0;
}
