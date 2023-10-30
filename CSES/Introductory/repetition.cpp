#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int len = s.length();
    int l = 1, max= 1;
    int i = 0;
    while(i<len-1){
        while(s[i]==s[i+1]){
            l++;
            if(l>=max) max=l;
            i++;
        }
        l=1;
        i++;
    }
    cout<<max<<endl;
}