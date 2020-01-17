#include<bits/stdc++.h>
using namespace std;

int main () {
    int names[26]={0}, pile[26]={0};
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for(int i=0; i<s1.length(); i++)
        names[s1[i]-'A']++;

    for(int i=0; i<s2.length(); i++)
        names[s2[i]-'A']++;

    for(int i=0; i<s3.length(); i++)
        pile[s3[i]-'A']++;
    
    for(int i=0; i<26; i++) {
        if(names[i] != pile[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}