#include<bits/stdc++.h>
 
using namespace std;

int search(vector<int>& nums, int target){
    int len = nums.size();
    int l = 0, r=len-1, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[l]<=nums[mid]){
            if(nums[mid] > target && nums[l]<=target){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        else{
            if(target<=nums[r] && nums[mid]<target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
    }
    return -1;

}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums {4,5,6,7,0,1,2};
    
}