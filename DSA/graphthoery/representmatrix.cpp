#include<bits/stdc++.h>
 
using namespace std;

const int N=1e3+10;
int graph[N][N];  //global variable zero by default
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    for(int i = 0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    int i = 0, j = 0;
    if(graph[i][j]!=0){
        //connected
    }
}