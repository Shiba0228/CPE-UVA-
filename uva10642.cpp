//can you solve it
#include <iostream>
using namespace std;
  
int main() {
    int T;
    long long x, y, n, step1, step2;
    cin >> T;
    for (int Case = 1; Case <= T; Case++){
        cout << "Case " << Case << ": ";
        cin >> x >> y;
        if (x == 0 && y == 0) step1 = 0;
        else {
            n = x + y - 1;
            step1 = (n * n + 3 * n) / 2 + (x + 1);
        }
        cin >> x >> y;
        n = x + y - 1;
        if (x == 0 && y == 0) step2 = 0;
        else {
            n = x + y - 1;
            step2 = (n * n + 3 * n) / 2 + (x + 1);
        }
        cout << step2 - step1 << "\n";
    }
    return 0;
}