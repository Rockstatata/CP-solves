#include<bits/stdc++.h>
 
using namespace std;

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    long long int count = 1, max_count =1;
    long long int len = str.length();
    for(long long int i = 0;i<len-1;i++){
        if(str[i]==str[i+1]){
            count++;
            if(count>=max_count){
                max_count = count;
            }
        }
        else{
            count=1;
        }
    }   
    cout<<max_count<<endl;
}