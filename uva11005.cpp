//cheapest base
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
//function f:將十進制數字 a 轉換為進制 b 表示的數字，並存儲在 arr 中
//使用 tmp[] 暫存轉換後的每一位（從低位到高位）。
//通過 a % b 取餘數，得到在進制 b 下的最低位，然後除以 b 繼續處理，直到 a < b
//最後將 tmp 中的數字逆序存入 arr，因為 tmp 存儲的是從低位到高位，而 arr 需要從高位到低位。
int f(int a, int b, int arr[], int &cnt) {
	int tmp[40] = {}, i;
	cnt = 0;
	while(a >= b) {
		tmp[cnt++] = a % b;
		a /= b;
	}
	if(a)
		tmp[cnt++] = a;
	for(i = 0; i < cnt; ++i)
		arr[cnt-i-1] = tmp[i];

	return 0;
}
//function calcost: 計算將數字 num 轉換為進制 b 表示時的總成本。
//遍歷 arr[] 中的每一位數字，將每一位的轉換成本累加，得到總成本 sum。
int CalCost(int arr[], int cnt, int cost[]) {
	int sum = 0;
	for(int i = 0; i < cnt; ++i) {
		sum += cost[arr[i]];
	}

	return sum;
}
//main function:理多個測試用例，對每個測試用例找出數字 num 的最便宜轉換進制。
//讀取輸入：讀取 t 和每個測試用例的 cost[]，表示在不同進制下，每個數字的成本。對每個測試用例，讀取 n 和需要判斷的 num。
//找最便宜的進制：
//對於每個 num，遍歷進制 b（從 2 到 36）。
//使用 f() 函數將 num 轉換為進制 b，並計算其轉換成本。
//使用 CalCost() 計算轉換後的總成本，儲存在 price[b] 中。
//更新 Min，以找到最小成本的進制。

int main()
{
	int a, b, n, num, Min;
	int cost[40];
	int t, ti = 0;
	cin >> t;
	while(ti++ < t) {
		printf("Case %d:\n", ti);

		for(int i = 0; i < 36; ++i)
			cin >> cost[i];
		cin >> n;
		while(n--) {
			int arr[40] = {}, cnt = 0;
			int price[40] = {};

			cin >> num;
			Min = 999999999;
			for(b = 2; b <= 36; ++b) {
				f(num, b, arr, cnt);
				price[b] = CalCost(arr, cnt, cost);

				if(price[b] < Min)
					Min = price[b];
			}

			printf("Cheapest base(s) for number %d:", num);
			for(b = 2; b <= 36; ++b) {
				if(price[b] == Min)
					printf(" %d", b);
			}
			printf("\n");
		}
		if(ti != t)
			printf("\n");
	}

	return 0;
}
