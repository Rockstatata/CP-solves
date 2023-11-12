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
        vector<int>v;
        if(n>45){
            cout<<-1<<endl;
        }
        else{
            int i = 9;
            while(n!=0){
                if(n>=i){
                    n-=i;
                    v.push_back(i);
                }
                i--;
            }
            sort(v.begin(),v.end());
            for(int i = 0;i<v.size();i++){
                cout<<v[i];
            }
            cout<<endl;
        }
    }
}