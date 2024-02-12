#include<bits/stdc++.h>
 
using namespace std;

const int N = 30;
vector<int>graph[N];
int vis[N][N] {0};

int rottenoranges(vector<vector<int>>& oranges){
    int n = oranges.size(), cntfresh =0;
    int m = oranges[0].size(), cnt = 0;
    queue<pair<pair<int,int>,int>>q;
    int vis[n][m] {0};
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1}; 
    for(int i = 0;i<n;i++){
        for(int j=  0;j<m;j++){
            if(oranges[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
            if(oranges[i][j]==1){
                cntfresh++;
            }
        }
    }
    int time = 0;
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(time,t);
        for(int i = 0;i<4;i++){
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && vis[nrow][ncol] !=2 && oranges[nrow][ncol]==1){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=2;
                cnt++;
            }
        }
    }

    if(cnt!=cntfresh) return -1;
    return time;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>>oranges {
                                {2,1,1},
                                {1,1,0},
                                {0,1,1}};
    int time = rottenoranges(oranges);
    cout<<time<<endl;
}