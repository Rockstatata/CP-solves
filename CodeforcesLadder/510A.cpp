#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    bool side=true;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        if(i%2==0){
            for(int i = 0;i<m;i++){
                cout<<"#";
            }
            cout<<endl;
        }
        else{
            if(side){
                for(int i = 0;i<m-1;i++){
                    cout<<".";
                }
                cout<<"#"<<endl;
                side=false;
            }
            else{
                cout<<"#";
                for(int i = 0;i<m-1;i++){
                    cout<<".";
                }
                cout<<endl;
                side=true;
            }
        }
    }
}