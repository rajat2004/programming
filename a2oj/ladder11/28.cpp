#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,count=0,a,b,c;
    cin >> n;
    while(n--) {
        cin >> a >> b >> c;
        count += (a+b+c) > 1 ? 1 : 0;
    }
    cout << count << endl;
    return 0;
}