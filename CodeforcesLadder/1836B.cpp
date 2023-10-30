#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k,g;
        cin>>n>>k>>g;
        int  po;
        po=(g-1)/2;
        long long int used=po*n;
        if(used>=k*g)
        {
            cout<<k*g<<"\n";
        }else
        {
            long long int total = k*g-used;
            used-=po;
            total+=po;
            total=total%g;
            if(total<=po)
            {
                used+=total;
            }else
            {
                used=used-g+total;
            }
            cout<<used<<"\n";
        }
    }
}
