#include<bits/stdc++.h>
using namespace std;

int main() {
    int k, count[26];
    cin >> k;
    string s;
    cin >> s;
    for(int i=0; i<26; i++)
        count[i]=0;

    for(int i=0; i<s.length(); i++) {
        count[s[i]-'a']++;
    }
    for(int i=0; i<26; i++) {
        if (count[i]%k != 0) {
            cout << "-1" << endl;
            return 0;
        }
    }
    string output = "";
    for(int i=0; i<26; i++) {
        for(int j=0; j<count[i]/k; j++) {
            output += (char)('a'+i);
        }
    }
    for(int i=0; i<k; i++)
        cout << output;
    cout << endl;
    return 0;
}
