#include <iostream>
using namespace std;
int main() {
    int n, a;
    int a0 = 1;
    int a1 = 1;
    cin >> n;
    for (int i = 1; i <= n; i++){
        a = a0;
        a0 = a1;
        a1 = a + a0;
        cout << a << endl;        
    }
}
