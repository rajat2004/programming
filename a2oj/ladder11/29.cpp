#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,x=0;
    cin >> n;
    string s;
    while(n--) {
        cin >> s;
        if(s[1]=='+')
            x+=1;
        else 
            x-=1;
    }
    cout << x << endl;
    return 0;
}