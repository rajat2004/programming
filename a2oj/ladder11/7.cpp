#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count_lower = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]>=97)
            count_lower++;
    }
    if(count_lower>=(s.length() - count_lower)) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    else 
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;
    return 0;
}