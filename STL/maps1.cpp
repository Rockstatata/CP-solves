#include<bits/stdc++.h>
 
using namespace std;

void printmap(map<int,string>&m){
    cout<<"Size: "<<m.size()<<endl;
    for(auto &pr:m){ //O(nlogn)
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<int,string>m;
    m[1]="abc"; //O(log(n)), because sorted in sorted order
    m[5]="cdc";
    m[3]="acd";
    //m[7]="aaa"; // this has more preference
    m.insert({7,"lol"}); //key values are unique, gets replaced
    m.insert({4,"afg"});
    m.insert(make_pair(6,"bdc"));
    m.insert(make_pair(7,"alal"));
    map<int,string>:: iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    for(auto &pr:m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    auto it2 = m.find(9);  // Searching is also (O(logn))
    if(it2==m.end()){
        cout<<"No value"<<endl;
    }
    else{
        cout<<(*it2).first<<" "<<(*it2).second<<endl;
    }
    printmap(m);
    m.erase(7); // Deletes in O(logn)
    printmap(m);
    auto it3 = m.find(5);
    if(it!=m.end())m.erase(it3);
    printmap(m);
    //here clear is a function which works on all containers;
    m.clear();
    printmap(m);
    map<string,string>s;
    s["abcd"]="abcd";
    
}