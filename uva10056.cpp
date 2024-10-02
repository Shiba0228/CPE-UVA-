//What is the Probability?
#include <bits/stdc++.h>

using namespace std;

int main() {
    int kase;
    cin >> kase;
    while (kase--) {
        double n, p, i;
        cin >> n >> p >> i;
        double q = 1 - p;
        if(p==0)
        	cout<<"0.0000"<<endl;
        else
        	printf("%.4f\n", (pow(q, (i - 1)) * p) / (1 - pow(q, n))); //小數第四位
    }
    return 0;
}
