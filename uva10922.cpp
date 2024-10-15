//2 the 9s
//我們知道要怎麼確定一個整數是不是 9 的倍數－如果它每位數的總和是9的倍數，那它就是9的倍數。這種檢驗的方法其實是一種遞迴的方法，而且我們把這種方法遞迴的深度稱作 N 的 9-degree 。
//你的工作就是，給你一個正整數N，判斷他是不是9的倍數，而且如果他是9的倍數你還需要判斷它的 9-degree。
#include <iostream>
using namespace std;
 
int func(string s, int count){
    int temp = 0, total = 0;
    for (int i = 0; i < s.length(); i++){
        temp = s[i] - '0';
        total += temp;
    }
    count++;
    if (total == 9){
        return count;
    }else if(total < 9){
        return 0;
    }else{
        return func(to_string(total), count);
    }
}
int main(){
    int ans;
    string s;
    while (cin >> s){
        if (s == "0") break;
        ans = func(s, 0);
        if (ans == 0){
            cout << s << " is not a multiple of 9.\n";
        }else{
            cout << s << " is a multiple of 9 and has 9-degree " << ans << ".\n";
        }
    }
 return 0;
}
