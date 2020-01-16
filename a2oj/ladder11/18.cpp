#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,a,min_score=INT_MAX,max_score=INT_MIN, count = -2;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a;
        if (a > max_score) {
            count += 1;
            max_score = a;
        }

        if (a < min_score) {
            count+=1;
            min_score = a;
        }
    }
    cout << count << endl;
    return 0;
}