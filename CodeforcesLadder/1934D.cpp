#include<bits/stdc++.h>

using namespace std;

bool binchk(int num) {
    while (num>0) {
        int temp = num % 10;
        if (temp!=0 && temp!=1) {
            return false;
        }
        num/=10;
    }
    return true;
}

bool gunkorbe(int n) {
    if (n==1) {
        return true;
    }
    if(binchk(n)) return true;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0 && binchk(i) && gunkorbe(n/i)) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (gunkorbe(n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
