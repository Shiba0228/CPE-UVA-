// UVa 11150 - Cola
#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin>>n) {
        int total = n;  // ﹍贾计秖
        int bottles = n;  // ﹍瞺计

        while (bottles >= 3) {
            int new_cola = bottles / 3;
            total += new_cola;
            bottles = bottles % 3 + new_cola;
        }

        // 狦程逞2瞺瞺ㄓ传瞺贾
        if (bottles == 2) {
            total += 1;
        }

        cout<<total<<endl;
    }
    return 0;
}
