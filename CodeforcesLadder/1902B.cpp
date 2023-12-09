#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
const int N = 1e5 + 9, INF = 1e9;
 
void solve() 
{
    ll n, point, class_point, lab_point;
    cin >> n >> point >> class_point >> lab_point;
    ll class_no = n;
    ll lab_no = ((n - 1) / 7) + 1;
 
    ll busy_day = 0, done = 0;
    ll triple_point = class_point + 2 * lab_point;
    ll double_point = class_point + lab_point;
    ll triple_no = lab_no / 2;
    ll double_no = lab_no % 2;
    ll triple_need = (point / triple_point) + (point % triple_point != 0);
    done = min(triple_no, triple_need);
    busy_day += done;
    point -= (done * triple_point);
 
    ll double_need = (point / double_point) + (point % double_point != 0);
    done = min(double_no, double_need);
    if(point > 0) busy_day += done;
    point -= (done * double_point);
 
    ll need = (point / class_point) + (point % class_point != 0);
    if(point > 0) busy_day += need;
 
    cout << n - busy_day << "\n";
}
 
int main()
{
    FAST_IO
 
    int t = 1, case_number = 1;
    cin >> t;
 
    while(t--)
    {
        // cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}