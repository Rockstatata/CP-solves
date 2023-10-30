#include<bits/stdc++.h>
 
using namespace std;

const int N = 1e7+10;
vector<bool>isPrime(N,1);
vector<int>lowestprime(N, 0 ),highestprime(N);
vector<int>prime_factors;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i<N;i++){
        if(isPrime[i]==true){
            lowestprime[i]=highestprime[i]=i;
            for(int j = 2*i;j<N;j+=i){
                isPrime[j]=false;
                highestprime[j]=i;
                if(lowestprime[j]==0){
                    lowestprime[j]=i;
                }
            }
        }
    }
    int num;cin>>num;
    while(num>1){
        int prime_factor=highestprime[num];
        while(num%prime_factor==0){
            num/=prime_factor;
            prime_factors.push_back(prime_factor);
        }
    }
    for(int i = 2;i<100;i++){
        cout<<lowestprime[i]<<" "<<highestprime[i]<<endl;
    }
    for(auto factor:prime_factors){
        cout<<factor<<" ";
    }
}