#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    float n, x0, x, e;
    cin >> n;
    e = 0.0001;
    x0 = 0;
    x = n;
    while ( abs(x - x0) > e ) {
        x0 = x;
        x = (x + n/x) / 2;
    }
    cout << x << endl;
    cout << sqrt(n);
}
