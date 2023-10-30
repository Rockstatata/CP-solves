#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a = abs(n)%10, b = (abs(n)%100)/10;
    if(n>0){
        cout<<n<<endl;
    }
    else{
        if(a>=b){
            n/=10;
            cout<<n<<endl;
        }
        else{
            n/=100;
            if(n==0){
                if(a!=0){
                    cout<<"-"<<a<<endl;
                }
                else{
                    cout<<a<<endl;
                }
            }
            else{
                cout<<n<<a<<endl;
            }
        }
    }

}