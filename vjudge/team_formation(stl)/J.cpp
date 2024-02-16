#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int i=1;
    while(i<=t){
        deque<int>dq;
        vector<string>commands {"pushLeft","pushRight","popLeft","popRight"};
        string s,command;
        cout<<"Case "<<i<<": "<<endl;
        int x,n,m;
        cin>>n>>m;
        while(m--){
            cin>>s;
            if(s=="pushLeft"){
                cin>>x;
                if(dq.size()==n){
                    cout<<"The queue is full"<<endl;
                    continue;
                }
                dq.push_front(x);
                cout<<"Pushed in left: "<<x<<endl;
            }
            if(s=="pushRight"){
                cin>>x;
                if(dq.size()==n){
                    cout<<"The queue is full"<<endl;
                    continue;
                }
                dq.push_back(x);  
                cout<<"Pushed in right: "<<x<<endl;                  
            }
            if(s=="popLeft"){
                if(dq.empty()){
                    cout<<"The queue is empty"<<endl;
                    continue;
                }
                x = dq.front();
                dq.pop_front();
                cout<<"Popped from left: "<<x<<endl;
            }
            if(s=="popRight"){
                if(dq.empty()){
                    cout<<"The queue is empty"<<endl;
                    continue;
                }
                x = dq.back();
                dq.pop_back();
                cout<<"Popped from right: "<<x<<endl;
            }
        }
        i++;
    }
}