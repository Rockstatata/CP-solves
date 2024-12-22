#include <bits/stdc++.h>

using namespace std;

const int N = 100;

void fillzero(int m, int n, vector<vector<bool>> visited)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
}

bool dfsrecurse(string word, vector<vector<char>> grid, vector<vector<bool>> visited, int ind, int i0, int j0)
{
    int m = grid.size();
    int n = grid[0].size();
    visited[i0][j0] = 1;
    int delrow[] = {-1, 0, 1, 0, 1, 1, -1, -1};
    int delcol[] = {0, 1, 0, -1, 1, -1, 1, -1};
    if (word.size() == ind)
    {
        return true;
    }
    for (int i = 0; i < 8; i++)
    {
        int nrow = i0 + delrow[i];
        int ncol = j0 + delcol[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol] == word[ind])
        {
            if (dfsrecurse(word, grid, visited, ind + 1, nrow, ncol))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

void dfsbase(vector<string> words, vector<vector<char>> grid, vector<vector<bool>> visited)
{
    int m = grid.size();
    int n = grid[0].size();
    bool stat;
    for (auto word : words)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == word[0])
                {
                    stat = dfsrecurse(word, grid, visited, 1, i, j);
                    if (stat)
                        break;
                }
            }
            if (stat)
                break;
        }
        fillzero(m, n, visited);
        if (stat)
        {
            cout << word << endl;
        }
        stat = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    vector<string> words(x);
    for (int i = 0; i < x; i++)
    {
        cin >> words[i];
    }
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid{{'S', 'E', 'R', 'T'},
                              {'U', 'N', 'K', 'S'},
                              {'T', 'C', 'A', 'T'}};

    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    fillzero(m, n, visited);
    dfsbase(words, grid, visited);
}