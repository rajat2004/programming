#include<bits/stdc++.h>
using namespace std;

int min(int a, int b, int c) {
    return min(min(a,b),c);
}

int main() {
    int n,k,l,c,d,p,nl,np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    cout << min((k*l)/nl, c*d, p/np)/n << endl;
    return 0;
}