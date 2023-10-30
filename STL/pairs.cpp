#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pair<int,string>p;
    pair<int,int>p2;
    p=make_pair(2,"abc");
    p2=make_pair(3,5);
    pair<int,string>p1 =p; // copy assign
    p1.first = 3;
    pair<int,string>&p3 =p;
    p3.first = 3;
    cout<<p.first<<" "<<p.second<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;
    // to track both elements at once;
    int a[]={1,2,3};
    int b[]={2,3,4};
    pair<int,int>p_array[3];
    p_array[0]={1,2};
    p_array[1]={2,3};
    p_array[2]={3,4};
    swap(p_array[0],p_array[2]);
    for(int i = 0;i<3;i++){
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
    cin>>p.first>>p.second;
    cout<<p.first<<" "<<p.second<<endl;
}