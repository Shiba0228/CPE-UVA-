//mutant flatworld exploders
#include<iostream>
using namespace std;
int n,m,sx,sy,face,arr[55][55];
char c,dir[4]={'N','E','S','W'};
string op;
int get_face(char ch){
	if(ch=='N') return 0;
	else if(ch=='E') return 1;
	else if(ch=='S') return 2;
	return 3;
}
int main(){
	cin>>n>>m;
	while(cin>>sx>>sy>>c){
		// 以數字表示方位
		face=get_face(c);
		cin>>op;
		bool lost=false;
		// 針對指令進行操作
		for(int i=0 ; i<op.size() ; i++){
			if(op[i]=='L'){
				face--;
				if(face<0) face=3;
			}
			else if(op[i]=='R'){
				face++;
				if(face>3) face=0;
			}
			else{
				if(face==0){
					if(sy+1>m){
						if(arr[sx][sy]==0){
							arr[sx][sy]=-1;
							lost=true;
							break;
						}
					}
					else
						sy++;
				}
				else if(face==1){
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
				else if(face==2){
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
				else if(face==3){
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