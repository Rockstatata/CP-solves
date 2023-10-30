#include<bits/stdc++.h>
 
using namespace std;



void solve(int num[], vector<vector<int>>& v, vector<int>& ds, bool freq[],int length){
    if(ds.size()==length){
        v.push_back(ds);
        return;
    }
    for(int i = 0;i<length;i++){
        if(!freq[i]){
            freq[i] = true;
            ds.push_back(num[i]);
            solve(num,v,ds,freq,length);
            ds.erase(ds.end());
            freq[i]=false;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num[] {1,2,3,4,5};
    int length = 5;
    vector<vector<int>> v {};
    vector<int> ds; 
    bool freq[5] {0};
    solve(num,v,ds,freq,length);
}