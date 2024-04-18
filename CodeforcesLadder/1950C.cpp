#include<bits/stdc++.h>
#include<string>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string x = s.substr(0,2);
        string y = s.substr(3,2);
        string ans = s;
        string ap;
        int time = stoi(x);
        int time2 = stoi(y);
        if(time>12){
            ap += "PM";
            time-=12;
        }
        else if(time==0){
            ap+="AM";
            time+=12;
        }
        else{
            if(time==12){
                ap+="PM";
            }
            else ap += "AM";
        }
        string l = to_string(time);
        if(l.size()==1){
            char c = l[0];
            l[0] = '0';
            l+=c;
        }
        ans[0]=l[0];
        ans[1]=l[1];
        cout<<ans<<" "<<ap<<endl;
    }
}