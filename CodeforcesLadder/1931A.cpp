#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, arr[3] = {0};
        cin>>n;
        int i = 2;
        while(n>27){
            n-=26;
            arr[i] = 26;
            i--;
        }
        if(i==0){
            arr[0] = n;
            n=0;
        }
        i = 0;
        if(n<=27 && n!=0){
            n-=1;
            arr[i]=1;
            if(n>0 && arr[2]==0){
                i++;
                arr[i]=1;
                n-=1;
                if(n>0){
                    i++;
                    arr[i]=n;
                    n=0;
                }
            }
            else if(arr[2]){
                arr[1]=n;
                n=0;
            }
        }
        char a = 'a'+arr[0]-1;
        char b = 'a'+arr[1]-1;
        char c = 'a'+arr[2]-1;
        cout<<a<<b<<c<<endl;
    }   
}