#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,k,s;
    cin>>n>>k>>s;
    if(!((k<=s) && s<=k*(n-1))){
        cout<<"NO"<<endl;
        return 0;
    }   
    cout<<"YES\n";
    long long moves[k];
    for(int i =0;i<k;i++)moves[i]=1;
    long long x = s - k;
    for(int i =0;i<k;i++){
        long long v = min(n-2,x);
        x-=v;
        moves[i]+=v;
    }
    long long cur =1;
    for(int i = 0;i<k;i++){
        if(i%2==0){
            cur+=moves[i];
        } 
        else{
            cur-=moves[i];   
        }
        cout<<cur<<" ";
    }

}