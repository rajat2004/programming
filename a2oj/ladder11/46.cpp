#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);
    long long int tot = 0;
    for(int i=0; i<m; i++) {
        if (arr[i] <= 0)
            tot += arr[i];
        else 
            break;
    }

    cout << -1*tot << endl;
    return 0;
}
