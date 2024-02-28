#include<bits/stdc++.h>
 
using namespace std;

int wordladder(auto startword, auto wordlist, auto targetword){
    queue<pair<string,int>>q;
    q.push({startword,1});
    wordlist.erase(startword);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word==targetword) return steps;
        for(int i = 0;i<word.size();i++){
            char original = word[i];
            for(char ch = 'a';ch<='z';ch++){
                word[i] = ch;
                if(wordlist.find(word)!= wordlist.end()){
                    wordlist.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string startword = "hit", targetword = "cog";
    set<string>wordlist = {"hot","dot","dog","lot","log","cog"};
    int shortestpath = wordladder(startword,wordlist,targetword);
    cout<<shortestpath<<endl;
}