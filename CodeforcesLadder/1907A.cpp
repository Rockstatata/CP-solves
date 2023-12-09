#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s[1]-'0';
        char c =s[0];
        for(int i=1;i<=8;i++){
            if(n==i)continue;
            cout<<c<<i<<endl;
        }
        for(int i=0;i<=7;i++){
            if(c==(97+i))continue;
            cout<<char(97+i)<<n<<endl;
        }
    }   
}