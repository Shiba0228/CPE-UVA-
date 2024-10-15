//Jolly Jumper
//用vector解
//迴圈從索引 1 開始遍歷數列，用來計算相鄰兩個數字的差值 diff（使用絕對值 abs() 函數來確保為正數）。
//條件檢查：
//diff 的值必須介於 1 和 n−1 之間，否則就不是 Jolly。
//如果該差值 diff 已經出現過（即 d[diff] != 0），則數列不是 Jolly。
//如果任何條件不滿足，將 isJolly 設為 false，並終止檢查。
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> d(n, 0); // 使用 vector 初始化大小為 n 且所有元素初始為 0
        vector<int> sequence(n);
        bool isJolly = true;

        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }

        for (int i = 1; i < n; i++) {
            int diff = abs(sequence[i] - sequence[i - 1]);
            if (diff < 1 ||  diff >= n  ||  d[diff] != 0) {
                isJolly = false;
                break;
            }
            d[diff] = 1;
        }

        if (isJolly) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }

    return 0;
}
