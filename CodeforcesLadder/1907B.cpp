#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string base;
        cin>>base;
        int n = base.length();
        vector<int>inds,indc;
        for(int i = 0;i<n;i++){
            if(base[i]>=97 && base[i]<=122){
                if(base[i]!='b'){
                    inds.push_back(i);
                }
                if(base[i]=='b'){
                    base[i]='\0';
                    if(!inds.empty()){
                        base[inds.back()]='\0';
                        inds.pop_back();
                    }
                }

            }
            if(base[i]>=65 && base[i]<=90){
                if(base[i]!='B'){
                    indc.push_back(i);
                }
                if(base[i]=='B'){
                    base[i]='\0';
                    if(!indc.empty()){
                        base[indc.back()]='\0';
                        indc.pop_back();
                    }          
                }
            }
        }
        for(int i =0;i<n;i++){
            if(base[i]!='\0'){
                cout<<base[i];
            }
        }
        cout<<endl;
    }
}