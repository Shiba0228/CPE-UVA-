//Summing Digits 
//將輸入值之所有位數相加，直到相加至 <10 之正整數，即輸出
#include <iostream>
using namespace std;
  
int solve(int x) {
    int set = 0;
    while (x) {
        set += x % 10;
        x /= 10;
    }
    if (set < 10) return set;
    else return solve(set);
}
  
int main() {
    int n;
    while (cin >> n && n) {
        cout << solve(n) << "\n";
    }
    return 0;
}
