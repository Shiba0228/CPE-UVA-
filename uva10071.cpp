//back to high school physic
#include<iostream>
using  namespace std;

int distance(int v, int t){
   return 2*v*t;
}
int main(){
   int v, t;
   while(cin>>v >>t)
      cout<<distance(v,t)<<endl;
   return 0;
}

//version2(瘋狂程社會有bug)
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
