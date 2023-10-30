#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //unordered maps 
    // time complexity ==> O(1) (insertion, access)
    // valid data types, only basic data types in key
    unordered_map<int,string>m;
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    m[6] = "a";
    m[5] = "cde";
    auto it = m.find(7);
    if(it!=m.end()){
        m.erase(it);
    }
    multimap<int,string>mm;
    // duplicate values allowed
}