#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<char> m;
    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++)
        m.insert(s[i]);
    if(m.size()%2==0)
        cout << "CHAT WITH HER!" << endl;
    else 
        cout << "IGNORE HIM!" << endl;
    return 0;
}