#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s1="", s2="", s;
    int count1=0, count2=0;
    cin >> s;
    s1 = s;
    count1+=1;
    n--;

    while(n--) {
        cin >> s;
        if (s!=s1) {
            count2++;
            if(s2=="") s2 = s;
        } else {
            count1++;
        }
    }

    if (count1 > count2)
        cout << s1 << endl;
    else 
        cout << s2 << endl;
    return 0;
}
