#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, a, s;
    s = 0;
    cin >> n;
    int m[n];
    float c, f = (1 + sqrt(5)) / 2;
    for (int i = 0; i <= n - 1; i++){
        cin >> m[i];
    }
    for (int i = 0; i<= n - 1; i++){
        int a0 = 1, a1 = 1;
        for (int j = 1; j <= m[i]; j++){
            if (a1 == m[i]){
                s++;
                break;
            }
            a = a0;
            a0 = a1;
            a1 = a + a0;
            if (a > m[i])
            break;
        }
    }
    cout << s;
}
