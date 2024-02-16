#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int i = 1;
    while(i<=t){
        vector<string>commands {"VISIT","BACK","FORWARD","QUIT"};
        stack<string>back,forward;
        string home ="http://www.lightoj.com/";
        cout<<"Case "<<i<<":"<<endl;
        while(1){
            string s,link;
            cin>>s;
            if(s=="QUIT"){
                break;
            }
            else{
                size_t found;
                string command;
                for(int i=0;i<4;i++){
                    found = s.find(commands[i]);
                    if(found!=string::npos){
                        command = commands[i];
                        break;
                    }
                }
                if(command=="VISIT"){
                    cin>>link;
                    back.push(link);
                    cout<<link<<endl;
                    while(!forward.empty()){
                        forward.pop();
                    }
                }
                if(command=="BACK"){
                    if(back.empty()){
                        cout<<"Ignored"<<endl;
                        continue;
                    }
                    forward.push(back.top());
                    back.pop();
                    if(!back.empty())cout<<back.top()<<endl;
                    else{
                        cout<<home<<endl;
                    }
                }
                if(command=="FORWARD"){
                    if(forward.empty()){
                        cout<<"Ignored"<<endl;
                        continue;
                    }
                    back.push(forward.top());
                    forward.pop();
                    cout<<back.top()<<endl;
                }
            }
            s.clear();
        }
        i++;
    }
}