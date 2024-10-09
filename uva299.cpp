//uva299 Train Swapping
//將每筆測資之數列由小到大排序，並計算交換次數（相當於 Bubble Sort，一次比較兩兩相鄰元素，若前者較大則交換，一輪結束後，最大元素會落在陣列尾端）
//sol:
//冒泡排序並計算交換次數：
//使用兩層 for 循環進行冒泡排序。
//外層循環控制排序的趟數。
//內層循環從 L-1 逐步到 j+1，每次比較相鄰的兩個元素 train[k-1] 和 train[k]。
//如果前面的元素比後面的大，則調用 swap 函數進行交換，並將 swap_num 加 1。

#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int testcase;// 測試用例的數量
  int L, swap_num;// L: 每組列車的長度（車廂數量），swap_num: 交換次數
  int train[55]; // 用於存儲列車車廂的數組，最多 50 節車廂
  while( scanf( "%d", &testcase ) != EOF ){// 從標準輸入讀取測試用例數量，直到文件結束
    for( int i = 0 ; i < testcase ; i++ ){
      scanf( "%d", &L );// 讀取每組列車的車廂數量
      for( int j = 0 ; j < L ; j++ )
        scanf( "%d", &train[j] ); //讀取每個車廂的編號

      swap_num = 0; // 初始化交換次數為 0
      //使用冒泡排序對列車進行排序，並計算交換次數
      for( int j = 0 ; j < L ; j++ )
        for( int k = L-1 ; k > j ; k-- )
          if( train[k-1] > train[k] ){
             // 如果前面的車廂比後面的車廂編號大，則交換它們
            swap( train[k-1], train[k] ); // 每次交換後，交換次數加 1
            swap_num++;
          }
      printf( "Optimal train swapping takes %d swaps.\n", swap_num );
    }
  }
  return 0;
}
