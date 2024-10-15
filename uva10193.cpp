//all you need is love
//判斷是否能夠找到一個合法的L，使得S1和S2都可以用Love做成。亦即
//S1 是 L 的倍數
//S2 是 L 的倍數
//L 是 S1 和 S2 的公因數
//利用輾轉相除法計算S1 和 S2 的最大公因數，如果大於 1 (只有一個位元的字串不合法)，表示有解。

#include <iostream>
using namespace std;
 
int mygcd(int x, int y){
    while ((x %= y) && (y %= x));
    return x + y;
}
 
int main() {
    int N;
    string S1, S2;
    cin >> N;
    for (int Case = 1; Case <= N; Case++){
        cin >> S1 >> S2;
        int n1 = 0, n2 = 0;
        for (int i = 0; i < S1.size(); i++){
            n1 *= 2;
            n1 += S1[i] - '0';
        }
        for (int i = 0; i < S2.size(); i++){
            n2 *= 2;
            n2 += S2[i] - '0';
        }
        cout << "Pair #" << Case;
        if (mygcd(n1, n2) > 1) cout << ": All you need is love!\n";
        else cout << ": Love is not all you need!\n";
    }
    return 0;
}
