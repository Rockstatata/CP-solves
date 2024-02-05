#include<bits/stdc++.h>
 
using namespace std;

int countsetbits(int n){
    int cnt = 0;
    while(n>0){
        int last_bit = n&1;
        cnt+=last_bit;
        n=n>>1;
    }
    return cnt;
}

int countresetbits(int n){
    int cnt = 0;
    while(n>0){
        int last_bit = n&1;
        cnt+=((last_bit)?0:1);
        n=n>>1;
    }
    return cnt;
}

int countbitshack(int n){
    int ans=0;
    while(n>0){
       n = n& (n-1);
       ans++; 
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n=16;
    cout<<countsetbits(n)<<endl;
    cout<<countresetbits(n)<<endl;
    cout<<countbitshack(n)<<endl;
}