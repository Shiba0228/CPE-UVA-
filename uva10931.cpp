//parity
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int in1;
	while(cin>>in1)
	{
		int sum=0;//sum紀錄有幾個1 
		string cs1="";//cs1轉成2進位的數 
		
		if(in1==0)//輸入0就結束 
		{
			break;
		}
		
		while(in1>0)//10進位轉成2進位 
		{			//用短除法一直除2 
			if(in1%2==1)//餘1 
			{
				cs1="1"+cs1;//要從短除法最後的1寫回去 
				sum=sum+1;//計算有幾個1 
			}
			
			else//餘0 
			{
				cs1="0"+cs1;
			}
			
			in1=in1/2;
		}
		
		cout<<"The parity of "<<cs1<<" is "<<sum<<" (mod 2)."<<endl;//輸出 
	}
	return 0;
}