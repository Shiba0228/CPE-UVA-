// B2-Sequence
// 判斷測資所給的數列是否為 B2-sequence，B2-sequence 的定義為數列中不會
// 有任意兩數總和是相同的，且數列為 1 ≤ b1 < b2 < ……。

// sol:
//n 表示序列中數字的個數。
//check 用於判斷序列是否為 B2-Sequence。初始設為 1，表示假設該序列是 B2-sequence。
//caseNum 是用來標記測試用例的編號，初始為 0，每次新測試用例時自增
//對於每個元素進行檢查：
//如果元素小於 1，check 設為 0，表示該序列不符合 B2-序列的條件（B2-序列中的數字必須是正整數）。
//如果序列不嚴格遞增（即前一個數大於或等於當前數），則 check 設為 0。
//檢查和是否唯一：
//使用 sum[20001] 數組來記錄每個可能的和。sum[x] 表示 x 是否出現過，初始值均為 0。
//如果初步條件檢查（正整數和遞增性）通過（即 check 為 1），則開始檢查所有數對的和是否唯一。
//遍歷所有 seq[j] 和 seq[k]（其中 j <= k），計算 tmp = seq[j] + seq[k]，然後檢查：
//如果 sum[tmp] 為 0，表示 tmp 這個和第一次出現，將 sum[tmp] 設為 1。
//如果 sum[tmp] 不為 0，表示這個和已經出現過，則將 check 設為 0 並中斷循環。

#include <iostream>
using namespace std;

int main(){
    int n, check, tmp;
    int caseNum = 0;

    while (cin >> n){
        caseNum++;
        check = 1; // initialize check to yes which means this sequence is a B2-seq

        int seq[n];
        for (int i = 0; i < n; i++){
            cin >> seq[i];
            if (seq[i] < 1){
                check = 0;
            }
            if (i != 0 && seq[i-1] >= seq[i]){
                check = 0;
            }
        }
        int sum[20001] = {0}; // use a table to record which num is appeared

        if (check == 1){
            for (int j = 0; j < n; j++){
                for (int k = j; k < n; k++){
                    tmp = seq[j] + seq[k];
                    if (sum[tmp] == 0){
                        sum[tmp] = 1;
                    } else {
                        check = 0;
                        break;
                    }
                }
            }
        }

        if (check == 0){
            cout << "Case #" << caseNum << ": It is not a B2-Sequence." << endl;
        } else {
            cout << "Case #" << caseNum << ": It is a B2-Sequence." << endl;
        }
        cout << endl;
    }
    return 0;
}
