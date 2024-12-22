#include<bits/stdc++.h>
 
using namespace std;

bool bellmanFord(int V, vector<vector<int>> edges, vector<int>& dist, int source){
		dist[source] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return true;
			}
		}
        return false;
}

void dijkstra(int V, vector<vector<pair<int, int>>>& adj, vector<int>& dist, int source) {
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

void johnsonAlgorithm(int V, vector<vector<int>>& edges) {
    // Step 1: Add a new vertex q and edges from q to every vertex with weight 0
    vector<vector<int>> newEdges = edges;
    for (int i = 0; i < V; i++) {
        newEdges.push_back({V, i, 0});
    }

    // Step 2: Run Bellman-Ford from vertex V (the added vertex q)
    vector<int> h(V + 1, numeric_limits<int>::max());
    if (!bellmanFord(V + 1, newEdges, h, V)) {
        cout << "Negative weight cycle detected!" << endl;
        //return;
    }

    // Step 3: Reweight the edges
    vector<vector<pair<int, int>>> adj(V);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int newWeight = edge[2] + h[u] - h[v];
        adj[u].push_back({v, newWeight});
    }

    // Step 4: Run Dijkstra's algorithm from each vertex
    vector<vector<int>> dist(V, vector<int>(V, numeric_limits<int>::max()));
    for (int u = 0; u < V; u++) {
        dijkstra(V, adj, dist[u], u);
    }

    // Step 5: Convert distances back to original weights
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (dist[u][v] != numeric_limits<int>::max()) {
                dist[u][v] += h[v] - h[u];
            }
        }
    }

    // Output the shortest paths
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (dist[u][v] == numeric_limits<int>::max()) {
                cout << "INF ";
            } else {
                cout << dist[u][v] << " ";
            }
        }
        cout << endl;
    }
}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int V = 5;  // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 3},
        {0, 2, 8},
        {1, 2, 2},
        {1, 3, 6},
        {2, 3, 1},
        {3, 4, 4},
        {4, 0, 2}
    };

    johnsonAlgorithm(V, edges);

    return 0;
}