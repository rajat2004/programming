#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count_cons=1;
    char last;
    for(int i=1; i<s.length(); i++) {
        if (s[i]==s[i-1]) {
            count_cons++;
            if(count_cons>=7) {
                cout << "YES" << endl;
                return 0;
            }
        } else 
            count_cons=1;
    }
    cout << "NO" << endl;
    return 0;
}
