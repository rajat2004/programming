#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n==2)
        return true;
    
    if(n%2==0)
        return false;
    
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0)
            return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=n+1; i<m; i++) {
        if(is_prime(i)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if(is_prime(m))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}