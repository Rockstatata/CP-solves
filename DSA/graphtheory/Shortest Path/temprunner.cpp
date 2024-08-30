#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pair<int,int> *arr;
    arr = new pair<int,int>({0,0});
    arr[0] = arr[0];
    cout<<arr[0].first<<endl;
    cout<<arr[0].second;  
}