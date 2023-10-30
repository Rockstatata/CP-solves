#include <iostream>
#include <string>

using namespace std;

bool isDivisibleBy7(const string& number) {
    int length = number.length();
    int remainder = 0;

    for (int i = 0; i < length; ++i) {
        int digit = number[i] - '0';
        remainder = (remainder * 10 + digit) % 7;
    }

    return (remainder == 0);
}

int main() {
    string s;
    cin>>s;
    bool divisible = isDivisibleBy7(s);

    if (divisible) {
        cout << "Yes" <<endl;
    } else {
        cout << "No"<<endl;
    }

}
