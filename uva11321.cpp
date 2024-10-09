//Sort! Sort!! and Sort!!!
//先給你兩個數 N、M，然後給 N 個數，要你照某些規則排序。利用每個數字除以 M 的餘數由小到大排
//若排序中相鄰的兩數為一奇一偶且兩數除以 M 的餘數相等，則奇數要在偶數前面。
//若兩奇數除以 M 餘數大小相等，則原本數值較大的奇數排在前面。
//同樣的，若兩偶數除以 M 餘數大小相等，則較小的偶數排在前面。
#include "bits/stdc++.h"

using namespace std;

int n, m;
bool cmp(int i, int j) {
    if (i % m != j % m) {
        return i % m < j % m;
    }
    if ((i & 1) && (j & 1))
        return i > j;
    else if (!(i & 1) && !(j & 1))
        return i < j;
    else
        return i & 1;
}

int main() {
    while (cin >> n >> m, n) {
        cout << n << " " << m << endl;
        vector<int> nums(n);
        for (auto& i : nums) {
            cin >> i;
        }
        sort(nums.begin(), nums.end(), cmp);
        for (auto& i : nums)
            cout << i << endl;
    }
    cout << 0 << " " << 0 << endl;
}
