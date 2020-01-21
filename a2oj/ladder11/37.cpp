#include<bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long int n,k;
    cin >> n >> k;
    if(k < ((n+1)/2 + 1)) 
        cout << 2*k-1 << endl;
    else 
        cout << 2*(k - (n+1)/2) << endl;
    // if(k <= (n/2))
    //     cout << 2*k - 1 << endl;
    // else 
    //     cout << 2*(k - (n+1)/2) << endl;
    return 0;
}