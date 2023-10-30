#include<bits/stdc++.h>

using namespace std ;

int main(){
    int tc , length , div , num , maxi ;
    long sum ;
    cin >> tc ;
    while(tc--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        bool ok = true;
        int left, right;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
            if (arr[i] % k) {
                if (ok)
                    left = i;
                right = i;
                ok = false;
            }
        }
        if (sum % k) {
            cout << n << endl;
        }
        else if (ok)
            cout << -1 << endl;
        else {
            cout << n - min(left + 1, n - right) << endl;
        }
    }
}