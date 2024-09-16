//498's
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string x_str;
    string a_str;

    // 讀取 x 和多項式係數
    while (getline(cin, x_str))
    {
        int x = stoi(x_str); // 將輸入的 x 轉為整數
        getline(cin, a_str); // 讀取係數列表
        istringstream iss(a_str);
        int num;
        vector<int> coefficients;

        // 將係數讀取到向量中
        while (iss >> num)
        {
            coefficients.push_back(num);
        }

        int n = coefficients.size() - 1; // 多項式的次數
        int total = 0;

        // 計算導數的值
        for (int i = 0; i < n; ++i)
        {
            total += coefficients[i] * (n - i) * pow(x, n - i - 1);
        }

        // 輸出導數結果
        cout << total << endl;
    }

    return 0;
}
