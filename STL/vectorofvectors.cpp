#include<bits/stdc++.h>
 
using namespace std;

void printvec(vector<int>&v){
    cout<<"size: "<<v.size()<<endl;
    for(int i = 0;i<v.size();i++){
        // v.size() -> O(1)
        cout<<v.at(i)<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>>z;
    int n,x,len;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>len;
        //vector<int>temp;
        z.push_back(vector<int> ());
        for(int j = 0;j<len;j++){
            cin>>x;
            //temp.push_back(x);
            z[i].push_back(x);
        }
        //z.push_back(temp);
    }
    for(int i = 0;i<z.size();i++){
        printvec(z[i]);
    }
}