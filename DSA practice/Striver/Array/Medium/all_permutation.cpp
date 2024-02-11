#include<bits/stdc++.h>
 
using namespace std;

void allpermutation(vector<int>& arr,vector<int>& smallans, vector<vector<int>>& ans, bool freq[]){
    if(smallans.size()==arr.size()){
        ans.push_back(smallans);
        return;
    }
    for(int i = 0;i<arr.size();i++){
        if(!freq[i]){
            freq[i] = true;
            smallans.push_back(arr[i]);
            allpermutation(arr,smallans,ans,freq);
            smallans.pop_back();
            freq[i]=false;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr {1,2,3};
    int n = 3;
    vector<vector<int>>ans;
    vector<int>smallans;
    bool freq[n] {0};
    allpermutation(arr,smallans,ans,freq);   
    for(int i = 0;i<6;i++){
        for(int j = 0;j<3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}