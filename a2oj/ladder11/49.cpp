#include<bits/stdc++.h>
using namespace std;

bool is_wub(string s, int i) {
    if (i > s.length()-3) return false;
    return (s[i]=='W' && s[i+1]=='U' && s[i+2]=='B');
}

void orig(string s, int idx) {
    int flag = 0;
    // if(idx >= s.length()-3) return;
    if(is_wub(s,idx)) {
        orig(s, idx+3);
    } else {
        if (idx >= s.length()-1) {
            cout << s[idx];
            return;
        }
        int i = idx+1;
        cout << s[idx];
        while(!is_wub(s, i)) {
            cout << s[i];
            i++;
            if (i >= s.length()) return;
        }
        cout << " ";
        orig(s, i);
    }
}

int main() {
    string s;
    cin >> s;
    // orig(s, 0);
    size_t index = 0;
    while (true) {
        index = s.find("WUB", index);
        if(index == string::npos) break;

        s.replace(index, 3, " ");
        
        index+=1;
    }

    // // Strip multiple spaces
    // index = 0;
    // while (true) {
    //     index = s.find("  ", index);
    //     if(index == string::npos) break;

    //     s.replace(index, 2, " ");
        
    //     // index+=1;
    // }

    s = regex_replace(s, regex("^ +| +$|( ) +"), "$1");
    cout << s << endl;
    return 0;
}
