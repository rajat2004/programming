#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int min_diff=INT_MAX, id1, id2;
    cin >> arr[0];
    for(int i=1; i<n; i++) {
        cin >> arr[i];
        int diff = abs(arr[i]-arr[i-1]);
        if(diff < min_diff) {
            min_diff = diff;
            id1 = i;
            id2 = i-1;
        }
    }
    int diff = abs(arr[n-1]-arr[0]);
    if(diff < min_diff) {
        min_diff = diff;
        id1 = n-1;
        id2 = 0;
    }
    cout << id1+1 << " " << id2+1 << endl;
    return 0;
}