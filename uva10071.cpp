//back to high school physic
//位移=2*v*t
#include<iostream>
using  namespace std;

int dis(int v, int t){
   return 2*v*t;
}
int main(){
   int v, t;
   while(cin>>v >>t)
      cout<<dis(v,t)<<endl;
   return 0;
}

//version2(瘋狂程設會有bug)
//#include<iostream>
//using  namespace std;
//int main(){
  // int v, t;  
  // while(cin>>v >>t){
   //   int  d;
   //  d=2*v*t;
   //  cout<<d <<endl;
   // }  
   //return 0;
   
//}
