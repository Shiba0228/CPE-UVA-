//four points
//平行四邊形
//給定平行四邊形的兩個相鄰邊的端點的 (x, y)座標。找到第四個點的 (x, y)座標
#include <iostream>
#include <iomanip>  //輸出格式
using namespace std;

// four points function
//重複點條件判斷：程式會檢查四個點中是否有兩個點的座標是相同的。這些點被認為是平行四邊形的重複點。
//如果 (x1, y1) 與 (x3, y3) 相同，那麼 (x2, y2) 和 (x4, y4) 是非重複點，則可以利用公式 (x2 + x4) - x1 和 (y2 + y4) - y1 來求出第四個點。
//程式依次檢查 (x1, y1) 和 (x4, y4) 是否相同，或者 (x2, y2) 和 (x3, y3) 是否相同，對每種情況都計算剩餘的第四個點。
//計算公式：
//(x2 + x4) - x1 這個公式的意思是：將兩個非重複點的 x 坐標相加，減去重複點的 x 坐標，得到第四個點的 x 坐標。
//(y2 + y4) - y1 同樣計算出第四個點的 y 坐標
void solve(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    if (x1 == x3 && y1 == y3) {
        cout << fixed << setprecision(3) << (x2 + x4) - x1 << " " << (y2 + y4) - y1 << endl;
    } else if (x1 == x4 && y1 == y4) {
        cout << fixed << setprecision(3) << (x2 + x3) - x1 << " " << (y2 + y3) - y1 << endl;
    } else if (x2 == x3 && y2 == y3) {
        cout << fixed << setprecision(3) << (x1 + x4) - x2 << " " << (y1 + y4) - y2 << endl;
    } else {
        cout << fixed << setprecision(3) << (x1 + x3) - x2 << " " << (y1 + y3) - y2 << endl;
    }
}
//main function
int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        solve(x1, y1, x2, y2, x3, y3, x4, y4);
    }
    return 0;
}
