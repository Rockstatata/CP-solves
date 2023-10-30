#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int maxa,maxb;
        maxa= a+c;
        maxb= b+c;
        if(maxa>maxb){
            cout<<"First"<<endl;
        }
        else if(maxa<maxb){
            cout<<"Second"<<endl;
        }
        else{
            cout<<((c%2==0)?"Second":"First")<<endl;
        }
    }
}