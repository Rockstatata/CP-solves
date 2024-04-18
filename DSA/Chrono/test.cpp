#include<bits/stdc++.h>
#include<chrono>

using namespace std::chrono; 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    auto old = steady_clock::now();

    //test with end line

    for(int i = 0;i< 1000000;i++){
        cout<<"test"<<endl;
    }
    auto test1 = steady_clock::now() - old;

    old = steady_clock::now();

    // test with endline character

    for(int i = 0;i<1000000;i++){
        cout<<"test \n";
    }

    auto test2 = steady_clock::now() - old;

    cout<<"Test with endl: "<<duration_cast<milliseconds>(test1).count()<<endl;
    cout<<"Test with \\n: "<<duration_cast<milliseconds>(test2).count()<<endl;
}