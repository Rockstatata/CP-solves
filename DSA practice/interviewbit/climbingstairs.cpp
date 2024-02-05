#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A[] {54, 5, 68, 68, 94, 39, 52, 84, 4, 6, 
    53, 68, 1, 39, 7, 42, 69, 59, 94, 85, 53, 10, 66, 42, 
    71, 92, 77, 27, 5, 74, 33, 64, 76, 100, 37, 25, 99, 
    73, 76, 66, 8, 64, 89, 28, 44, 77, 48, 24, 28, 36, 17, 
    49, 90, 91, 7};
    int n1 = int(sizeof(A)/sizeof(A[0]));
    long long i,sum = 0;
    sum+=A[0];
    for(i = 0;i<n1;){
        if((i+2<n1 && A[i+2]<=A[i+1]) || i+2==n1-1){
            sum+=A[i+2];
            i+=2;
        }
        else if(i+1<n1){
            if(i+2>=n1 || A[i+2]<=A[i+1]){
                sum+=A[i+1];
                i++;
            }
            else{
                sum+=A[i+1];
                i++;
            }
        }
        else if(i==n1-1){
            break;
        }
    }
    printf("%lli\n",sum);

}