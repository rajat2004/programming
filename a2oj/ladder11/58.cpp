#include<bits/stdc++.h>
using namespace std;

int is_char(string s, int idx, char c) {
    for(int i=idx; i>=0; i--) {
        if(s[i]==c)
            return i;
    }
    return -1;
}

int main() {
    string s;
    cin >> s;
    int pos_o = is_char(s, s.length()-1, 'o');

    if (pos_o!=-1) {
        int pos_l2 = is_char(s, pos_o, 'l');

        if(pos_l2 != -1) {
            int pos_l1 = is_char(s, pos_l2-1, 'l');

            if (pos_l1 != -1) {
                int pos_e = is_char(s, pos_l1, 'e');

                if (pos_e != -1) {
                    int pos_h = is_char(s, pos_e, 'h');

                    if (pos_h != -1) {
                        cout << "YES" << endl;
                    } else 
                        cout << "NO" << endl;

                } else 
                    cout << "NO" << endl;

            } else 
                cout << "NO" << endl;

        } else 
            cout << "NO" << endl;
    } else 
        cout << "NO" << endl;
    return 0;
}