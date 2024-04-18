#include<bits/stdc++.h>
 
using namespace std;

const int N = 1e5+10;
int parent [N];
int sizee[N];

//Time Complexity : Amortized Time Complexity
// O(alpha(n))
// alpha(n) => Reverse Ackermann function => A type of function which increases really slow
// Amortized => sometimes more or sometimes less, but average case
// It is almost constant

void make(int v){
    parent[v] = v;
    sizee[v] = 1;
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}
 
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        // Union by Size
        if(sizee[a]<sizee[b])swap(a,b);
        parent[b] = a;
        sizee[a]+=sizee[b];
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
    int connected = 0;
    for(int v = 1;v<=n;v++){
        if(find(v)==v)connected++;
    }
    cout<<connected<<endl;
}