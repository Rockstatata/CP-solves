#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int len = s.size();
    map<char, long long> hash;
    for(int i= 0;i<len;i++){
        hash[s[i]]++;
    }   
    string firsthalf="",secondhalf="";
    int oddc=0;
    char oddchar;
    for (auto x : hash) {
        if (x.second % 2 == 1) {
            oddc++;
            oddchar = x.first;
        }
    }
    if((oddc==0 && hash.size()==1) || (oddc==1 && len%2!=0)){
       for (auto x : hash) { 
            string sp(x.second / 2, x.first);
            firsthalf = firsthalf + sp;
            secondhalf = sp + secondhalf;
        }
        cout<<firsthalf+oddchar+secondhalf<<endl;
        return 0;
    }
    else{
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    
}