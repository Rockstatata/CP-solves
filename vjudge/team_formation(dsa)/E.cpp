#include<bits/stdc++.h>
 
using namespace std;

const int N = 10;
int vis[N][N] {0};


int travel(vector<vector<int>>& build){
    int n = build.size();
    int m = build[0].size(), cnt = 0;
    if(n==1 && m==1) cnt =1;
    queue<pair<int,int>>q;
    int delrow[] = {+1, 0};
    int delcol[] = {0, +1};
    q.push({0,0});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0;i<2;i++){
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && vis[nrow][ncol] !=1){
                if(nrow== n-1 && ncol == m-1){
                    cnt++;
                }
                else{
                    q.push({nrow,ncol});
                }
            }
        }
    }
    return cnt;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>path;
        for(int i = 0;i<n;i++){
            vector<int>mini;
            for(int j= 0;j<m;j++){
                mini.push_back(0);
            }
            path.push_back(mini);
        }
        int ways = travel(path);
        cout<<ways<<endl;
    }
}