#include<bits/stdc++.h>
 
using namespace std;

const int N = 1e5+10;
vector<int>g[N];

int vis[N];
map<int,vector<int>>level;

void readylevel(int n){
    vector<int> v(n+1,0);
    for(auto &i:level){
        i.second = v;
    }
}

void resetvis(int n){
    for(int i = 0;i<=n;i++){
        vis[i] = 0;
    }
}

void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int cur_v = q.front();
        q.pop();
        cout<<cur_v<<" "; 
        for(int child:g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[source][child]=level[source][cur_v]+1;
            }
        }
    }
    cout<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    for(int i = 0;i<m;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int>friends;
    for(int i=0;i<d;i++){
        int x;
        cin>>x;
        friends.push_back(x);
        level[x].push_back(0);
    }
    friends.push_back(s);
    level[s].push_back(0);
    readylevel(n);
    for(int i:friends){
        bfs(i);
        resetvis(n);
    }

    for(auto i:level){
        cout<<i.first<<": ";
        for(int j=0;j<=n;j++){
            cout<<level[i.first][j]<<" ";
        }
        cout<<endl;
    }
    set<int>exclude;
    for(auto i:level){
        int max = *max_element(level[i.first].begin(),level[i.first].end());
        for(int j=0;j<=n;j++){
            if(max==level[i.first][j]){
                exclude.insert(j);
            }
        }
    }
    vector<int>summation;
    vector<int>answer;
    for(int i=0;i<=n;i++){
        int sum = 0;
        for(auto j:level){
            sum += level[j.first][i];
        }
        summation.push_back(sum);
    }
    int min = *min_element(summation.begin()+1,summation.end());
    for(int i=1;i<=n;i++){
        if(min==summation[i] && exclude.find(i)==exclude.end()){
            answer.push_back(i);
        }
    }
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
}