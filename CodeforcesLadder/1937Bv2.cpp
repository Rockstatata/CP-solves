#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);


int main()
{
    fastio
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        vector<char>str;
        str.push_back(s1[0]);
        int co=1;
        for(int i=1;i<n;i++)
        {
            if(s1[i]==s2[i-1])
            {
                co++;
                str.push_back(s1[i]);
            }
            else if(s1[i]=='0')
            {
                str.push_back(s1[i]);
                co=1;
            }
            else
            {
                for(int j=i-1;j<n-1;j++)
                {
                    str.push_back(s2[j]);
                }
                break;
            }
        }
        for(auto it:str)cout<<it;
        cout<<s2[n-1];
        cout<<"\n";
        cout<<co<<"\n";
    }
}
