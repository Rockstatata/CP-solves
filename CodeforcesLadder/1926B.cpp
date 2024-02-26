#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char grid[n][n];
        int cnt[n] {0};
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>grid[i][j];
                if(grid[i][j]=='1'){
                    cnt[i]++;
                }
            }
        }
        string ans = "TRIANGLE", ans2 = "SQUARE";
        for(int i = 0;i<n-1;i++){
            if(cnt[i]==cnt[i+1] && cnt[i]!=0){
                ans = ans2;
                break;
            }
        }
        cout<<ans<<endl;
    }
}