#include<bits/stdc++.h>
#include<chrono>
#include<thread>
 
using namespace std;
using namespace std::chrono;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Starting Time point
    auto old = steady_clock::now();

    auto five_seconds = seconds(5);
    //std::this_thread::sleep_for(five_seconds);
    
    auto day = 24h;
    auto my_seconds = seconds(day);
    cout<<my_seconds.count()<<endl;


    auto dur = steady_clock::now() - old;

    std::cout<<duration_cast<microseconds>(dur).count()<<endl;
}