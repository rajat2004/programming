#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[m];
    for(int i=0; i<m; i++)
        cin >> arr[i];

    sort(arr, arr+m);
    int min_diff = INT_MAX;
    for(int i=0; i<m; i++) {
        if(i+n-1 >= m) {
            cout << min_diff << endl;
            return 0;
        }
        int diff = arr[i+n-1] - arr[i];
        if (diff <= min_diff) {
            min_diff = diff;
        }
    }
    cout << min_diff << endl;
    return 0;
}
