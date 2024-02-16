#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    ll i = 1;
    while(i<=t){
        ll n;
        cin>>n;
        ll root = ceil(sqrt(n*1.0)), column,row;
        ll lack = root * root - n;
        if(lack < root){
            row = root;
            column = lack + 1;
        }
        else{
            column = root;
            row = n - (root-1)*(root-1);
        }
        if(root%2==0){
            ll temp = column;
            column = row;
            row = temp;
        }
        cout<<"Case "<<i<<": "<<column<<" "<<row<<endl;
        i++;
    }
}