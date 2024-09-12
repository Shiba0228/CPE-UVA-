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
