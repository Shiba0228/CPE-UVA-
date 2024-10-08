//Common Permutation
//給予兩個小寫字串，找出重複之字母
// 先計算出兩個字串之各個字母出現次數（注意：可能包含空字串，使用getline()，而非 cin>>)
// 比較兩者次數，取最小者，存入 char letter[26]
// 依字母順序印出字母的個數
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    string a, b;
    while (getline(cin, a), getline(cin, b))
    {
        int aCounts[128], bCounts[128];
        for (int i = 'a'; i <= 'z'; ++i)
            aCounts[i] = bCounts[i] = 0;
        
        for (int i = 0; i < a.size(); ++i)
            ++aCounts[a[i]];
        
        for (int i = 0; i < b.size(); ++i)
            ++bCounts[b[i]];
        
        string longest = "";
        
        
        for (int i = 'a'; i <= 'z'; ++i)
            while (aCounts[i] > 0 && bCounts[i] > 0)
            {
                longest += (char) i;
                --aCounts[i];
                --bCounts[i];
            }
        
        cout << longest << '\n';
    }
}
