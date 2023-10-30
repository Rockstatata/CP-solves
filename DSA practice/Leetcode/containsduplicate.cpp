#include<bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<(len-1);i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int>v{1,1,1,3,3,4,3,2,4,2};
    cout<<s.containsDuplicate(v)<<endl;

}