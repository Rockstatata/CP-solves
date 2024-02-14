#include <bits/stdc++.h>

using namespace std;


long long pref[100001];

int checkPalindrome(int num)
{

	string str = to_string(num);

	int l = 0, r = str.length() - 1;

	while (l < r) {
		if (str[l] != str[r]) {
			return 0;
		}
		l++;
		r--;
	}
	return num;
}

void preCompute()
{
	for (int i = 1; i <= 100000; ++i) {

		pref[i] = pref[i - 1] + checkPalindrome(i);
	}
}

void printSum(int L, int R)
{
	cout << pref[R] - pref[L - 1]<< endl;
}

void printSumPalindromic(int l, int r)
{

	preCompute();
	printSum(l,r);
}

int main()
{
	int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        printSumPalindromic(l,r);
    }
}
