#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,a;
    cin >> n;
    float sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a;
        sum += a/100.0;
    }
    cout << fixed << setprecision(10) << (float)sum/n * 100 << endl;
    return 0;
}