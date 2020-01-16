#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, mini=INT_MAX, maxi=INT_MIN, min_pos, max_pos;
    cin >> n;
    // min_pos = n-1;
    // max_pos = 0;
    for(int i=0; i<n; i++) {
        cin >> a;
        if(a > maxi) {
            max_pos = i;
            maxi = a;
        }
            
        if(a <= mini) {
            min_pos = i;
            mini = a;
        }
    }
    // cout << max_pos << min_pos << endl;
    if(max_pos < min_pos)
        cout << (max_pos + n-1 -min_pos) << endl;
    else
        cout << (max_pos + n-1 -min_pos -1) << endl;
    
    return 0;
}