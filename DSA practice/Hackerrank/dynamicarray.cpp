#include<bits/stdc++.h>
 
using namespace std;


vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> temp;
    for (int i=0; i<n;i++){
        temp.push_back(answer);
    }
    int lastAnswer = 0,x,y,idx;
    for(int i=0; i<queries.size();i++){
        x = queries[i][1];
        y = queries[i][2];
        idx = (x^lastAnswer)%n; 
        if (queries[i][0] == 1){
            temp[idx].push_back(y);
        }
        if (queries[i][0] == 2){
            lastAnswer = temp[idx][y%(temp[idx].size())]; 
            answer.push_back(lastAnswer);
        }
    }
    
    return answer;
}   
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q,lastAnswer;
    cin>>n>>q;
    vector<vector<int>>queries;
    vector<int>answer;
    int c,x,y,l;
    for(int i = 0;i<q;i++){
        cin>>c>>x>>y;
        queries.push_back(answer);
        queries[i].push_back(c);
        queries[i].push_back(x);
        queries[i].push_back(y);
    }
    answer = dynamicArray(n,queries);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }
}   