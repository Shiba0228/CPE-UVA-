//GCD
//其中 GCD(i,j) 為整數 i 和整數 j 的最大公因數。
//G=0;
//for(i=1;i<N;i++)
//for(j=i+1;j<=N;j++)
//{

   // G+=GCD(i,j);
//}
#include <iostream>
#include <algorithm>
using namespace std;
// 計算兩個整數 x 和 y 的最大公因數 (GCD) 
int GCD(int x, int y) {
    while ((x %= y) && (y %= x));
    return x + y;
}
  
int main() {
    int N, G;
    while (cin >> N && N) { //讀取 N，當 N 為 0 時結束
        G = 0; //初始化 G 為 0，用於存儲 GCD 的總和
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                G += GCD(i, j);// 累加所有 i 和 j 的 GCD 值
            }
        }
        cout << G << "\n"; //輸出 G 的結果
    }
}
