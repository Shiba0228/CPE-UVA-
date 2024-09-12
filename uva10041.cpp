//Vito's Family
#include<iostream>
#include<algorithm>
using namespace std;
int main () {
 int ts;
 cin>>ts;
 
 for(int k=0; k<ts; k++){
 int ts2;
 cin>>ts2;
 
 int r[501];
 int mid = ts2/2;
 int sum = 0;
 for(int i=0; i<ts2; i++)cin>>r[i];
 sort(r,r+ts2);
 for(int i=0; i<ts2; i++){
 sum = sum + abs(r[mid]-r[i]);
 }
 cout<<sum<<endl;
 }
 
 return 0;
}
