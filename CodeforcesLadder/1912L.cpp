#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
        cin>>n;
        string s;
        cin>>s;
        int a[n][2];
        int t1=0,t2=0;
        for(int i=n-1;i>=0;i--)
        {
            a[i][0]=t1;
            a[i][1]=t2;
            if(s[i]=='L')
            {
                t1++;
            }else
            {
                t2++;
            }
        }
        int res=-1;
        t1=0,t2=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='L')
            {
                t1++;
            }else
            {
                t2++;
            }
            if(t1!=a[i][0]&&t2!=a[i][1])
            {
                res=i+1;
                break;
            }
        }
        cout<<res;
}