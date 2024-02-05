#include<bits/stdc++.h>
 
using namespace std;

int getbit(int n , int i){
    int mask = (1<<i);
    return (n&mask)>0?1:0;
}

void setbit(int &n,int i){
    int mask = (1<<i);
    n = n | mask;
}

void clearbit(int &n,int i){
    int mask = ~(1<<i);
    n = n & mask;
}

void updatebit(int &n,int i, int v){
    if(v==0){
        clearbit(n,i);
    }
    else{
        setbit(n,i);
    }

}

void clearlastbits(int &n,int i){
    int mask = -1<<i;
    n = n & mask;
}

void clearbitsinrange(int &n, int i, int j){
    int a = -1<<(i+1);
    int b = (1<<j)-1;
    int mask = a | b;
    n = n & mask;
}


 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int i;
    cin>>i;
    int bit = getbit(n,i);
    cout<<bit<<endl;
    clearbit(n,2);
    cout<<n<<endl;
    setbit(n,2);
    cout<<n<<endl;
    updatebit(n,1,1);
    cout<<n<<endl;
    clearlastbits(n,2);
    cout<<n<<endl;
    clearbitsinrange(n+=11,3,1);
    cout<<n<<endl;
}