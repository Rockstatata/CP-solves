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

void kruskal(vector<pair<int,pair<int,int>>>edgelist){
    sort(edgelist.begin(),edgelist.end());
    int ans = 0;
    for (auto edge : edgelist) { 
            int w = edge.first; 
            int x = edge.second.first; 
            int y = edge.second.second; 
  
            // Take this edge in MST if it does 
            // not forms a cycle 
            if (find(x) != find(y)) { 
                Union(x, y); 
                ans += w; 
                cout << x << " -- " << y << " == " << w 
                     << endl; 
            } 
        } 
        cout << "Minimum Cost Spanning Tree: " << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    vector<pair<int,pair<int,int>>>edgelist;
    int w,a,b;
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        make(i);
    }
    while(k--){
        cin>>w>>a>>b;
        edgelist.push_back({w,{a,b}});
    }
    
}