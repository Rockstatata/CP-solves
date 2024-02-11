#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>&a) {
    unordered_set<int>st;
    int len = a.size(), count = 1, longest = 1;
    for(int i = 0;i<len;i++){
        st.insert(a[i]);
    }
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            count = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                count++;
                x+=1;
            }
            longest =max(longest,count);
        }
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
