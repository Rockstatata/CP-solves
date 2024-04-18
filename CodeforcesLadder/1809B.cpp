#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int root=sqrtl(n);
        if(root*root!=n)
            cout<<root<<endl;
        else
            cout<<root-1<<endl;
    }
    return 0;
}