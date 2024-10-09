//TEX Quotes
//轉換一般 " 為一對雙引號 “ ” ，用 ``及 ' ' 表示。
//題目不含巢狀雙引號，因此用 int 計算其出現次數，奇數為左雙引號，偶數為右雙引號

//sol
//讀取輸入：
//使用 getline(cin, tmp) 逐行讀取輸入，這樣可以處理帶有空格的整行文本
//處理每一行的字符：
//算當前行的長度 length，然後使用 for 循環逐個字符進行處理。
//對於每個字符，檢查它是否是雙引號 "
//如果是雙引號，則根據 count 的奇偶性來決定替換為左雙引號或右雙引號：
//奇數次數（count % 2 == 1）時，替換為 ````（兩個反引號）。
//偶數次數時，替換為 ''（兩個單引號）。
//然後輸出替換後的字符。
//如果不是雙引號，則直接輸出該字符。
//每行處理結束後，輸出一個換行符，以確保原輸入的格式（每行輸入一行輸出）
#include <iostream>
#include <string>
using namespace std;

int main(){
    string tmp;  // 用來存儲每行輸入的字符串
    int length;  // 存儲每行字符串的長度
    int count = 0; //用來計數已經遇到的雙引號數量
    //input使用getline
    while (getline(cin, tmp)){
        length = tmp.length(); //計算當前行的長度

        for (int i = 0; i < length; i++){
            if (tmp[i] == '\"'){
                count++;

                if (count % 2 == 1){ // left-double-quote
                    cout << "``";
                } else {
                    cout << "''"; // right-double-quote
                }
            } else {
                cout << tmp[i];
            }  
        }
        cout << endl;
    }
    return 0;
}
