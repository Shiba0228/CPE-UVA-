#include <iostream>
#include <algorithm>   //會用到 
using namespace std;
int main()
{
    int testcase;    //how many testcase?
    cin>>testcase;
    int d[500]={0}; 
    for(int i=0;i<testcase;i++){
        int r;   
        cin>>r;
        int s[500];    //每個親戚的門牌號碼，上限500人
        int mid;
        for(int j=0;j<r;j++){
        cin>>s[j];    }
        sort(s,s+r);
        mid =s[(int)r/2];    //取中位數
        for(int j=0;j<r;j++)
        {
            d[i]+=abs(s[j]-mid);
        }
    }
for (int i=0;i<testcase;i++){
    cout<<d[i]<<endl;
}

return 0;

} 
