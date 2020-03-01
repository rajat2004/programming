#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    long long unsigned min = 0, new_sum;
    
    for(int i=0; i<k; i++) {
        min+=a[i];
    }
    new_sum = min;
    int id = 0;
    for(int i=1; (i+k-1)<n; i++) {
        new_sum = new_sum + a[i+k-1] - a[i-1];
        if(new_sum<min) {
            min = new_sum;
            id = i;
        } 
    }
    cout << id+1 <<  endl;
    return 0;
}
