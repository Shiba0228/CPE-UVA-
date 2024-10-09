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
#include <stdio.h> 
#include <string.h>

using namespace std;

int main() {
    char s[105][105]; // 用來存儲最多 105 行，每行最多 105 個字符的輸入
    int i = 0, j, k, maxlen = 0; // i：計數輸入的行數，maxlen：最長行的長度
    int l[105]; // 存儲每行的長度
    // 讀取多行輸入
    while(gets(s[i])) {
        l[i] = strlen(s[i]); // 儲存當前行的長度
        if(strlen(s[i]) > maxlen)
            maxlen = strlen(s[i]); // 更新最長行的長度
        i++;  // 行數自增
    }
   // 將文本進行旋轉輸出
    for(j = 0; j < maxlen; j++) { // 遍歷每一列，從第 0 列到最長列
        for(k = 0; k < i; k++) { // 遍歷每一行，從最底行向上讀取
            if(j < l[i - 1 - k]) // 確保當前列在該行的長度範圍內
                cout << s[i - 1 - k][j]; // 如果是有效字符，則輸出
            else
                cout << " "; // 如果該位置超出當前行的長度，輸出空格
        }
        cout << endl; // 每輸出一列，換行
    }
    return 0;
}








