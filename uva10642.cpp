//can you solve it
//下面這張圖，每個圓都有一個坐標，根據笛卡爾坐標系，您可以按照以下所示的箭頭路徑從一個圓圈移動到另一個圓圈。
//total_number_of_step(s)_needed = number_of_intermediate_circles_you_pass + 1
//例如，要從 (0, 3) 到 (3, 0)，您必須經過兩個中間圓 (1, 2) 和 (2, 1)。 所以，
//在這種情況下，所需的總步數是 2 + 1 = 3。

//sol
//觀察移動順序 (x, y)：
//x+y = 0: (0, 0) ->
//x+y = 1: (0, 1) -> (1, 0) ->
//x+y = 2: (0, 2) -> (1, 1) -> (2, 0) ->
//x+y = 3: (0, 3) -> (1, 2) -> (2, 1) -> (3, 0) ->
//從 (0, 0) 移動到 (x, y) 需走
//令 n = x + y – 1,
//2 + 3 + 4 + … + (n+1) + (x+1)
//2 + 3 + … + (n+1) = (n^2 + 3n) / 2

#include <iostream>
using namespace std;
  
int main() {
    int T;
    long long x, y, n, step1, step2;
    cin >> T;
    for (int Case = 1; Case <= T; Case++){
        cout << "Case " << Case << ": ";
        cin >> x >> y;
        if (x == 0 && y == 0) step1 = 0;
        else {
            n = x + y - 1;
            step1 = (n * n + 3 * n) / 2 + (x + 1);
        }
        cin >> x >> y;
        n = x + y - 1;
        if (x == 0 && y == 0) step2 = 0;
        else {
            n = x + y - 1;
            step2 = (n * n + 3 * n) / 2 + (x + 1);
        }
        cout << step2 - step1 << "\n";
    }
    return 0;
}
