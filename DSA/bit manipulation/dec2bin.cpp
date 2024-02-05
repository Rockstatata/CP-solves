#include<bits/stdc++.h>
 
using namespace std;

int convtobin(int n){
    int ans = 0;
    int p = 1;
    while(n>0){
        int last_bit = n&1;
        ans+=p*last_bit;
        p=p*10;
        n=n>>1;
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n=15;
    cout<<convtobin(n)<<endl;
}