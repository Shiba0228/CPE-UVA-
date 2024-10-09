//uva10908
//largest square
#include <iostream>
using namespace std;

//largest square
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
