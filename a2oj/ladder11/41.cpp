#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    long long int time = 0;
    int a[m];
    cin >> a[0];
    time = a[0]-1;
    for(int i=1; i<m; i++) {
        cin >> a[i];
        if(a[i]-a[i-1] >= 0)
            time += a[i]-a[i-1];
        else 
            time += n - a[i-1] + a[i];
        // cout << time << endl;
    }
    cout << time << endl;
    return 0;
}