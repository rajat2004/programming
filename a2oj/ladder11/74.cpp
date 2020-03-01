#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int c[1001],arr[n];
    if(n==1) {
        cout << "YES\n";
        return 0;
    }

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        c[arr[i]]++;
        if(c[arr[i]]>(n+1)/2) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
