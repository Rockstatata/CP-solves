#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d,B=0,A=0,count=0,flag=0,x;
        cin>>a>>b>>c>>d;
        int sum = a + b + c + d;
        int ans = a;
        int p = abs(b - c);
        int pp = min(b, c);
        if (a == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            ans += 2 * pp;
            if (a >= p)
            {
                ans += p;
                a -= p;
                ans += min(a + 1, d);
            }
            else
            {
                ans += min(a + 1, p);
            }
            cout << min(ans, sum) << endl;
        }
    }   
}