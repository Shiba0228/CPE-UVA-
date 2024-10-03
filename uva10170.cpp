//The Hotel with Infinite Rooms 
//HaluaRuti市有一家奇怪的酒店，房間無限。
//來這家酒店的團體，請遵循以下規則：
//a）同時，只有能有一個旅行團可以租用酒店。
//b）每個旅行團在入住日的早晨到達，並在退房日的晚上離開酒店。
//c）後入住的旅行團需要在前一團退房後的隔天早晨，才能入住
//d）除了第一團，其他旅行團人數都比前一團多一人
//e）有n名成員的旅行團則會在酒店停留n天。
//例如：
//如果一組四個成員的旅行團在8月1日早晨到達，則它將在8月4日晚上離開酒店
//下一組五個成員將在8月5日早晨入住並且停留五天，依此類推。
//現在給定第一組旅行團人數，您必須回答在指定日期入住的旅行團人數。
#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long S,D;
    while(cin>>S>>D)
    {
        while(D!=0)
        {
            D -= S;
            if(D <= 0)
            {
                cout<<S<<endl;
                break;
            }
            else
                S++;
        }
    }
    return 0;
}


