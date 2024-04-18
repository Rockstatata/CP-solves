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
        int m = n*2;
        char x,c;
            c = '#'; x = '.';
            for(int i = 0;i<n;i++){
                for(int j=0;j<2;j++){
                    for(int k = 0;k<n;k++){
                        for(int l = 0;l<2;l++){
                            cout<<c;
                        }
                        swap(c,x);
                    }
                    if((n%2==0 && j==1) || n==1) swap(c,x);
                    else if(n%2==1 && j==0) swap(c,x);
                    cout<<endl;
                }
            }
        
    }
}