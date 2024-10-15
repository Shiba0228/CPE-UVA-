//Satellites
//Degrees (°), minutes (‘), seconds (“), 1° = 60′,1′ = 60″
//角度 degree (deg) vs. 弧度 radius (rad),一個完整的圓的弧度：2 * PI, rad = deg / 180 * PI, cos (90°) = 0 -> acos(0) = PI / 2 -> PI = 2 * acos(0)
//一個半徑為 R 的圓，圓周長為 2 * PI * R，當兩顆衛星之間的夾角「角度」為 a°（a 大於 180 時，a -> 360 – a）
//弧長 arc = 2 * PI * R * a / 360
//弦長 chord = 2* R * cos((90 – a / 2) / 180 * PI)
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI acos(0.0)*2.0
 
int main() {
    double r, s, a;
    string unit;
    double chord, arc;
    r = 6440.0; //地球半徑，設定為 6440.0（單位是公里）
    while (cin >> s >> a >> unit){
        if (unit == "min") a /= 60.0; //如果輸入的角度單位是「min」（分鐘），則需要將其轉換為度，因為 1 度等於 60 分鐘，因此將 a 除以 60 將其轉換成度數
        if (a > 180.0) a = 360.0 - a;//處理大於 180 度的角度
        //弦長是指直接連接兩個點之間的距離，這是一個直線距離。
        // r + s 是地球的半徑加上測量點或衛星的高度，這表示兩點所在的圓的半徑。
        //a/2.0 是夾角的一半，因為弦長可以看作是兩個角分成的等腰三角形。
       //cos((90.0 - a/2.0)/180.0 * PI) 計算出這個等腰三角形的底邊長，再乘以 2 得到完整的弦長。
        chord = (r+s) * cos((90.0 - a/2.0)/ 180.0 * PI) * 2.0;
       //弧長是指沿著圓周的曲線距離。
       //2 * PI * (r + s) 是圓的周長。
       //a / 360.0 是角度相對於整個圓的比例，這樣可以計算出相對應的弧長。
        arc = 2.0 * PI * (r+s) * a / 360.0;
        //小數點後六位
        cout << fixed << setprecision(6) << arc << " " << chord << "\n";
    }
    return 0;
}
