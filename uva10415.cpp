//Eb Alto Saxophone Player
//測資會給予一串音符，需計算每一指按按鈕的次數。
//（若前一個音符有使用那指，則在目前的音符不需再計算一次）

//解題過程：
//1. 宣告一個二維陣列，紀錄每一個音符需按的指法
//2. 用兩個 array 分別紀錄總按鈕次數及前一個指法，以進行比對
//3. 注意！測資之歌曲可能為空行，因此使用 getline() 讀入測資

#include <iostream>
#include <string>
#include <string.h>
using namespace std;
//音符
char notes[14] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B'};
//指法
int finger[14][10] = {
    {0,1,1,1,0,0,1,1,1,1}, // c
    {0,1,1,1,0,0,1,1,1,0}, // d
    {0,1,1,1,0,0,1,1,0,0}, // e
    {0,1,1,1,0,0,1,0,0,0}, // f
    {0,1,1,1,0,0,0,0,0,0}, // g
    {0,1,1,0,0,0,0,0,0,0}, // a
    {0,1,0,0,0,0,0,0,0,0}, // b
    {0,0,1,0,0,0,0,0,0,0}, // C
    {1,1,1,1,0,0,1,1,1,0}, // D
    {1,1,1,1,0,0,1,1,0,0}, // E
    {1,1,1,1,0,0,1,0,0,0}, // F
    {1,1,1,1,0,0,0,0,0,0}, // G
    {1,1,1,0,0,0,0,0,0,0}, // A
    {1,1,0,0,0,0,0,0,0,0}, // B 
};

int main(){
    int case_num;
    string song;

    cin >> case_num;
    getline(cin, song); //clear buffer
    for (int i = 0; i < case_num; i++){
        string song;
        int f_num[10] = {0};
        int last_f[10] = {0};
        int note_index;

        getline(cin, song);
        for (int j = 0; j < song.length(); j++){
            // find the index of note to find the fingering
            note_index = distance(notes, strchr(notes, song[j]));
            
            if (j == 0){
                for (int k = 0; k < 10; k++){
                    f_num[k] = finger[note_index][k];
                    last_f[k] = finger[note_index][k];
                }
            } else {
                for (int k = 0; k < 10; k++){
                    // check if finger used in last note
                    if (finger[note_index][k] == 1 && finger[note_index][k] != last_f[k]){
                        f_num[k] ++;
                    }
                    last_f[k] = finger[note_index][k];
                }
            }
        }

        // output(cout)
        for (int k = 0; k < 10; k++){
            if (k != 0){
                cout << ' ';
            }
            cout << f_num[k];
        }
        cout << endl;
    }
    return 0;
}