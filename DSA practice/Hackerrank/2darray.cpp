#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[6][6]={},sum=0,max=-64;
    for(int i = 0;i<6;i++){
        for(int j = 0;j<6;j++){
            cin>>arr[i][j];
        }
    }
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            if(sum>max){
                max=sum;
            }
        }
    }
    cout<<max<<endl;
}