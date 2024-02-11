#include<bits/stdc++.h>
 
using namespace std;

vector<int> RearrangebySign(vector<int>& A, int n){
    int neg = 1, pos = 0,count = 1;
    vector<int> ans(n,0);
    for(int i =0;i<n;i++){
        if(A[i]<0){
            ans[neg]=A[i];
            neg+=2;
        }
        else if(A[i]>0){
            ans[pos]=A[i];
            pos+=2;
        }
    }
    return ans;
}
 
int main() {
    
  int n = 4;
  vector<int> A {1,2,-4,-5};

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}