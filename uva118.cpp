//mutant flatworld exploders
//題目大意：
//測資會給予整體座標大小以及好幾個機器人的初始座標、方位，並要預測在一串指令後，機器人的所處位置。
//若過程中有機器人掉出邊界，會紀錄該位置（不管方位），避免有其他機器人也從同樣座標墜落。
//sol
//輸入與初始化：
//讀取地圖的大小 n 和 m，表示地圖的行數和列數。
//使用 arr[55][55] 記錄每個位置是否發生過機器人「丟失」的情況。arr 的初始值為 0，如果某位置有機器人丟失過，則將 arr[sx][sy] 設為 -1。
//讀取機器人初始位置與方向：
//sx 和 sy 分別表示機器人初始的橫坐標和縱坐標。
//c 是機器人的初始方向（N、E、S、W），使用 get_face 函數將其轉換為對應的數字（0 表示北，1 表示東，2 表示南，3 表示西）。
//op 是機器人接收到的操作指令的字符串，包括 L（左轉）、R（右轉）、F（前進）。
//處理操作指令：
//對於每個操作指令，根據字符進行相應操作：
//'L'（左轉）：將 face 減 1（方向數字減小），如果減到負數則循環到 3。
//'R'（右轉）：將 face 加 1（方向數字增加），如果超過 3 則循環到 0。
//'F'（前進）：根據當前方向決定機器人前進的方向。
//如果機器人移動會超出地圖邊界：
//檢查該位置是否有其他機器人「丟失」過。如果沒有，則標記此位置為丟失點，並將 lost 設為 true，跳出循環。
//如果該位置之前有其他機器人「丟失」，則不再進一步丟失，機器人不會真正移動。
//如果沒有超過邊界，則進行位置更新。
//輸出機器人最終狀態：
//輸出機器人最終位置 sx 和 sy，以及面對的方向 dir[face]（將數字轉換回字符 N、E、S、W）。
//如果機器人丟失，則輸出 LOST，否則輸出換行
#include<iostream>
using namespace std;
int n,m,sx,sy,face,arr[55][55]; //定義地圖的大小和機器人的初始位置
char c,dir[4]={'N','E','S','W'};
string op;
//將方向字符轉換為對應的整數
int get_face(char ch){
	if(ch=='N') return 0;
	else if(ch=='E') return 1;
	else if(ch=='S') return 2;
	return 3;
}
int main(){
	cin>>n>>m;// 讀取地圖大小（n 和 m）
	while(cin>>sx>>sy>>c){
		// 以數字表示方位
		face=get_face(c);
		cin>>op;// 讀取機器人的操作指令串
		bool lost=false;// 設置丟失標誌為 false
		// 針對指令進行操作
		for(int i=0 ; i<op.size() ; i++){
			if(op[i]=='L'){ //turn left
				face--;
				if(face<0) face=3;// 循環處理方向
			}
			else if(op[i]=='R'){ //turn right
				face++;
				if(face>3) face=0; // 循環處理方向
			}
			else{// 'F' 前進指令
				if(face==0){ // 北向
					if(sy+1>m){// 檢查是否超過地圖邊界
						if(arr[sx][sy]==0){ // 如果此處沒有「丟失」過，則標記並丟失
							arr[sx][sy]=-1;
							lost=true;
							break;
						}
					}
					else
						sy++; //沒有超出邊界則前進
				}
				else if(face==1){ // 東向
					if(sx+1>n){
						if(arr[sx][sy]==0){
							arr[sx][sy]=-1;
							lost=true;
							break;
						}
					}
					else
						sx++;
				}
				else if(face==2){ // 南向
					if(sy-1<0){
						if(arr[sx][sy]==0){
							arr[sx][sy]=-1;
							lost=true;
							break;
						}
					}
					else
						sy--;
				}
				else if(face==3){ // 西向
					if(sx-1<0){
						if(arr[sx][sy]==0){
							arr[sx][sy]=-1;
							lost=true;
							break;
						}
					}
					else
						sx--;
				}
			}
		}
		cout<<sx<<" "<<sy<<" "<<dir[face];
		if(lost){
			cout<<" LOST\n";
		}
		else{
			cout<<'\n';
		}
	}
	return 0;
}
