//symmertic matrix
//現在給你一個正方形矩陣M。
//M矩陣的元素為Mij：{0 < i < n，0 < j < n}。
//在這個問題中，您必須找出給定的矩陣是否對稱(symmetric)。
//定義：對稱矩陣所有元素都是非負的並且相對於該矩陣的中心對稱。
//任何其他矩陣都被認為是非對稱的。
//矩陣內的元素範圍為-2^32 <= Mij <= 2^32  且 0 < n <= 100

//sol
//輸入和初始化：
//ios_base::sync_with_stdio(0); cin.tie(0); 這段代碼用來加快輸入輸出的速度，特別是在需要多次輸入輸出的情況下。
//讀取測試用例的數量 T。
//對於每個測試用例，讀取兩個字符（通常是用來表示格式，如 'N' 和 '='），然後讀取矩陣的維度 n。
//義一個 n x n 的矩陣 a，並且使用 long long 型別以支持較大範圍的整數。

//矩陣元素輸入與初步檢查：
//讀取矩陣元素並存入 a[i][j]。
//同時檢查是否有負數，如果存在負數，則 flag 設為 false，因為對稱矩陣中的元素不能為負數。
//輸出測試用例標題：
//輸出 Test #x:，其中 x 是測試用例的編號。
//負數檢查結束處理：
//如果矩陣中有負數，則直接輸出「Non-symmetric」，並使用 continue 進入下一個測試用例。
//對稱性檢查：
//如果矩陣沒有負數，繼續檢查對稱性。
//對於每個矩陣元素 (i, j)，檢查它是否等於其對稱位置 (n-1-i, n-1-j)。
//檢查範圍僅需到 n / 2，因為超過該範圍後已經檢查過對應的元素。
//如果發現不對稱的情況，將 flag 設為 false 並跳出內層循環。

#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    char ch;
    cin >> T; // 讀取測試用例的數量
    for (int Case = 1; Case <= T; Case++){
        cin >> ch >> ch >> n; // 讀取兩個字符（'N'和'='），然後讀取矩陣的維度 n
        long long a[n][n]; //定義一個 n x n 的矩陣，使用 long long 以支持大範圍的整數
        bool flag = true;  //用來判斷矩陣是否符合對稱條件
        for (int i = 0; i < n; i++){ //讀取矩陣元素
            for (int j = 0; j < n; j++){ //如果矩陣中有負數，直接標記為非對稱
                cin >> a[i][j];
                if (a[i][j] < 0) flag = false;
            }
        }
        cout << "Test #" << Case << ": ";
        if (!flag){
            cout << "Non-symmetric.\n";
            continue; //若已經確定有負數，直接跳到下一個測試用例
        }
         
        for (int i = 0; i <= n/2; i++){
            for (int j = 0; j < n-i; j++){
                if (a[i][j] != a[n-1-i][n-1-j]){
                    flag = false; //如果不對稱，將標誌設為 false
                    break;
                }
            }
        }
        if (flag) cout << "Symmetric.\n";
        else cout << "Non-symmetric.\n";
    }
    return 0;
}
