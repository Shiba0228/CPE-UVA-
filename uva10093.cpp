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
