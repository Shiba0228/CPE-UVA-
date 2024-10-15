//uva10019
//Funny Encryption Method
//演算法步驟如下：

//1. 讀入一個整數N，N為欲加密的數字：N = 265
//2. 將N當作十進位的數值：X1 = 265(decimal)
//3. 把X1由十進制轉為二進制：X1 = 100001001(binary)
//4. 計算二進制的X1有幾個1：b1 = 3
//5. 把N當作十六進位數值：X2 = 265(hexadecimal)
//6. 把X2由十六進制轉為二進制：X2 = 1001100101(binary)
//7. 計算二進制的X2有幾個1：b2 = 5
//8. 最後的編碼為N xor (b1*b2)：265 xor (3*5) = 262
//這位學生並未通過這次的計算機組識考試，所以他請求校方在ACM的試題上出一題計算共有幾個位元1的題目，好讓他能順利發表他的數值加密演算法。
//你必須寫一個程式能讀入一個整數，然後輸出該整數的b1, b2值。
//輸入一個數M，先把M當成10進位(個十百千...)，轉成二進位後統計1的個數。再把同一個M看成十六進位，也轉成二進位後，再統計1的個數。

#include<iostream>

using namespace std;

int main(){
   int N;
   cin >> N; // 讀取測試數量 N
   while(N--){
      int m;
	  cin >> m;
	  
      int b1 = 0, b2 = 0;// 初始化兩個計數器，b1 和 b2 用於計算兩種情況下的 "1" 的數量
     // 第一種情況：直接將 m 轉換為二進制，並計算其中 "1" 的個數  
      for(int v = m; v; v /= 2) b1 += v % 2; // 不斷將 v 除以 2，判斷它的二進制表示
      for(; m; m /= 10)// 如果 v 是奇數，則增加一個 "1"
     // 第二種情況：將 m 視為十進制數字串，對每個數字轉換為二進制，並計算其中的 "1" 的個數      
         for(int v = m % 10; v; v /=2)b2 += v % 2; // 每次取 m 的最後一位（m % 10），然後將 m 除以 10 ， 將每個十進制位的數字轉換為二進制，並計算 "1" 的個數
      cout << b1 << " " << b2 << endl;
   }
   return 0;
}
