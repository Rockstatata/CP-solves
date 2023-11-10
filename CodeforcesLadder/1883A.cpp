#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string num;
        int count=4;
        string comb ="1111";
        cin>>num;
        for(int i=0;i<4;i++){
            if((num[i]==comb[i]))continue;
            else{
                if(num[i]=='0' || comb[i]=='0') count+=(10-(abs(num[i]-comb[i])));
                else count+=(abs(num[i]-comb[i]));
                for(int j = i;j<4;j++){
                    comb[j]=num[i];
                }
            }
        }
        cout<<count<<endl;
    }   
}