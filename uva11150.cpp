// UVa 11150 - Cola
#include <iostream>
using namespace std; 

int main() {
    int n;
    cin>>n; 
        int total = n;  
        int bottles = n;  

        while (bottles >= 3) {
            int new_cola = bottles / 3;
            total += new_cola;
            bottles = bottles % 3 + new_cola;
        }

        
        if (bottles == 2) {
            total += 1;
        }

        cout<<total<<endl;

    return 0;
	}
