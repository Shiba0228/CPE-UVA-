//tell me the frequencies
//getline input
//對每一列輸入，輸出各字元的 ASCII & 次數
//需要注意的點有：
//重複輸入，止於 EOF
//每一行輸入對應一輸出，長度 ≦ 1000
//輸入的每個字元：32 ≦ ASCII ≦ 127
//每行輸出包含 ASCII & 次數
//按照次數由小到大
//同樣次數按照 ASCII 由大到小
//每筆輸出間含一空白行
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string str;
    int count = 0;
    while (getline(cin, str)){
        if (count > 0){
            cout << endl;
        }
        int freq[95]; // ascii 126~32
        for (int i = 0; i < 95; i++){
            freq[i] = 10000;
        }

        // calculate the frequency of each char
        int tmp = 0;
        for (int i = 0; i < str.length(); i++){
            tmp = 126 - (int)str[i];
            if (freq[tmp] == 10000){
                freq[tmp] = 0;
            }
            freq[tmp]++;
        }

        // find the least frequency char and print it
        int index;
        index = distance(freq, min_element(freq, freq + 95));
        tmp = freq[index];
        while (tmp != 10000){
            for (int i = index; i < 95; i++){
                if (freq[i] == tmp){
                    cout << 126 - i << " " << freq[i] << endl;
                    freq[i] = 10000;
                }
            }
            index = distance(freq, min_element(freq, freq + 95)); //126-32+1
            tmp = freq[index];
        }
        count++;
    }
    return 0;
}
