#include <iostream>
#include <algorithm>   //�|�Ψ� 
using namespace std;
int main()
{
    int testcase;    //how many testcase?
    cin>>testcase;
    int d[500]={0}; 
    for(int i=0;i<testcase;i++){
        int r;   
        cin>>r;
        int s[500];    //�C�ӿ˱������P���X�A�W��500�H
        int mid;
        for(int j=0;j<r;j++){
        cin>>s[j];    }
        sort(s,s+r);
        mid =s[(int)r/2];    //�������
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
