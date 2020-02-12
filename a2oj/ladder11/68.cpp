#include<bits/stdc++.h>
using namespace std;

int main() {
    // string s1,s2;
    // cin >> s1;
    // cout << s1 << endl;
    // cin >> s2;
    char c;
    int arr[58] = {0};
    scanf("%c", &c);
    while(c!='\n') {
        if(c!=' ') {
            arr[c-'A']++;
        }
        scanf("%c",&c);
    }
    scanf("%c", &c);
    while(c!='\n') {
        if(c!=' ') {
            arr[c-'A']--;
            if (arr[c-'A'] < 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
        scanf("%c",&c);
    }
    cout << "YES" << endl;
    return 0;
}