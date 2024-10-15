//an easy problem
//題目給定一個 N 進制 (2 ≤ N ≤ 62) 的數字 R，R 保證可以被 (N-1) 整除。求符合提議的最小 N。當 N = 62 時，用來表示62進制的字符為 0..9, A..Z, a..z。
//一個N進位制的數，表示成【abc】 = a * N^2 + b * N + c
                             //= a*N*(N-1+1) + b*(N-1+1) + c
                             //= a*N*(N-1) + a*N + b*(N-1) + b + c
                             //= a*N*(N-1) + a*(N-1) + a + b*(N-1) + b + c
                            //= (a * N + a + b) * (N-1) + (a + b + c)

#include <iostream>
using namespace std;
 
int main() {
    int sum, mx, temp;
    string s;
    while (getline(cin, s)){
        sum = 0;
        mx = 1;
        int i;
      //如果字元是數字（'0' 到 '9'），那麼將該字元轉換成其對應的數字（s[i] - '0'）。
      //如果字元是大寫字母（'A' 到 'Z'），那麼將該字元轉換成對應的數值（A 對應 10，B 對應 11，依此類推，s[i] - 'A' + 10）。
      //如果字元是小寫字母（'a' 到 'z'），將其轉換成對應的數值（a 對應 36，b 對應 37，依此類推，s[i] - 'a' + 36）。
      //如果字元不是數字或字母，則忽略它並繼續處理下一個字元。
        for (i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                temp = s[i] - '0';
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                temp = s[i] - 'A' + 10;
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                temp = s[i] - 'a' + 36;
            }
            else continue;
 
            if (mx < temp)
                mx = temp;
            sum += temp;
        }
 
        for (i = mx; i < 62; i++)
            if (!(sum % i)) {
                cout << i + 1 << "\n";
                break;
            }
 
        if (i == 62)
            cout << "such number is impossible!\n";
    }
    return 0;
}
