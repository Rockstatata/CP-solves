#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;

#define rep(i, x, y) for (int i = x; i < y; i++)
#define pb push_back
#define pres(c, x) ((c).find(x) != (c).end())
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int dayNumber(int day, int month, int year)
{
 
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 +
             year/400 + t[month-1] + day) % 7;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int din;
        string s, yr, mnth, day,dayName;
        vector<string> days {"Sun", "Mon", "Tues", "Wed", "Thurs", "Fri", "Sat"};
        cin >> s;
        rep(i, 6, 10)
        {
            yr.push_back(s[i]);
        }
        int bochor=stoi(yr);
        int lpyear = isLeapYear(stoi(yr));
        rep(i, 3, 5)
        {
            mnth.push_back(s[i]);
        }
        int mash = stoi(mnth);
        rep(i, 0, 2)
        {
            day.push_back(s[i]);
        }
        int tarikh = stoi(day);
        rep(i, 11, 14)
        {
            dayName.push_back(s[i]);
        }
        if (mash == 2)
        {
            if (lpyear)
                din = 29;
            else
                din = 28;
        }
        else if (mash == 4 || mash == 6 || mash == 9 || mash == 11)
            din = 30;
        else
            din = 31;

        ll dayno;
        ll dayy = stoi(day);
        ll div = ceil(dayy / 7*1.0);
        ll dayy-= div*7;
        if(dayy>0){
            dayno = dayy+1;
        }
        else{
            dayno = 1-dayy;
        }

        ll day = 1;

        cout<<"|---------------------------|\n"
<<"|Sun|Mon|Tue|Wed|Thu|Fri|Sat|\n"<<
"|---------------------------|\n";
        for (int i = 1; i <= 5; ++i)
        {
            for (int j = 0; j < 7; ++j)
            {
                
                
                
                    cout << "- ";
            }

            cout << "|"<<endl;
            cout<<"|---------------------------|\n";
        }
    }
    return 0;
}