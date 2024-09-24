//list of conquests
#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string,int> m;
    while(n--){
        string country,name;
        cin>>country;
        getline(cin,name);
        if(m.find(country)==m.end()){
            m.insert({country, 1});
        }
        else{
            m[country]+=1;
        }
    }
    for(auto &str:m){
        cout<<str.first<<" "<<str.second<<endl;
    }
    return 0;
}