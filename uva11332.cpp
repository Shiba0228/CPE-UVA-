//Summing Digits 
//將輸入值之所有位數相加，直到相加至 <10 之正整數，即輸出
#include <iostream>
using namespace std;
  
int solve(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    if (ret < 10) return ret;
    else return solve(ret);
}
  
int main() {
    int n;
    while (cin >> n && n) {
        cout << solve(n) << "\n";
    }
    return 0;
}
