#include<bits/stdc++.h>
 
using namespace std;
 
void printvec(vector<int>&v){
    cout<<"size: "<<v.size()<<endl;
    for(int i = 0;i<v.size();i++){
        // v.size() -> O(1)
        cout<<v.at(i)<<endl;
    }
}
void printvec(vector<string>&v){
    cout<<"size: "<<v.size()<<endl;
    for(int i = 0;i<v.size();i++){
        // v.size() -> O(1)
        cout<<v.at(i)<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //Dynamic sized array
    vector<int>v;
    vector<double>d;
    vector<pair<int,int>>p;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x); //appends at end O(1)
    }
    printvec(v);
    // local vector -> 10^5 , global vector -> 10^7
    vector<int>x(10);  // allocates a vector of size 10
    vector<int>y(10,3); //prefills the vector with 3
    printvec(y);
    x.push_back(7);
    cout<<"size: "<<x.size()<<endl;
    x.pop_back();
    cout<<"size: "<<x.size()<<endl;
    vector<int> y2 = y; //array can't be copied, vector can be O(n)
    vector<int> &y3=y;
    y3[0]=2;
    printvec(y);
    vector<string>s;
    int len;
    cin>>len;
    for(int i = 0;i<len;i++){
        string l;
        cin>>l;
        s.push_back(l);
    }
    printvec(s);
}