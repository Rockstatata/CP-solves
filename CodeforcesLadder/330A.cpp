#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r,c,count=0;
    cin>>r>>c;
    vector<vector<pair<char,bool>>>grid;
    vector<pair<char,bool>>id;
    char n;
    bool b,abort = false;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>n;
            b = false;
            id.push_back({n,b});
        }
        grid.push_back(id);
        id.clear();
    }

    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(grid[i][j].first=='S'){
                abort=true;
                break;
            }
        }
        if(abort==false){
                for(int j =0;j<c;j++){
                    grid[i][j].second=true;
                }
            }
            abort=false;
    }

    for(int i = 0;i<c;i++){
        for(int j = 0;j<r;j++){
            if(grid[j][i].first=='S'){
                abort=true;
                break;
            }
        }
        if(abort==false){
                for(int j =0;j<r;j++){
                    grid[j][i].second=true;
                }
            }
            abort=false;
    }
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(grid[i][j].second){
                count++;
            }
        }
    }
    cout<<count<<endl;

}