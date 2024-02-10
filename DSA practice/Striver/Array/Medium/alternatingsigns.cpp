#include<bits/stdc++.h>
 
using namespace std;

vector<int> RearrangebySign(vector<int>& A, int n){
    int neg = 0, pos = 0,count = 1;
    vector<int> ans;
    ans.push_back(A[0]);
    for(int i =1;i<n;){
        if(A[i]<0 && count%2){
            ans.push_back(A[i]);
            count++;
        }
        else if(A[i]>0 && count%2==0){
            ans.push_back(A[i]);
            count++;
            i = pos;
        }
        else{
            if(A[i]<0){
                if(neg==0)neg = i;
            }
            if(A[i]>0){
                if(pos==0)pos = i;
            }
        }
    }
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