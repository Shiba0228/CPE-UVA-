//divide but not conquer
//uva10190
//cmath
//此問題的目標是將某個整數n除以另一個整數m直到 n = 1，這方法將會獲得一個數字序列。
//我們假設該序列的每個數字為a[i]，假設它有k個數字(即必須進行 k−1 個連續除法才能達到 n = 1)。
//根據以下限制，此序列必唯一：
//1. a[1] = n, a[i] = a[i − 1] ÷ m, for all 1 < i ≤ k
//2. a[i] 被 m 整除(a[i] mod m = 0) for all 1 ≤ i < k
//3. a[1] > a[2] > a[3] > ... > a[k]

//以下為舉例：
//如果n = 125且m = 5，則根據上述過程會得到125、25、5、1(做了3次除法：125/5、25/5、5/5)。
//因此，k = 4，a[1] = 125、a[2] = 25、a[3] = 5、a[4] = 1。
//如果n = 30且m = 3，則根據上述過程會得到30、10、3、1。
//但是a[2] = 10 且 10 mod 3 = 1，違反了限制2，所以此序列不存在。
//如果序列不存在，我們認為這不好玩，因此非常"Boring!"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n, m, i;

    while (cin >> n >> m) { //input
        long long cn1 = m;

        for (i = 1; cn1 < n && m > 1; i++) { //計算n是否為m的次方數 
            cn1 = pow(m, i); //cmath
        }

        if (cn1 > n || m <= 1) {//不是次方數
            cout << "Boring!" << endl;
        } else {
            while (cn1 > 0) {//從n開始輸出m次方數 
                cout << cn1;
                if (cn1 != 1) {
                    cout << " ";
                } else {
                    cout << endl;
                }
                cn1 /= m;
            }
        }
    }
    return 0;
}
