#include<bits/stdc++.h>
using namespace std;

int main(){
    char c;
    cin >> c;
    if(c>=97)
        cout << (char)(c-32);
    else
        cout << c;
    string s;
    cin >> s;
    cout << s;
    
    return 0;
}