//Vito's Family
//median
#include<iostream>
#include<algorithm>
using namespace std;
int main () {
 int ts;
 cin>>ts;
 
 for(int k=0; k<ts; k++){
 int ts2;
 cin>>ts2;
 
 int r[501]; //array
 int mid = ts2/2; //mid
 int sum = 0;//initialization
 for(int i=0; i<ts2; i++)cin>>r[i]; 
 sort(r,r+ts2); //sort function
 for(int i=0; i<ts2; i++){
 sum = sum + abs(r[mid]-r[i]); //絕對值
 }
 cout<<sum<<endl;
 }
 
 return 0;
}
