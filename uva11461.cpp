//Square Numbers
//給定兩個整數 a, b，找到 a 和 b 之間的完全平方數個數
//計算 a 及 b 之平方數，並相減算出其個數
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a,b,sq;
	while(cin>>a>>b)
	{
		if(a==0&&b==0)//輸入結束 
		{
			break;
		}
		int count=0;
		
		for(int i =a;i<=b;i++)
		{
			sq=sqrt(i);//因為是整數型態所以開根號後也是整數 
					   //所以再乘回來不一定會是原本的數 
			if(sq*sq==i)//將兩數相乘與原本的數進行比較 
			{
				count++;
			}
			
		}
		
		cout<<count<<endl;//輸出 
	}
	return 0;
}
