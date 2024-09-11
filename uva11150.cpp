// UVa 11150 - Cola
#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin>>n) {
        int total = n;  // ��l�i�ּƶq
        int bottles = n;  // ��l�Ų~��

        while (bottles >= 3) {
            int new_cola = bottles / 3;
            total += new_cola;
            bottles = bottles % 3 + new_cola;
        }

        // �p�G�̫�ѤU2�ӪŲ~�A�i�H�ɤ@�ӪŲ~�Ӵ��@�~�i��
        if (bottles == 2) {
            total += 1;
        }

        cout<<total<<endl;
    }
    return 0;
}
