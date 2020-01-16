#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, curr=0, max_cap=INT_MIN;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        curr = curr - a + b;
        if (curr > max_cap)
            max_cap = curr;
    }
    cout << max_cap << endl;
    return 0;
}