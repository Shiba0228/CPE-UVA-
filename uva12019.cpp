//Doom's Day Algorithm
//透過題目給予的日期及其星期，求出其他輸入日期為星期幾。
//將題目給的資訊及星期存入 int[] 及 string[] 中
//依輸入值與題目資訊之月份比對，求出星期幾
//weekDay = (day - mondays[month] + 35) % 7：
//day - mondays[month] 計算輸入日期與該月份中已知的「星期一」日期之間的天數差。
//+ 35 是為了避免差值為負數，因為日期差可能會是負的。加上35（或其他7的倍數）不會改變餘數的結果，這樣可以保證 weekDay 為非負數。
//% 7 是為了取模，將結果約束在 0 到 6 的範圍內，對應於 week 字符串數組中的索引。
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    int month, day, weekDay; // month: 月份, day: 日期, weekDay: 計算出的星期編號
    string week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    // 2011 1/10, 2/21, 4/4, 5/9, 6/6, 7/11, 
    // 8/8, 9/5, 10/10 , 11/7 and 12/12 are Mondays.
    // 3/1 is Tuesday
    int mondays[12] = {10, 21, 0, 4, 9, 6, 11, 8, 5, 10, 7, 12};
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> month >> day; //讀取要查詢的月份和日期

        month--; // to fit the index of array

        weekDay = (day - mondays[month] + 35) % 7;

        cout << week[weekDay] << endl; 
    }
    return 0;
}
