#include<bits/stdc++.h>
 
using namespace std;

class hashtable{
    unordered_map<int,vector<string>> table;
public:
    long long hash(long long x){
        long long square = x * x;
        int size = ceil(log10(square));
        long long id;
        if(size<=3){
            id = square;
        }
        else{
            int mov = floor((size-3)/2);
            for(int i = 0;i<mov;i++){
                square/=10;
            }
            id = square % 1000;
        }
        return id;
    }

    void insert(long long x){
        string num = to_string(x);
        long long id = hash(x);
        vector<string> temp {num};
        if(table[id].empty())table[id] = temp;
        else table[id].push_back(num);
        cout<<id<<" : "<<num<<endl;
    }

    void find(long long x){
        long long id = hash(x);
        string num = to_string(x);
        long long int count = 0;
        for(auto x: table[id]){
            if(x==num) count++;
        }
        cout<<id<<" : "<<num<<" : "<<count<<endl;
    }

    void remove(long long x){
        long long id = hash(x);
        string num = to_string(x);
        for(auto it = table[id].begin(); it!=table[id].end();it++){
            if(*it == num) {
                table[id].erase(it);
                it--;
            }
        }
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    hashtable h;
    h.insert(4564);
    h.insert(112);
    h.insert(112);
    h.insert(112);
    h.find(112);
    h.remove(112);
    h.find(112);
}   