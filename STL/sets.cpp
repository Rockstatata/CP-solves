#include<bits/stdc++.h>
 
using namespace std;

void printset(set<string> &s){
    for(string value:s){
        cout<<value<<endl;
    }
    for(auto it = s.begin();it!= s.end();it++){
        cout<<(*it)<<endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<string>s;
    set<int>i;
    s.insert("abc"); //O(log(n))
    s.insert("xyz");
    s.insert("bcd");
    auto it = s.find("abc");
    if(it!=s.end()){
        cout<<(*it)<<endl;
        s.erase(it);
        s.erase("xyz");
    }
    s.insert("abc");
    printset(s); //prints in sorted order
    unordered_set<string>x;
    // doesn't get ordered, O(1)
    x.insert("abc"); //O(log(n))
    x.insert("xyz");
    x.insert("bcd");
    for(auto val:x){
        cout<<val<<endl;
    }
    multiset<string>m; // allows duplicates in sorted order
    m.insert("abc");
    m.insert("abc");
    m.insert("xyz");
    m.insert("bcd");
    auto it2 = m.find("abc");
    if(it2!= m.end()){
        m.erase(it2);  // only the address pointed by iterator gets deleted
        m.erase("abc"); // if passed by value all the same values get deleted
    }
    for(auto val:m){
        cout<<val<<endl;
    }
}