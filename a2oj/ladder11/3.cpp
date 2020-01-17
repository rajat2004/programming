// http://codeforces.com/problemset/problem/266/B
#include <bits/stdc++.h>
using namespace std;

void swap(int a, int b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int n, t;
    cin >> n >> t;
    char q[n];
    cin >> q;
    while(t--) {
        for(int i=0; i<n;) {
            if (q[i]=='B' && q[i+1]=='G') {
                swap(q[i], q[i+1]);
                i+=1;
            }
            i+=1;
        }
    }
    cout << q << endl;
    return 0;
}