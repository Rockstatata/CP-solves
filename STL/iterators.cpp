#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // allows us to access values of containers without using indexes
    vector<int>v = {2,3,4,5,7};
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int> ::iterator it = v.begin();
    cout<<(*it)<<endl;
    cout<<(*(it+1))<<endl;
    for(it = v.begin();it !=v.end();it++){
        cout<<(*it)<<endl;
    }
    vector<pair<int,int>>v_p={{1,2},{2,3},{3,4}};
    vector<pair<int,int>>:: iterator it2;
    for(it2=v_p.begin();it2!=v_p.end();it2++){
        cout<<(*it2).first<<" "<<(*it2).second<<endl;  
    }
    for(it2=v_p.begin();it2!=v_p.end();it2++){
        cout<<(it2)->first<<" "<<(it2)->second<<endl;  
    }
    //(*it2).first <=> it2->first
}