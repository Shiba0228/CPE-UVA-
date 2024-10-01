//uva10019
//Funny Encryption Method
//輸入一個數M，先把M當成10進位(個十百千...)，轉成二進位後統計1的個數。再把同一個M看成十六進位，也轉成二進位後，再統計1的個數。
#include<iostream>

using namespace std;

int main(){
   int N;
   cin >> N;
   while(N--){
      int m;
	  cin >> m;
	  
      int b1 = 0, b2 = 0;
      for(int v = m; v; v /= 2) b1 += v % 2;
      for(; m; m /= 10)
         for(int v = m % 10; v; v /= 2) b2 += v % 2;
      cout << b1 << " " << b2 << endl;
   }
   return 0;
}
