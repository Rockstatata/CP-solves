#include<bits/stdc++.h>
 
using namespace std;

bool isAnagram(string s, string t) {
    int pref[27] {},pref2[27]{ };
    for(int i = 0;i<s.size();i++){
        int y = s[i] - 97;
        pref[y]++;
    }
    for(int i = 0;i<t.size();i++){
        int y = t[i] - 97;
        pref2[y]++;
    }
    for(int i = 0;i<27;i++){
        if(pref[i]!=pref2[i]){
            return false;
        }
    }
    return true;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,x;
    cin>>s>>x;
    if(isAnagram(s,x)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}