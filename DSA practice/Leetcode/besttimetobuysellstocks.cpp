#include<bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size(),maxp=0,l=0,r=1,pro;
        while(r<len){
            if(prices[l]<prices[r]){
                pro = prices[r]-prices[l];
                maxp= max(maxp,pro);
            }
            else{
                l=r;
            }
            r++;
        }
        return maxp;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int>v{7,6,4,3,1};
    cout<<s.maxProfit(v)<<endl;
}