#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.length();) {
        if(s[i]=='.') {
            cout << "0";
            i+=1;
        }
        else {
            if(s[i+1]=='-')
                cout << "2";
            else
                cout << "1";
            
            i+=2;
        }
    }
    return 0;
}