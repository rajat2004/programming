#include<bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    return (c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U' || c=='y' || c=='Y');
}

int main() {
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        if(!is_vowel(s[i])) {
            cout << "." << (s[i] <= 'Z' ? (char)(s[i]+32) : s[i]);
        }
    }
    return 0;
}
