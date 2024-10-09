// UVa 11150 - Cola
//sol:
//可樂兌換邏輯：
//當空瓶數量大於等於 3，就可以用 3 個空瓶換 1 瓶新可樂：
//計算 new_cola，即 bottles / 3 表示可以換到的可樂瓶數。
//將新得到的可樂數加到 total 中。
//更新 bottles：剩下的空瓶數量是 bottles % 3（表示剩下的未用來兌換的空瓶）加上 new_cola（新喝完後產生的空瓶數）
//特殊情況處理：
//如果最終剩下 2 個空瓶，可以假設借 1 個空瓶來換 1 瓶可樂（題目允許這樣做），這樣就可以多喝到 1 瓶可樂，且借來的空瓶又可以歸還。
//因此，在 bottles為2 的情況下，再加上 1 瓶可樂

#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin>>n) {
        int total = n;  // 初始可樂數量
        int bottles = n;  // 初始空瓶數

        while (bottles >= 3) {
            int new_cola = bottles / 3;
            total += new_cola;
            bottles = bottles % 3 + new_cola;
        }

        // 如果最後剩下2個空瓶，可以借一個空瓶來換一瓶可樂
        if (bottles == 2) {
            total += 1;
        }

        cout<<total<<endl;
    }
    return 0;
}
