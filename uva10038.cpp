//Jolly Jumper
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