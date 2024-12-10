//Sort! Sort!! and Sort!!!
//先給你兩個數 N、M，然後給 N 個數，要你照某些規則排序。利用每個數字除以 M 的餘數由小到大排
//若排序中相鄰的兩數為一奇一偶且兩數除以 M 的餘數相等，則奇數要在偶數前面。
//若兩奇數除以 M 餘數大小相等，則原本數值較大的奇數排在前面。
//同樣的，若兩偶數除以 M 餘數大小相等，則較小的偶數排在前面。


#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
//function cmp:用於 sort() 函數進行排序。比較邏輯如下：
//i 和 j 的 m 的餘數不同，則 i 的餘數小於 j 的餘數時優先。
//如果 i 和 j 的 m 的餘數相同:
//若 i 和 j 都是奇數（i & 1 和 j & 1 為 true），則按降序排序，即大數在前。
//若 i 和 j 都是偶數（!(i & 1) 和 !(j & 1)），則按升序排序，即小數在前。
//若一個是奇數，一個是偶數，則奇數優先。

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
//main function:
//讀入數字後，使用 sort(nums.begin(), nums.end(), cmp) 對 nums 進行排序，cmp 是自定義的比較函數。
//排序後，輸出結果，每個數字占一行
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
