#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,count=0,sum=0;
    cin>>n>>x;
    bool have[n] {false};
    vector<int>v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }   
    sort(v.begin(),v.end());
    int i = 0, j = v.size()-1;
    while(i<j){
        if((v[i]+v[j])<=x){
            count++;
            have[i] = true;
            have[j] = true;
            i++;
            j--;
        }
        else{
            j--;
        }
    }
    for(int i = 0;i<n;i++){
        count+=(have[i]==false);
    }
    cout<<count<<endl;
}