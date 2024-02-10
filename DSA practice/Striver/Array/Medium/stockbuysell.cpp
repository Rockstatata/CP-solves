#include<bits/stdc++.h>
 
using namespace std;

int maxProfit(vector<int>& arr, int& l, int& h){
    int len = arr.size();
    int min=__INT_MAX__;
    int max=0;
    for(int i = 0;i<len;i++){
        if(arr[i]<min){
            min = arr[i];
            l = i;
        }
        if((arr[i]-min) >max){
            max = arr[i] - min;
            h = i;
        }
    }
    return max;
}
 
int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int l=0,h=0;
    int maxPro = maxProfit(arr,l,h);
    cout << "Max profit is: " << maxPro << endl;
    cout<<l<<" "<<h<<endl;
}