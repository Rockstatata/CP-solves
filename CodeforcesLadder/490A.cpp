#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int kids[n];
    bool kidav[n] {};
    int a=0,b=0,c=0;
    vector<vector<int>>ans;
    for(int i = 0;i<n;i++){
        cin>>kids[i];
    }
    for(int i = 0;i<n;i++){
        if(kids[i]==1){
            kidav[i]=true;
            a=i+1;
            for(int j = 0;j<n;j++){
                if(kids[j]==2 && kidav[j]==false){
                    b=j+1;
                    kidav[j]=true;
                    for(int k=0;k<n;k++){
                        if(kids[k]==3 && kidav[k]==false){
                            c=k+1;
                            kidav[k]=true;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        if(a!=0 && b!=0 && c!=0)ans.push_back({a,b,c});
        a=b=c=0;
    }
    int anssize = ans.size();
    cout<<anssize<<endl;
    if(anssize==0)return 0;
    for(int i = 0;i<anssize;i++){
        for(int j = 0;j<3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}