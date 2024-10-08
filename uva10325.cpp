//Simply Emirp
//GCD, LCM
#include <iostream>
using namespace std;
int p[1000005];
 
int main() {
    p[1] = 1;
    //使用篩選法（埃拉托斯特尼篩法）來標記所有非質數
    for (int i = 2; i < 1000005; i++){
        if (p[i] == 0){
            for (int j = i+i; j < 1000005; j+=i){
                p[j] = 1;
            }
        }
    }
    int N, N1, N2;
 //從標準輸入中讀取一個整數 N 並進行以下操作
 //將 N 的反向數存入 N2。例如，123 會轉換為 321
 //如果 N 是非質數 (p[N] 為 1)，輸出 N is not prime.
 //如果 N 是質數，且反向數 N2 不等於 N 並且 N2 也是質數，則輸出 N is emirp.。反質數（emirp）是指一個數及其反向數均為質數且不相等。
 //否則，僅輸出 N is prime.，表示 N 是質數但不是反質數。
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
