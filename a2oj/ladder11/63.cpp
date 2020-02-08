#include<bits/stdc++.h>
using namespace std;

int main(){
    int count[26]={0};
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        count[s[i]-'a']++;
    }
    int count_odd = 0;
    for(int i=0; i<26; i++) {
        if(count[i]%2!=0)
            count_odd++;
    }
    if (count_odd == 0) {
        cout << "First" << endl;
        return 0;
    }
    if((count_odd-1)%2==0)
        cout << "First" << endl;
    else 
        cout << "Second" << endl;

    return 0;
}