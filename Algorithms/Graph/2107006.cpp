#include <bits/stdc++.h>

using namespace std;

void bellmanford(int V, int E, vector<int> &dist, vector<pair<pair<int, int>, int>> &edgelist, int source, vector<int> &cycle, bool &cycleexist)
{
    vector<int> parent(V, -1);
    for (int i = 0; i < V-1 ; i++)
    {
        for (auto edge : edgelist)
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    int first = -1;

    
    for (auto edge : edgelist)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            first = v;
            cycleexist = false;
            break;
        }
    
    }

    for (int i = 0; i < V; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;

    if (first != -1)
    {
        // for (int i = 0; i < V; i++)
        //     first = parent[first];
        for (int v = first;; v = parent[v])
        {
            cycle.push_back(v);
            if (v == first && cycle.size() > 1)
                break;
        }
    }
    reverse(cycle.begin(), cycle.end());
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<pair<int, int>, int>> edgelist;
    int source, dest, weight;
    for (int i = 0; i < E; i++)
    {
        cin >> source >> dest >> weight;
        edgelist.push_back({{source, dest}, weight});
    }
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    vector<int> cycle;
    bool cycleexist = true;
    bellmanford(V, E, dist, edgelist, 0, cycle, cycleexist);
    if (cycleexist)
    {
        cout << "There is not any negative cycles" << endl;
    }
    else
    {
        cout << "There exists a negative cycle" << endl;
        for (int i = 0; i < cycle.size(); i++)
        {
            cout << cycle[i] << " ";
        }
        cout << endl;
    }
}
