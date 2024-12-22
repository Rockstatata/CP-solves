#include<bits/stdc++.h>

using namespace std;

struct Node {
    vector<vector<int>> puzzle;
    int x, y, cost, level;
    Node* parent;
    
    Node(vector<vector<int>>& p, int x, int y, int newX, int newY, int level, Node* parent) 
        : puzzle(p), x(newX), y(newY), level(level), parent(parent) {
        swap(puzzle[x][y], puzzle[newX][newY]);
        cost = calculateCost(puzzle) + level;
    }

    int calculateCost(vector<vector<int>>& puzzle) {
        int cost = 0;
        int goal[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0} };
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (puzzle[i][j] && puzzle[i][j] != goal[i][j])
                    cost++;
        return cost;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->cost > b->cost;
    }
};

bool isValid(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void printPath(Node* root) {
    if (root == nullptr)
        return;
    printPath(root->parent);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << root->puzzle[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSolvable(vector<vector<int>>& puzzle) {
    vector<int> flatPuzzle;
    int blankRow;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (puzzle[i][j] == 0) {
                blankRow = puzzle.size()-i;
            }
            flatPuzzle.push_back(puzzle[i][j]);
        }
    }

    int inversions = 0;
    for (int i = 0; i < 16; i++) {
        for (int j = i + 1; j < 16; j++) {
            if (flatPuzzle[i] && flatPuzzle[j] && flatPuzzle[i] > flatPuzzle[j]) {
                inversions++;
            }
        }
    }

    if(puzzle.size()%2!=0){
        return (inversions%2==0);
    }

    return (inversions % 2 == 0) == (blankRow % 2 != 0);
}

int solve15Puzzle(vector<vector<int>>& initial, int x, int y) {
    int row[] = {1, 0, -1, 0};
    int col[] = {0, -1, 0, 1};
    priority_queue<Node*, vector<Node*>, compare> pq;
    Node* root = new Node(initial, x, y, x, y, 0, nullptr);
    pq.push(root);

    while (!pq.empty()) {
        Node* min = pq.top();
        pq.pop();

        if (min->cost - min->level == 0) {
            printPath(min);
            return min->level;
        }

        for (int i = 0; i < 4; i++) {
            int newX = min->x + row[i];
            int newY = min->y + col[i];

            if (isValid(newX, newY)) {
                Node* child = new Node(min->puzzle, min->x, min->y, newX, newY, min->level + 1, min);
                 pq.push(child);
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> initial = { {1, 2, 3, 4}, {5, 6, 0, 8}, {9, 10, 7, 11}, {13, 14, 15, 12} };
    int x = 1, y = 2; // Position of the blank tile (0)

    if (isSolvable(initial)) {
        int moves = solve15Puzzle(initial, x, y);
        cout << "Number of moves: " << moves << endl;
    } else {
        cout << "This puzzle is not solvable." << endl;
    }

    return 0;
}