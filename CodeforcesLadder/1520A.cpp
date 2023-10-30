#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int pref[27] {};
        int n,flag=0,y;
        cin>>n;
        char x[n+1],c;
        for(int i = 0;i<n;i++){
            cin>>x[i];
            if(flag==1)continue;
            if(i==0){
                y = x[i] - 65;
                pref[y]++;
            }
            else{
                y = x[i] - 65;
                if(x[i-1]!=x[i]){
                    if(pref[y]!=0){
                        flag=1;
                    }
                }
                pref[y]++;               
            }
        }
        cout<<((flag)?"NO":"YES")<<endl;
    }
}