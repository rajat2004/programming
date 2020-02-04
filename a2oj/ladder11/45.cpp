#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n;
    int arr1[n];
    for(int i=0; i<n; i++)
        cin >> arr1[i];

    cin >> m;
    int arr2[m];
    for(int i=0; i<m; i++)
        cin >> arr2[i];

    int max_ratio=INT_MIN, count=0;
    
    for(int i=0; i<n; i++) {
        for(int j=m-1; j>=0; j--) {
            if(arr2[j] % arr1[i] == 0) {
                int quo = arr2[j]/arr1[i];
                if (quo > max_ratio) {
                    max_ratio = quo;
                    count = 1;
                } else if (quo == max_ratio)
                    count++;

                // cout << arr2[j] << " " << arr1[i] << endl;
                break;
            }
        }
    }

    cout << count << endl;
    // cout << max_ratio << endl;

    return 0;
}
