//Simply Emirp
#include <iostream>
using namespace std;
int p[1000005];
 
int main() {
    p[1] = 1;
    for (int i = 2; i < 1000005; i++){
        if (p[i] == 0){
            for (int j = i+i; j < 1000005; j+=i){
                p[j] = 1;
            }
        }
    }
    int N, N1, N2;
    while (cin >> N){
        N1 = N;
        N2 = 0;
        while (N1){
            N2 *= 10;
            N2 += N1 % 10;
            N1 /= 10;
        }
        if (p[N]) cout << N << " is not prime.\n";
        else if (N2 != N && p[N2] == 0) cout << N << " is emirp.\n";
        else cout << N << " is prime.\n";
    }
    return 0;
}