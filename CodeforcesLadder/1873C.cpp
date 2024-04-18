#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        char target[10][10];
        int score = 0;
        for(int i = 0;i<10;i++){
            for(int j = 0;j<10;j++){
                cin>>target[i][j];
                if((target[i][j]=='X') &&((i==0 && j>=0 && j<=9) || (i==9 && j>=0 && j<=9
                                       || (j==0 && i>=0 && i<=9) || (j==9 && i>=0 && i<=9)))){
                    score+=1;
                }
                else if((target[i][j]=='X') && ((i==1 && j>=1 && j<=8) || (i==8 && j>=1 && j<=8
                                       || (j==1 && i>=1 && i<=8) || (j==8 && i>=1 && i<=8)))){
                    score+=2;
                }
                else if((target[i][j]=='X') && ((i==2 && j>=2 && j<=7) || (i==7 && j>=2 && j<=7
                                       || (j==2 && i>=2 && i<=7) || (j==7 && i>=2 && i<=7)))){
                    score+=3;
                }
                else if((target[i][j]=='X') && ((i==3 && j>=3 && j<=6) || (i==6 && j>=3 && j<=6
                                       || (j==3 && i>=3 && i<=6) || (j==6 && i>=3 && i<=6)))){
                    score+=4;
                }
                else if((target[i][j]=='X') && ((i==4 && j>=4 && j<=5) || (i==5 && j>=4 && j<=5
                                       || (j==4 && i>=4 && i<=5) || (j==5 && i>=4 && i<=5)))){
                    score+=5;
                }
            }
        }
        cout<<score<<endl;
    }   
}