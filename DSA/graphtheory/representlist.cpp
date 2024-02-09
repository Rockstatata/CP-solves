#include<bits/stdc++.h>
 
using namespace std;

const int N= 1e3+10;
vector<int>graph[N];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int i = 0,j=0;
    for(int child : graph[i]){
        if(child==j){
            //connected;
        }
    }
}