//uva10908
//largest square
#include <iostream>
using namespace std;

//largest square
//功能：這個函數用來找到在 grid（字符矩陣）中以 (r, c) 為中心的最大正方形邊長。
//char grid[][101]：包含字符的網格
//length：這是以 (r, c) 為中心的正方形的半徑（距離），每次迭代會檢查以 length 為半徑的正方形。
//ulx 和 uly 分別是正方形的左上角坐標。lrx 和 lry 分別是正方形的右下角坐標。
//如果正方形超出網格範圍（即左上角或右下角超出邊界），則返回當前正方形的大小，即 length * 2 - 1（因為邊長是 2 * length - 1，如 length 為 1 時，邊長為 1；length 為 2 時，邊長為 3）。
//檢查正方形邊緣的字符一致性
//上、下邊檢查：檢查上邊和下邊的字符是否與中心 (r, c) 的字符一致。如果不一致，返回當前的邊長。
//左、右邊檢查：檢查左邊和右邊的字符是否與中心 (r, c) 的字符一致。如果不一致，返回當前的邊長。
//擴大正方形：
//如果邊長擴展成功且字符一致，增加 length，繼續檢查更大的正方形。
//返回結果：當無法擴展時，返回當前的正方形邊長，即 length * 2 - 1。

int largestSquare(char grid[][101], int m, int n, int r, int c){
    int length = 1;

    while(1){

        // upper left corner, lower right corner 
        int ulx, uly, lrx, lry;

        ulx = r - length;
        uly = c - length;
        lrx = r + length;
        lry = c + length;

        // out of bound
        if( ulx < 0 || lrx >= m || uly < 0 || lry >= n )
            return length * 2 - 1;

        // top and down
        for(int i = ulx; i <= (r +length); i += length * 2){
            for(int j = uly; j <= lry; j++){
                if (grid[i][j] != grid[r][c])
                    return length * 2 - 1;
            }
        }

        // left and right
        for(int j = uly; j <= (c + length); j += length * 2){
            for(int i = ulx; i <= lrx; i++){
                if (grid[i][j] != grid[r][c])
                    return length * 2 - 1;
            }
        }
        length += 1;
    }
    
    return length * 2 - 1;
}


int main() {
    int t, m, n, q;
    cin >> t;
    while (t--){
        char grid[101][101] = {0};
        cin >> m >> n >> q;
        for (int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];

        int r, c;
        cout << m << " " << n << " " << q << "\n";
        while (q--){
            cin >> r >> c;
            cout << largestSquare(grid, m, n, r, c) << "\n";
        }
    }
}
