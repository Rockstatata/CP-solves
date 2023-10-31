#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x1,x2,y1,y2,x3,y3,x4,y4,d;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2){
        d=abs(y1-y2);
        x3=x1+d;
        x4=x2+d;
        if(x3>1000) x3-=((x3));
        if(x3<-1000) x3+=((x3));
        if(x4>1000) x4-=((x4));
        if(x4<-1000) x4+=((x4));
        y3=y1;
        y4=y2;
        cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
    }
    if(y1==y2){
        d=abs(x1-x2);
        y3=y1+d;
        y4=y2+d;
        if(y3>1000) y3-=((y3));
        if(y3<-1000) y3+=((y3));
        if(y4>1000) y4-=((y4));
        if(y4<-1000) y4+=((y4));
        x3=x1;
        x4=x2;
        cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
    }
    else if(x1!=x2 && y1!=y2){
        int d1 = abs(x1-x2);
        int d2 = abs(y1-y2);
        if(d1!=d2){
            cout<<-1<<endl;
        }
        else{
            x3=x1;
            y3=y2;
            x4=x2;
            y4=y1;
            cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
        }
    }
}