//uva490
//rotating sentence
//將原先「由左往右，再由上至下」輸入的文字，改為直行輸出（由上往下，再由右至左）。
//sol:
//輸入多行文本：
//使用 gets() 函數讀取多行輸入，存儲在 s 數組中。s[i] 表示第 i 行的文本。
//l[i] 存儲第 i 行文本的長度。
//使用 maxlen 來記錄最長行的長度，這樣可以確定在旋轉輸出時，輸出的總列數。
//旋轉文本：
//外層循環 for (j = 0; j < maxlen; j++) 遍歷每一列，這相當於對應旋轉後的每一行。
//內層循環 for (k = 0; k < i; k++) 從最後一行開始，逐行向上讀取每一行的第 j 個字符，這樣能夠達到逆時針旋轉的效果。
//使用 if (j < l[i - 1 - k]) 來檢查當前列是否在該行的有效範圍內，如果是，就輸出對應字符；如果超過了該行的長度範圍，就輸出空格。
#include <iostream>
using namespace std;
string s[105];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int col = 0, row = 0;
    while (getline(cin, s[col])){
        row = max(row, (int)s[col].size());
        col++;
    }
    for (int i = 0; i < row; i++){
        for (int j = col-1; j >= 0; j--){
            if (i >= s[j].size()) cout << " ";
            else cout << s[j][i];
        }
        cout << "\n";
    }
    return 0;
}







