#include <iostream>
using namespace std;
 
int main() {
    int T, N;
    cin >> T;
    while (T--){
        cin >> N;
        int X1 = N;
        int b1 = 0;
        while (X1){
            b1 += X1 & 1;
            X1 >>= 1;
        }
        int X2 = 0;
        int mul = 1;
        X1 = N;
        while (X1){
            X2 += (X1 % 10) * mul;
            X1 /= 10;
            mul *= 16;
        }
        int b2 = 0;
        while (X2){
            b2 += X2 & 1;
            X2 >>= 1;
        }
        cout << b1 << " " << b2 << "\n";
    }
    return 0;
}