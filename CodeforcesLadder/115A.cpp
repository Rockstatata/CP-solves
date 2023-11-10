#include <bits/stdc++.h>
#define mod 1000000007
#define N 100005
#define mp make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;
typedef long long int ll;
const ll INF_LL=2e18;
const int INF_INT=2e9;

vector<int>v[N];
vector<int>par;
int depth[N];
int max_depth=0;

void dfs(int vertex){
    for(auto child:v[vertex]){
        depth[child]=depth[vertex]+1;
        max_depth=max(max_depth,depth[child]);
        dfs(child);
    }
}

int main(){
	fastio
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        int g;
        cin>>g;
        if(g!=-1){
            v[g].pb(i);
            par.pb(g);
        }
    }
    for(auto i:par){
        dfs(i);
    }
    cout<<max_depth+1<<endl;

}
