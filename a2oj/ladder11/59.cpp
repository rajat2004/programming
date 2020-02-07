#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[m], arr2[m];
    int count[1001]={0};
    int max_empty = INT_MIN;
    for(int i=0; i<m; i++) {
        cin >> arr[i];
        if (arr[i] > max_empty)
            max_empty = arr[i];
        // arr2[i] = arr[i];
        for(int j=arr[i]; j>=1; j--)
            count[j]++;
    }
    int min_money = 0, n1 = n;
    sort(arr, arr+m);

    int i = 0;
    while(n1 > 0) {
        if (i >= m) break;
        while(arr[i] > 0) {
            min_money += arr[i];
            n1--;
            arr[i]--;
            if (n1==0) break;
        }
        i++;
    }

    i = max_empty;
    int max_money = 0;
    while(n>0) {
        if (i==0) break;
        while(count[i]>0) {
            max_money += i;
            n--;
            count[i]--;
            if(n==0) break;
        }
        i--;
    }


    cout << max_money << " " << min_money << endl;
    return 0;
}
