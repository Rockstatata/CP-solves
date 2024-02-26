#include <bits/stdc++.h>
using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define int long long
#define float long double
int cs;
void solve()
{
    int n;
    string s;
    char c;
    cin >> n >> c;
    map<char,vector<int>> mp;
    for(int i=0;i<2*n;i++) cin >> s, mp[s[1]].push_back(s[0]-'0');
    if(mp['S'].size()%2+mp['C'].size()%2+mp['D'].size()%2+mp['H'].size()%2-mp[c].size()%2>mp[c].size())
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    sort(mp['C'].begin(),mp['C'].end());
    sort(mp['D'].begin(),mp['D'].end());
    sort(mp['H'].begin(),mp['H'].end());
    sort(mp['S'].begin(),mp['S'].end());
    for(int i=0;'C'!=c && i<mp['C'].size()/2*2;i+=2) cout << mp['C'][i] << "C " << mp['C'][i+1] << 'C'<< endl;
    for(int i=0;'D'!=c && i<mp['D'].size()/2*2;i+=2) cout << mp['D'][i] << "D " << mp['D'][i+1] << 'D' <<endl;
    for(int i=0;'H'!=c && i<mp['H'].size()/2*2;i+=2) cout << mp['H'][i] << "H " << mp['H'][i+1] << 'H' <<endl;
    for(int i=0;'S'!=c && i<mp['S'].size()/2*2;i+=2) cout << mp['S'][i] << "S " << mp['S'][i+1] << 'S' <<endl;
    int i=0;
    if('C'!=c && mp['C'].size()%2) cout << mp['C'].back() << 'C'<< ' ' << mp[c][i++] << c  << endl;
    if('D'!=c && mp['D'].size()%2) cout <<  mp['D'].back() << 'D' <<' ' << mp[c][i++] << c  <<endl;
    if('H'!=c && mp['H'].size()%2) cout<< mp['H'].back() << 'H' <<' ' <<  mp[c][i++] << c   <<endl;
    if('S'!=c && mp['S'].size()%2) cout << mp['S'].back() << 'S' << ' ' << mp[c][i++] << c  <<endl;
    while(i<mp[c].size())
    {
        cout << mp[c][i] << c << ' ' << mp[c][i+1] <<c <<endl;
        i+=2;
    }


}
signed main()
{
    fast
    int t=1;
    cin >> t;
    for(cs=1;cs<=t;cs++)
    {
        //cout << "Case " << cs << ": "; 
        solve();
    }
    return 0;
}