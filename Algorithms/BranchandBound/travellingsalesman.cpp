#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(int current, int n, vector<vector<int>>& dist, vector<bool>& visited, int count, int cost, int& minCost) {
    if (count == n && dist[current][0]) {
        minCost = min(minCost, cost + dist[current][0]);
        return minCost;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[current][i]) {
            visited[i] = true;
            tsp(i, n, dist, visited, count + 1, cost + dist[current][i], minCost);
            visited[i] = false;
        }
    }

    return minCost;
}

int main() {
    vector<vector<int>> dist = {
        {0, 20, 30, 10, 11},
        {15, 0, 16, 4, 2},
        {3, 5, 0, 2, 4},
        {19, 6, 18, 0, 3},
        {16, 4, 7, 16, 0}
    };
    int n = dist.size();
    vector<bool> visited(n, false);
    visited[0] = true;
    int minCost = INT_MAX;

    cout << "Minimum cost of TSP: " << tsp(0, n, dist, visited, 1, 0, minCost) << endl;
    return 0;
}
