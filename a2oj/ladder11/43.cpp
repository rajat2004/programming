#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() != s2.length()) {
        cout << "NO" << endl;
        return 0;
    } else {
        int n = s1.length();
        for(int i=0; i<n; i++) {
            if(s1[i] != s2[n-1-i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}
