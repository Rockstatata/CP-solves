#include<bits/stdc++.h>
 
using namespace std;


void dfs(auto row, auto col, auto& mapp, auto& vis,auto i0,auto j0){
    int n = mapp.size();
    int m = mapp[0].size();
    vis[row][col]=1;
    //vec.push_back({row-i0,col-j0});
    int delrow[] = {-1,0,1,0,1,1,-1,-1};
    int delcol[] = {0,1,0,-1,1,-1,1,-1};
    for(int i = 0;i<8;i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
        && !vis[nrow][ncol] && mapp[nrow][ncol] == 1){
            dfs(nrow, ncol, mapp, vis, i0, j0);
        } 
    }
}

int distinctislands(auto& mapp){
    int n = mapp.size();
    int m = mapp[0].size();
    vector<vector<int>>vis (n,vector<int>(m,0));
    //set<vector<pair<int,int>>>ans;
    set<pair<int,int>>anss;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!vis[i][j] && mapp[i][j]==1){
                //vector<pair<int,int>>vec;
                anss.insert({i,j});
                dfs(i,j,mapp,vis,i,j);
                //ans.insert(vec);
            }
        }
    }
    return anss.size();
}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> mapp{{1,0,1,0},
                             {1,0,1,1},
                             {0,0,0,0},
                             {1,1,0,1}};

    int islands = distinctislands(mapp);
    cout<<islands<<endl;                       

}