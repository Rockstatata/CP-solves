#include<bits/stdc++.h>
 
using namespace std;


void dfs(auto row, auto col, auto& mapp, auto& vis,auto& vec,auto i0,auto j0){
    int n = mapp.size();
    int m = mapp[0].size();
    vis[row][col]=1;
    vec.push_back({row-i0,col-j0});
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && !vis[nrow][ncol] && mapp[nrow][ncol] == 1){
                dfs(nrow, ncol, vis, mapp, vec, i0, j0);
            } 
        }
    }
}

int distinctislands(auto& mapp){
    int n = mapp.size();
    int m = mapp[0].size();
    vector<vector<int>>vis (n,vector<int>(m,0));
    set<vector<pair<int,int>>>ans;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!vis[i][j] && mapp[i][j]==1){
                vector<pair<int,int>>vec;
                dfs(i,j,mapp,vis,vec,i,j);
                ans.insert(vec);
            }
        }
    }
    return ans.size();
}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> mapp{{1,1,0,1,1},
                             {1,0,0,0,0},
                             {0,0,0,1,1},
                             {1,1,0,1,0}};

    int islands = distinctislands(mapp);
    cout<<islands<<endl;                       

}