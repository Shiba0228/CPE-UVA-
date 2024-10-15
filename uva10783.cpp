//odd sum
//計算題目提供兩數範圍內之奇數總和
// 用迴圈計算 a~b之奇數相加
#include <iostream>
using namespace std;

int main(){
    int t, a, b, sum;

    cin >> t; // size of test case
    for (int i = 0; i < t; i++){
        cin >> a >> b;

        sum = 0;
       //這段程式碼檢查起始數字 a 是否為偶數。如果 a 是偶數，則將 a 加 1 使其變成下一個奇數。這樣可以確保迴圈只處理奇數。
        if (a % 2 == 0){
            a++;
        }
       // while 迴圈會從 a 開始，每次加 2（這樣確保每次只處理奇數），並將其累加到變數 sum 中。
        //迴圈繼續執行直到 a 超過 b，即處理完範圍內所有奇數。
        while (a <= b){
            sum = sum + a;
            a += 2;
        }
        cout << "Case " << i+1 << ": " << sum << endl;
    }


    return 0;
}
