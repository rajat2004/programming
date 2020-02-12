#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int num = arr[k-1];
    for(int i=k; i<n; i++) {
        if(arr[i]!=num) {
            cout << "-1" << endl;
            return 0;
        }
    }
    for(int i=k-2; i>=0; i--) {
        if(arr[i]!=num) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
