#include <iostream>
using namespace std;
int main() {
    int s, a, n;
    for (int j = 100; j<=999;j++){
        s = 0;
        n = j;
        for (int i = 1; i <= 3; i++){
            a = n % 10;
            n = (n - a) / 10;
            s += a*a*a;
        }
        if (s == j)
        cout << j << endl;
    }
}
