#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count_cons = 0, last_col;
    for(int i=1; i<n; i++) {
        if(s[i] == s[i-1])
            count_cons+=1;
    }
    cout << count_cons << endl;
    return 0;
}