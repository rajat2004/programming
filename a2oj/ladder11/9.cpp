#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int count47 = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='4' || s[i]=='7')
            count47++;
    }
    int flag = 0;
    if (count47 == 0) {
        cout << "NO" << endl;
        return 0; 
    }
    while(count47>0) {
        int r = count47%10;
        if(!(r==4 || r==7)) {
            cout << "NO" << endl;
            flag = 1;
            break;
        }
        count47=count47/10;
    }
    if(flag==0)
        cout << "YES" << endl;
    return 0;
}