#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        set<int>num1,num2;
        long long int sum=0;
        for(int i=0; i<n; i++)
        {
            int k;
            cin>>k;
            num1.insert(k);
            sum+=k;
        }
        ll all=sum;
        ll sum2=0;
        for(int i=0; i<m; i++)
        {
            int k;
            cin>>k;
            num2.insert(k);
            all+=k;
            sum2+=k;
        }
        if(k%2==0)
        {
            int dif=*num2.rbegin()-*num1.begin();
            if(dif>0)
            {
                sum+=dif;
                sum2-=dif;
                num2.insert(*num1.begin());
                num1.insert(*num2.rbegin());
            }
            int ma=*num1.rbegin();
            sum2=ma+sum2;
            num2.insert(ma);
            sum2=sum2-*num2.begin();
            sum=all-sum2;
        }else
        {
            int ma=*num2.rbegin();
            sum=ma+sum;
            num1.insert(ma);
            sum=sum-*num1.begin();
        }
        cout<<sum<<"\n";
    }
}

