//divide but not conquer
//uva10190
//cmath
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n, m, i;

    while (cin >> n >> m) { //input
        long long cn1 = m;

        for (i = 1; cn1 < n && m > 1; i++) { //計算n是否為m的次方數 
            cn1 = pow(m, i);
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
