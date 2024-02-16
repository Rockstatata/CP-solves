#include<bits/stdc++.h>
 
using namespace std;

const int N = 1000;
int vis[N][N] {0};


void bfs(vector<vector<char>>& build, int i, int j){
    int n = build.size();
    int m = build[0].size(), cnt = 0;
    queue<pair<int,int>>q;
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    q.push({i,j});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && vis[nrow][ncol] !=1 && build[nrow][ncol]=='.'){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }
    }
}

int rottenbuild(vector<vector<char>>& build){
    int n = build.size();
    int m = build[0].size(), cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j=  0;j<m;j++){
            if(build[i][j] == '.'){
                if(!vis[i][j]){
                    vis[i][j]=1;
                    bfs(build,i,j);
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    char c;
    vector<vector<char>>build;
    for(int i = 0;i<n;i++){
        vector<char>mini;
        for(int j = 0;j<m;j++){
            cin>>c;
            mini.push_back(c);
        }
        build.push_back(mini);
    }
    int rooms = rottenbuild(build);
    cout<<rooms<<endl;
}