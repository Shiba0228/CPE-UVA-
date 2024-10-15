//simply emirp
//uva10235
//判斷測資是否為 prime 或 emirp(質數不為迴文，且反轉後仍為質數)。
#include<iostream>
using namespace std;

int com[1000000];
int main() {
	//使用了 篩法（Sieve of Eratosthenes） 來建立一個質數表，存放在 com 陣列中：
        //com[i] 表示數字 i 是否為合數（不是質數）。如果 com[i] == 1，則 i 是合數；如果 com[i] == 0，則 i 是質數。
       //程式從 2 開始，對每個數 i，如果它是質數（com[i] == 0），那麼標記所有 i 的倍數為合數（com[j] = 1），這樣就可以篩選出所有的質數。
	for(int i = 2; i < 1000; i++) {
		if(com[i])
			continue;
		for(int j = i + i; j < 1000000; j+=i)
			com[j] = 1;
	}
	int n, rn;
	while(cin >> n) {
		//sn 儲存原始的輸入數字 n，並且使用 rn 來儲存反轉後的數字。
               //通過一個 for 迴圈，程式逐位計算出 n 的反轉數字 rn：
               //n % 10 取得 n 的最右邊一位，並將它加到 rn。
               //n /= 10 去掉 n 的最右邊一位，直到 n 變為 0。
		int sn = n; 
		for(rn = 0; n; n /= 10) rn = rn * 10 + (n % 10);
		if(com[sn]) cout << sn << " is not prime.";
		else if(com[rn]) cout << sn << " is prime.";
		else if(sn == rn) cout << sn << " is prime.";
		else cout << sn << " is emirp.";
		cout << endl;
	}
	return 0;
}
