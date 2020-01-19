#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, curr_max=INT_MIN, max_index;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a;
        int temp = a/m + ((a%m==0) ? -1 : 0);
        if(temp >= curr_max) {
            curr_max = temp;
            max_index = i;
        } 
    }
    cout << max_index+1 << endl;
    return 0;
}