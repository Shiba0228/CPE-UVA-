//What's Cryptanalysis?
//字元、計數
#include <iostream>
#include <cctype>
using namespace std;

int count[256], length;   //統計各字母出現的次數
int main() {
 char text;                //使用者輸入的字
 while(cin >> text)
 {
  length++;             //統計所有字母出現的次數
  count[toupper(text)]++;
 }
 while(--length)          
 {
  for(text = 'A'; text <= 'Z';text++)                //輸出A~Z的出現次數
  {
   if(count[text] == length)                     //由出現次數多的先印出，相同者前面的字母會優先，沒出現過不會印出來
   {
    cout << text << " " << count[text] << endl;
   }
  }
 }
 return 0;
}
