#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int i = 1;
    cout<<fixed<<setprecision(10);
    while(i<=t){
        double v1,v2,v3,a1,a2;
        cin>>v1>>v2>>v3>>a1>>a2;
        double t1 = v1/a1, t2 = v2/a2;
        double t3 = t1; 
        if(t1<t2) t3 = t2;
        double d1 = (v1*t1)-(0.5*(a1*t1*t1));
        double d2 = (v2*t2)-(0.5*(a2*t2*t2));
        double d3 = v3 * t3;
        double d4 = d1+d2;
        cout<<"Case "<<i<<": ";
        cout<<d4<<" "<<d3<<endl;
        i++;
    } 
}