//What is the Probability?
//此遊戲可以有N個玩家。
//第一個玩家將擲骰子，然後第二個玩家，最後是第N個玩家，再來是第一個玩家，依此類推。
//當玩家獲得期望的結果時，宣佈為獲勝者，比賽停止。
//您必須確定其中一名 (第i名) 的獲勝機率。
//cmath
#include <bits/stdc++.h>

using namespace std;

int main() {
    int kase; //case
    cin >> kase;
    while (kase--) { //input
        double n, p, i; //p為機率，n為第n個玩家
        cin >> n >> p >> i;
        double q = 1 - p; //q為1-p
        if(p==0)
        	cout<<"0.0000"<<endl;
        else
        	printf("%.4f\n", (pow(q, (i - 1)) * p) / (1 - pow(q, n))); //小數第四位
    }
    return 0;
}
