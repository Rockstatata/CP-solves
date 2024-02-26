#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int year=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>year)
        {
            year=a[i];
        }
        else
        {
            int x=year/a[i];
            x++;
            year=a[i]*x;
        }
    }
   
    
    cout<<year<<endl;

}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}