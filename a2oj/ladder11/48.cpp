#include<bits/stdc++.h>
using namespace std;

int main() {
    int k, arr[12];
    cin >> k;
    for(int i=0; i<12; i++)
        cin >> arr[i];

    sort(arr, arr+12);
    int tot = 0, count = 0;
    for(int i=11; i>=0; i--) {
        if (tot < k) {
            count += 1;
            tot += arr[i];
        } else {
            break;
        }
    }
    if (tot < k)
        cout << -1 << endl;
    else 
        cout << count << endl;
    return 0;
}
