#include<bits/stdc++.h>
using namespace std;

bool is_magic(string s, int index) {
    if (index >= s.length()) return true;

    if(s[index] != '1')
        return false;

    if(index + 1 == s.length()) return true;
    if(s[index+1]=='4') {
        if(index+2 == s.length()) return true;

        if (s[index+2]=='4') {
            return is_magic(s, index+3);
        }
        else {
            return is_magic(s, index+2);
        }
    } else 
        return is_magic(s, index+1);
}

int main() {
    string s;
    cin >> s;
    if(is_magic(s, 0))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
    return 0;
}
