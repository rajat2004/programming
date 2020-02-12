#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    if(s1.length()!=s2.length()) {
        cout << "NO\n";
        return 0;
    }
    int diff1=0,diff2=0,count=0;
    for(int i=0; i<s1.length(); i++) {
        int diff = s1[i]-s2[i];
        if(diff!=0) {
            count++;
            if (count>=3) {
                cout << "NO\n";
                return 0;
            }
            if(diff1==0)
                diff1=diff;
            else
                diff2=diff;
        }
    }
    if(diff1!=(-1*diff2))
        cout << "NO\n";
    else 
        cout << "YES\n";
    return 0;
}