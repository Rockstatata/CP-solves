#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int level, profit, weight;
    float bound;
    Node(int l, int p, int w) : level(l), profit(p), weight(w) {}
};

float bound(Node u, int n, int W, vector<int>& weights, vector<int>& profits) {
    if (u.weight >= W) return 0;
    float profit_bound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;
    
    while ((j < n) && (totalWeight + weights[j] <= W)) {
        totalWeight += weights[j];
        profit_bound += profits[j];
        j++;
    }

    if (j < n) profit_bound += (W - totalWeight) * profits[j] / weights[j];
    return profit_bound;
}

struct compare {
    bool operator()(Node const& a, Node const& b) {
        return a.bound < b.bound;
    }
};

int knapsack(int W, vector<int>& weights, vector<int>& profits, int n) {
    priority_queue<Node, vector<Node>, compare> Q;
    Node u(-1, 0, 0), v(-1, 0, 0); 
    u.bound = bound(u, n, W, weights, profits);
    Q.push(u);
    int maxProfit = 0;

    while (!Q.empty()) {
        u = Q.top();
        Q.pop();
        
        if (u.level == -1) v.level = 0;
        if (u.level == n-1) continue;
        
        v.level = u.level + 1;
        v.weight = u.weight + weights[v.level];
        v.profit = u.profit + profits[v.level];

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, weights, profits);
        
        if (v.bound > maxProfit)
            Q.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, weights, profits);
        if (v.bound > maxProfit)
            Q.push(v);
    }
    return maxProfit;
}

int main() {
    int W = 110;
    vector<int> weights = {1,11,21,23,33,43,45,55,65};
    vector<int> profits = {11, 21, 31,33, 43, 53, 55, 65};
    int n = weights.size();
    cout << "Maximum profit: " << knapsack(W, weights, profits, n) << endl;
    return 0;
}