//the 3n+1 problem
//1.         輸入 n
//2.         印出 n
//3.         如果 n = 1 結束
//4.         如果 n 是奇數 那麼 n=3*n+1
//5.         否則 n=n/2
//6.         重複這個過程，直到 n 變為 1

#include<iostream>
using namespace std;
int main(){
   int a,b;
   // 持續讀取輸入
   while(cin>>a>>b){
      cout<<a<<" "<<b<<" "; // 輸出原始輸入的 a 和 b
      if(a>b){int c=a;a=b;b=c;}//確保 a <= b，如果 a > b，則交換 a 和 b
      int maxLen=0;
      for(int k=a;k<=b;k++){
         int n=k,len=1; 
         while(true){
            if(n==1)break; //finish
            if(n%2)n=n*3+1; //n=3n+1(odd)
            else n/=2;     //n=n/2(even)
            len++;
         }
         maxLen=max(len,maxLen);
      }
      cout<<maxLen<<endl;
   }
   return 0;
}
