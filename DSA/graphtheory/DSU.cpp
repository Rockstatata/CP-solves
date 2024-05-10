#include<bits/stdc++.h>
 
using namespace std;

const int N = 1e5+10;
int parent [N];
int sizee[N];
int rankk[N] = {0};
int connected = 0;

//Time Complexity : Amortized Time Complexity
// O(alpha(n))
// alpha(n) => Reverse Ackermann function => A type of function which increases really slow
// Amortized => sometimes more or sometimes less, but average case
// It is almost constant

void make(int v){
    parent[v] = v;
    sizee[v] = 1;
    rankk[v] = 0;
    connected++;
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}
 
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b){
        return;
    }
    if(a!=b){
        // Union by Size
        if(sizee[a]<sizee[b])swap(a,b);
        parent[b] = a;
        sizee[a]+=sizee[b];

        // Union by Rank
        // if(rankk[a]<rankk[b]){
        //     parent[a] = b;
        // }
        // else if(rankk[b]<rankk[a]){
        //     parent[b] = a;
        // }
        // else{
        //     parent[a] = b;
        //     rankk[a]++;
        // }
        if(find(a)==find(b)){
            connected--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        make(i);
    }
    while(k--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    cout<<connected<<endl;
}