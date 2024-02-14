#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    scanf("%lld",&t);
    ll i =1;
    while(i<=t){
        ll n;
        scanf("%lld",&n);
        ll hist[n];
        for(ll i = 0;i<n;i++){
            scanf("%lld",&hist[i]);
        }
        stack<ll>track;
        ll left[n] {0};
        ll right[n] {0};
        ll area[n] {0};
        for(ll i = 0;i<n;i++){
            while( !track.empty()){
                if(hist[track.top()] >= hist[i])
                    track.pop();
                else
                    break;
            }

            if(track.empty()){
                left[i] = 0;
            }
            else{
                left[i] = track.top()+1;
            }

            track.push(i);
        }
        while(!track.empty()){
            track.pop();
        }
        for(ll i=n-1;i>=0;i--){
            while(!track.empty()){
                if(hist[track.top()] >= hist[i])
                    track.pop();
                else
                    break;
            }
            if(track.empty()){
                right[i] = n-1;
            }
            else{
                right[i] = track.top()-1;
            }
            track.push(i);
        }

        ll maxi = 0;
        for(ll i = 0;i<n;i++){
            area[i] = (hist[i]*(right[i]-left[i]+1));
            maxi = max(area[i],maxi);
        }
        cout<<"Case "<<i<<": ";
        cout<<maxi<<endl;
        i++;
    }
}