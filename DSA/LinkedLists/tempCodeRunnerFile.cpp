#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, y;
int g = extended_euclidean(a, m, x, y);
if (g != 1) {
    cout << "No solution!";
}
else {
    x = (x % m + m) % m;
    cout << x << endl;
}

    return 0;
}
