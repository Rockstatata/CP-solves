#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int num[n];
    int min=INT_MAX,ans=0;
    for(int i = 0;i<n;i++){
        cin>>num[i];
        ans = abs(num[i]-0);
        if(ans<=min){
            min = ans;
        }
    }
    cout<<min<<endl;
}