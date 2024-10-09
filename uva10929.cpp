//you can say 11
//判定是否是11 的倍數
//每列資料有一個正整數N，N 最大可能到1000 位數。
//若N = 0 代表輸入結束

//sol
//使用 cin >> s 讀取每一個數字 s。因為這些數字可能非常大（最多 1000 位），所以讀取為字符串形式。
//計算奇數位和偶數位的和
//使用 for 迴圈遍歷字符串 s 的每一位數字：
//如果索引 i 是奇數（i % 2 為 1），則將該位數字加到 odd 中。
//如果索引 i 是偶數（i % 2 為 0），則將該位數字加到 even 中。
//s[i] - '0' 的作用是將字符轉換成對應的整數值。例如，字符 '3' 會轉換成數字 3。
//判斷是否是 11 的倍數:使用差值法來判斷是否為 11 的倍數：如果數字 N 的奇數位數字和與偶數位數字和的差是 11 的倍數，則該數是 11 的倍數
//用 (odd - even) % 11 來檢查這個差值是否能被 11 整除

#include<iostream>
using namespace std;
  
int main() {
    string s;
    while (cin >> s) {
        if (s == "0") break;
        int odd = 0, even = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2) {
                odd += s[i] - '0';
            } else {
                even += s[i] - '0';
            }
        }
        if ((odd - even) % 11 == 0) {
            cout << s << " is a multiple of 11.\n";
        } else {
            cout << s << " is not a multiple of 11.\n";
        }
    }
    return 0;
}
