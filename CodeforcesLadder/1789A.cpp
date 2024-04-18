#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,b=1e9;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++) b=min(b,__gcd(a[i],a[j]));
        }
        if(b<=2) cout << "Yes" << endl;
        else cout << "No" <<endl;
    }
}
