//Summing Digits 
#include <bits/stdc++.h>

using namespace std;

int f(int n){
    if(n<10) return n;
    return f(f(n/10)+n%10);
}

int main(){
    int n;
    while(cin>>n,n)
        cout<<f(n)<<endl;
    return 0;
}