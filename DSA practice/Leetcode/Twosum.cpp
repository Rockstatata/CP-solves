#include<bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>returnSize;
        int len=nums.size();
        for(int i=0;i<(len-1);i++){
            for(int j = i+1;j<len;j++){
                if((nums[i]+nums[j])==target){
                    returnSize.push_back(i);
                    returnSize.push_back(j);
                    break;
                }
            }
        }
    return returnSize;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}