//Primary Arithmetic
//在小學時我們都做過加法的運算，就是把2個整數靠右對齊然後，由右至左一位一位相加。如果相加的結果大於等於10就有進位（carry）的情況出現。你的任務就是要判斷2個整數相加時產生了幾次進位的情況。這將幫助小學老師分析加法題目的難度。
//計算輸入值的各個位數相加是否進位，若進位記得將加入下一個位數計算（注意：輸入值使用 unsigned long long int）
//判斷各輸出格式
//（注意：carry 超過 1 時，operation 要加s）
//a % 10 和 b % 10 取得 a 和 b 的最右一位數。
//將兩個數字的最右一位相加，再加上上次的進位（carry），如果和大於等於 10，則表示需要進位，進位次數 count 增加，並將進位標誌 carry 設為 1。
//如果和小於 10，則沒有進位，carry 設為 0。
//最後，將 a 和 b 各自除以 10，這樣就可以移除已經處理過的最右一位，繼續下一位的相加操作。
//當 a 和 b 都為 0 時，迴圈結束。
#include <iostream>
using namespace std;
int main() {
    int a, b;
    while(cin >> a >> b) {
        if(a == 0 && b == 0) return 0;

        // Calculation
        int count = 0, carry = 0;
        while(a || b) {    //當a或b有一數等於0便停止計算
            if(a%10 + b%10 + carry >= 10) {
                count++;
                carry=1;
            } else {
                carry=0;
            }
            a /= 10;
            b /= 10;
        }

        // Output
        if(count == 0) cout << "No carry operation.\n";
        else if(count == 1) cout << "1 carry operation.\n";
        else cout << count << " carry operations.\n";
    }
    return 0;
}
