#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n;
    cin>>n;
    long long sum = (n*(n+1))/2;
    if(sum%2){
        cout<<"NO"<<endl;
    }
    else{
        long long avg = sum/2;
        vector<long long>a,b;
        for(int i =n;i>=1;i--){
            if(i<=avg){
                a.push_back(i);
                avg-=i;
            }
            else{
                b.push_back(i);
            }
        }
        cout<<"YES"<<endl;
        cout<<a.size()<<endl;
        reverse(a.begin(),a.end());
        for(auto it:a){
            cout<<it<<" ";
        }
        cout<<endl;
        cout<<b.size()<<endl;
        reverse(b.begin(),b.end());
        for(auto it:b){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}