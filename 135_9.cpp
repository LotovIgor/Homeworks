#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n, a, s, p = 0;
    s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a;
        for (int j = 2; j <= sqrt(a); j++){
            if ((a % j == 0) and (a != j)){
                p = 1;
                break;
            }
            if (a = 1){
                p = 1;
                break;
            }
        }
        if (p == 0){
            s++;
        }
        p = 0;
    }
    cout << s;
}
